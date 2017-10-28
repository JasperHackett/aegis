#include "header.hpp"




int main(){
    resHeight = 1600;
    resWidth = 900;
    fullscreen = false;
    sf::RenderWindow mainWindow(sf::VideoMode(resHeight, resWidth), "Aegis", sf::Style::Close);

    textureMgr.loadTexture("melee","assets/meleechar.png");
    textureMgr.loadTexture("ranged","assets/rangedchar.png");

    RenderObject testObject;
    testObject.addSprite(textureMgr.getTexture("melee"),"body");
    testObject.setSpritePosition("body",50,50);
    //testObject.addSprite(textureMgr.getTexture("ranged"),("test"));
    testObject.setPos(sf::IntRect(50,50,50,50));
    testObject.setSpriteMap(renderMgr.addMultiObjects(testObject.getSpriteMap()));
    testObject.setSpritePosition("body",200,200);
    testObject.updateSprite("body",&renderMgr);

    ClickManager mainClickManager;
    mainClickManager.addObject(&testObject);



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
        mainClickManager.checkHover(mousePos);
       // mainWindow.draw(testSprite);
        renderMgr.render(mainWindow);

        mainWindow.display();
    }

    return 0;
}

