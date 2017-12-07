#include <header.hpp>


/* TO DO
    - Click on unit and then click on action
    - Action Buttons with text



*/



int main(){
    resHeight = 1600;
    resWidth = 900;
    fullscreen = false;
    sf::RenderWindow mainWindow(sf::VideoMode(resHeight, resWidth), "Aegis", sf::Style::Close);

    //Loading fonts
    objectMgr.loadFont("trebuc","assets/trebuc.ttf");

    //Message log initialisation
    mainEventLog.setFieldWidth(400);
    mainEventLog.setFont(objectMgr.getFont("trebuc"));
    mainEventLog.setNewLinePos(sf::Vector2f(350,850));
    objectMgr.addVisible(&mainEventLog);


//TESTING CODE
    objectMgr.loadTexture("startBtn","assets/startbtn.png");
    objectMgr.loadTexture("ranged","assets/rangedchar.png");
    objectMgr.loadTexture("abilityBtn","assets/abilitybutton.png");


    StartBtn startBtn;
    startBtn.addSprite(objectMgr.getTexture("startBtn"),"button");
    startBtn.setSpritePosition("button",50,750);
    startBtn.setTextureRect("button",sf::IntRect(0,0,156,40));
    startBtn.setPos(sf::IntRect(50,750,156,40));
    startBtn.setMainTextLog(&mainEventLog);

    Unit meleeChar(&objectMgr, &clickMgr);
    meleeChar.addSprite(objectMgr.getTexture("ranged"),"body");
    meleeChar.setSpritePosition("body",700,450);
    meleeChar.setPos(sf::IntRect(700,450,20,20));
    meleeChar.setMainTextLog(&mainEventLog);
    //meleeChar.addSprite(objectMgr.getTexture("abilityBtn"),"abilityBtn");
    meleeChar.addMove(attack);
    meleeChar.addMove(attack);
    meleeChar.positionActions();



    objectMgr.addVisible(&startBtn);
    objectMgr.addVisible(&meleeChar);

    clickMgr.addObject(&startBtn);
    clickMgr.addObject(&meleeChar);
    clickMgr.addObject(&meleeChar.attackButton);




//END TESTING CODE




    //Main frame loop
    while (mainWindow.isOpen()){

        mousePos = sf::Mouse::getPosition(mainWindow);
        clickMgr.checkHover(mousePos);

        sf::Event event;
        while (mainWindow.pollEvent(event)){

            switch(event.type){

                case sf::Event::MouseButtonPressed :
                    if(event.mouseButton.button == sf::Mouse::Left){
                        clickMgr.leftMouseClick(true);
                    }
                    break;

                case sf::Event::MouseButtonReleased :
                    if(event.mouseButton.button == sf::Mouse::Left){
                        clickMgr.leftMouseClick(false);
                    }
                    break;

                case sf::Event::Closed :
                    mainWindow.close();
                    break;

                default :
                    break;
            }



        }
        mainWindow.clear();
        objectMgr.render(mainWindow);
        mainWindow.display();
    }
}

