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
    testObject.addSprite(textureMgr.getTexture("ranged"),("test"));
    renderMgr.addMultiObjects(testObject.getAllSprites());



    //Main frame loop
    while (mainWindow.isOpen()){

        sf::Event event;
        while (mainWindow.pollEvent(event)){
                if(event.type == sf::Event::Closed){
                    mainWindow.close();
                }

        }
        mainWindow.clear();

       // mainWindow.draw(testSprite);
        renderMgr.render(mainWindow);

        mainWindow.display();
    }

    return 0;
}
