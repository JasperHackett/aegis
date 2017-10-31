#include "header.hpp"



int main(){
    resHeight = 1600;
    resWidth = 900;
    fullscreen = false;
    sf::RenderWindow mainWindow(sf::VideoMode(resHeight, resWidth), "Aegis", sf::Style::Close);


//TESTING CODE
    textureMgr.loadTexture("melee","assets/meleechar.png");
    textureMgr.loadTexture("ranged","assets/rangedchar.png");
    textureMgr.loadFont("trebuc","assets/trebuc.ttf");

    RenderObject testObject;
    testObject.addSprite(textureMgr.getTexture("melee"),"body");
    testObject.setSpritePosition("body",50,50);
    //testObject.addSprite(textureMgr.getTexture("ranged"),("test"));
    testObject.setPos(sf::IntRect(50,50,50,50));


    renderMgr.addObject(&testObject);
    testObject.setSpritePosition("body",200,200);

    testObject.assignHoverFunction(simpleSpriteChange);


    clickMgr.addObject(&testObject);

    //Text test

    TextLogEntry testTextObject;
    testTextObject.setFieldWidth(60);
    testTextObject.setFont(textureMgr.getFont("trebuc"));
    testTextObject.addText("test test test test test test tes tes tes");
    renderMgr.addObject(&testTextObject);



//END TESTING CODE




    //Main frame loop
    while (mainWindow.isOpen()){

        mousePos = sf::Mouse::getPosition(mainWindow);
        sf::Event event;

        while (mainWindow.pollEvent(event)){
                if(event.type == sf::Event::Closed){
                    mainWindow.close();
                }

        }
        mainWindow.clear();
        clickMgr.checkHover(mousePos);
       // mainWindow.draw(testSprite);
        renderMgr.render(mainWindow);
        testTextObject.draw(mainWindow);
        mainWindow.display();
    }

    return 0;
}

