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
    mainEventLog.setFieldWidth(600);
    mainEventLog.setFont(objectMgr.getFont("trebuc"));
    mainEventLog.setNewLinePos(sf::Vector2f(350,850));
    objectMgr.addVisible(&mainEventLog);

    //Loading textures from files into class ObjectManager
    objectMgr.loadTexture("startBtn","assets/startbtn.png");
    objectMgr.loadTexture("exitBtn","assets/exitbtn.png");
    objectMgr.loadTexture("ranged","assets/rangedchar.png");
    objectMgr.loadTexture("abilityBtn","assets/abilitybutton.png");
    objectMgr.loadTexture("meleeUnit","assets/meleechar1.png");
    objectMgr.loadTexture("frog","assets/frog.png");
    objectMgr.loadTexture("bluering","assets/bluering.png");
    objectMgr.loadTexture("background","assets/Stagetest.png");
    objectMgr.loadTexture("rings","assets/coloured_rings.png");
    objectMgr.loadTexture("healthbar","assets/health_fill.png");
    objectMgr.loadTexture("healthoutline","assets/health_outline.png");

/*TESTING CODE*/



    RenderObject background;
    background.addSprite(objectMgr.getTexture("background"),"background");


    GenericBtn exitBtn(&clickMgr,"exit");
    exitBtn.addSprite(objectMgr.getTexture("exitBtn"),"button");
    exitBtn.setSpritePosition("button",50,830);
    exitBtn.setTextureRect("button",sf::IntRect(0,0,120,40));
    exitBtn.setPos(sf::IntRect(50,830,120,40));
    exitBtn.setMainTextLog(&mainEventLog);
    exitBtn.setDefaultPos(sf::IntRect(0,0,120,40));
    exitBtn.setHoverValue(sf::IntRect(120,0,120,40));



    GenericBtn startBtn(&clickMgr,"start");
    startBtn.addSprite(objectMgr.getTexture("startBtn"),"button");
    startBtn.setSpritePosition("button",50,750);
    startBtn.setTextureRect("button",sf::IntRect(0,0,156,40));
    startBtn.setPos(sf::IntRect(50,750,156,40));
    startBtn.setMainTextLog(&mainEventLog);
    startBtn.setDefaultPos(sf::IntRect(0,0,156,40));
    startBtn.setHoverValue(sf::IntRect(156,0,156,40));


    objectMgr.addVisible(&startBtn);
    objectMgr.addVisible(&exitBtn);

    clickMgr.setWindowPtr(&mainWindow);
    clickMgr.addObject(&startBtn);
    clickMgr.addObject(&exitBtn);





/*END TESTING CODE*/

    gameStates existingGameState = menu;
    //Main frame loop
    while (mainWindow.isOpen()){

        //CHECK IF GAME STATE HAS CHANGED - GameStates: {menu,playing,options,exiting}
        if(clickMgr.currentGameState != existingGameState){
            switch(clickMgr.currentGameState){
            //Change game state
            case(menu) :
                if(startBtn.rendered == false){
                    objectMgr.addVisible(&exitBtn);
                    objectMgr.addVisible(&startBtn);
                }
                if(startBtn.hovered == false){
                    clickMgr.addObject(&exitBtn);
                    clickMgr.addObject(&startBtn);

                }
                break;
            case(playing) :
                mainEventLog.addText("Game starting...");
                objectMgr.addVisible(&background,false);
                startBtn.rendered = false;
                startBtn.hoverable = false;
                exitBtn.rendered = false;
                exitBtn.hoverable = false;
                objectMgr.removeObjects();
                clickMgr.removeObject(&startBtn);
                clickMgr.removeObject(&exitBtn);
                break;
            case(options) :

                break;
            case(exiting):
                break;

            default :
                 break;


            }
            existingGameState = clickMgr.currentGameState;
        }

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

