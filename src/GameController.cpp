#include <GameController.hpp>
#include <iostream>
GameController::GameController(){
}

GameController::GameController(ObjectManager* objectMgrPtr, TextLog* mainEventLog, sf::RenderWindow* mainWindow){
    this->objectMgrPtr = objectMgrPtr;
    this->mainTextLog = mainEventLog;
    this->mainWindow = mainWindow;

}

GameController::~GameController()
{
    //dtor
}

GameController* GameController::startGame(ClickManager *clickMgrPtr){
    this->clickMgrPtr = clickMgrPtr;

    topMenuBar.addSprite(objectMgrPtr->getTexture("topbar"),"topbar");
    topMenuBar.setPos(sf::IntRect(0,0,1600,20));
    topMenuBar.setSpritePosition("topbar",0,0);
    topMenuBar.setTextureRect("topbar",sf::IntRect(0,0,1600,20));
    objectMgrPtr->addVisible(&topMenuBar);

    DropDownMenu controlMenu(objectMgrPtr,clickMgrPtr);
    controlMenu.addSprite(objectMgrPtr->getTexture("menubtn"),"primary");
    controlMenu.setDefaultPos(sf::IntRect(60,0,60,20));
    controlMenu.setTextureRect("primary",sf::IntRect(60,0,60,20));
    controlMenu.setHoverValue(sf::IntRect(0,0,60,20));
    controlMenu.setClickedPos(sf::IntRect(0,20,60,20));
    controlMenu.addBtn("dropdownbtn","","dropdownbtn","");
    controlMenu.addBtn("dropdownbtn","Resolution","dropdownbtn","options");
    controlMenu.addBtn("dropdownbtn","Fullscreen","dropdownbtn","fullscreen");
    controlMenu.addBtn("dropdownbtn","Exit game","dropdownbtn","exit");
    controlMenu.setPos(sf::IntRect(0,0,60,20));
    gameMenuDropdowns.push_back(controlMenu);

    objectMgrPtr->addVisible(&gameMenuDropdowns.back());
    clickMgrPtr->addObject(&gameMenuDropdowns.back());
    return this;
}


void GameController::applyOptions(std::list<std::string> optionChangeList){
    std::string keyWord;
    std::string argument;
    std::stringstream convert;

    for(std::string optionCommand : optionChangeList){
        keyWord.clear();
        int i = 0;
        if(optionCommand.size() > 0){
            if(optionCommand.compare(0,0,"#")!= 0){
                int breakPos = optionCommand.find_first_of(":");
                while(i < breakPos){
                    keyWord.push_back(optionCommand[i]);
                    i++;
                }
                i++;
                if(keyWord == "resolution"){
                    float resWidth;
                    float resHeight;
                    breakPos = optionCommand.find_first_of(",");
                    while(i < breakPos){
                        argument.push_back(optionCommand[i]);
                        i++;
                    }
                    convert.str(argument);
                    convert >> resWidth;
                    convert.clear();
                    argument.clear();
                    i++;
                    while(i < optionCommand.size()){
                        argument.push_back(optionCommand[i]);
                        i++;
                    }
                    convert.str(argument);
                    convert >> resHeight;
                    convert.clear();
                    argument.clear();
                    changeResolution(resWidth,resHeight);
                }else if(keyWord == "fullscreen"){
                    bool fullscreen;
                    if(optionCommand.compare(i,i,"1") == 0){
                        fullscreen = true;
                    }else if(optionCommand.compare(i,i,"0")== 0){
                        fullscreen = false;
                    }
                    setFullscreen(fullscreen);
                }
            }
        }
    }
}

void GameController::changeResolution(float widthIn, float heightIn){
    this->mainWindow->setSize(sf::Vector2u(widthIn,heightIn));
}

void GameController::setFullscreen(bool fullscreen){
    if(fullscreen){
        mainWindow->create(sf::VideoMode(mainWindow->getSize().x, mainWindow->getSize().y), "Aegis", sf::Style::Fullscreen);
    }else{
        mainWindow->create(sf::VideoMode(mainWindow->getSize().x, mainWindow->getSize().y), "Aegis", sf::Style::Close);
    }
}

void GameController::optionsMenu(bool enableMenu, ClickManager* clickMgrPtr){
    this->clickMgrPtr = clickMgrPtr;

    if(optionMenuButtons.empty()){
        //Create options menu assets (this could be reorganized)
        optionsMenuBackground.addSprite(objectMgrPtr->getTexture("optionsmenu_background"),"optionsMenuBackground");
        optionsMenuBackground.setSpritePosition("optionsMenuBackground",300,300);

        GenericBtn applyOptionsBtn(clickMgrPtr,"applyOptions");
        applyOptionsBtn.addSprite(objectMgrPtr->getTexture("abilityBtn"),"button");
        applyOptionsBtn.setSpritePosition("button",650,650);
        applyOptionsBtn.setTextureRect("button",sf::IntRect(0,0,122,32));
        applyOptionsBtn.setPos(sf::IntRect(650,650,122,32));
        applyOptionsBtn.setDefaultPos(sf::IntRect(0,0,122,32));
        applyOptionsBtn.setHoverValue(sf::IntRect(122,0,122,32));
        applyOptionsBtn.addText(objectMgrPtr->getFont("trebuc"),"labelText","Apply",sf::Color::Black,16);
        applyOptionsBtn.setTextPosition("labelText",applyOptionsBtn.getPos().left +30,applyOptionsBtn.getPos().top +5);
        optionMenuButtons.push_back(applyOptionsBtn);

        GenericBtn closeOptionsBtn(clickMgrPtr,"closeOptions");
        closeOptionsBtn.addSprite(objectMgrPtr->getTexture("abilityBtn"),"button");
        closeOptionsBtn.setSpritePosition("button",800,650);
        closeOptionsBtn.setTextureRect("button",sf::IntRect(0,0,122,32));
        closeOptionsBtn.setPos(sf::IntRect(800,650,122,32));
        closeOptionsBtn.setDefaultPos(sf::IntRect(0,0,122,32));
        closeOptionsBtn.setHoverValue(sf::IntRect(122,0,122,32));
        closeOptionsBtn.addText(objectMgrPtr->getFont("trebuc"),"labelText","Close",sf::Color::Black,16);
        closeOptionsBtn.setTextPosition("labelText",closeOptionsBtn.getPos().left +30,closeOptionsBtn.getPos().top +5);
        optionMenuButtons.push_back(closeOptionsBtn);

        GenericBtn fullscreenBtn(clickMgrPtr,"fullscreen");
        fullscreenBtn.addSprite(objectMgrPtr->getTexture("abilityBtn"),"button");
        fullscreenBtn.setSpritePosition("button",350,350);
        fullscreenBtn.setTextureRect("button",sf::IntRect(0,0,122,32));
        fullscreenBtn.setPos(sf::IntRect(350,350,122,32));
        fullscreenBtn.setDefaultPos(sf::IntRect(0,0,122,32));
        fullscreenBtn.setHoverValue(sf::IntRect(122,0,122,32));
        fullscreenBtn.addText(objectMgrPtr->getFont("trebuc"),"labelText","Fullscreen",sf::Color::Black,16);
        fullscreenBtn.setTextPosition("labelText",fullscreenBtn.getPos().left +30,fullscreenBtn.getPos().top +5);
        optionMenuButtons.push_back(fullscreenBtn);


        GenericBtn resolutionBtn(clickMgrPtr,"resolution");
        resolutionBtn.addSprite(objectMgrPtr->getTexture("abilityBtn"),"button");
        resolutionBtn.setSpritePosition("button",350,400);
        resolutionBtn.setTextureRect("button",sf::IntRect(0,0,122,32));
        resolutionBtn.setPos(sf::IntRect(350,400,122,32));
        resolutionBtn.setDefaultPos(sf::IntRect(0,0,122,32));
        resolutionBtn.setHoverValue(sf::IntRect(122,0,122,32));
        resolutionBtn.addText(objectMgrPtr->getFont("trebuc"),"labelText","Resolution",sf::Color::Black,16);
        resolutionBtn.setTextPosition("labelText",resolutionBtn.getPos().left +30,resolutionBtn.getPos().top +5);
        optionMenuButtons.push_back(resolutionBtn);
    }
    std::list<GenericBtn>::iterator iter;
    if(enableMenu){
        objectMgrPtr->addVisible(&optionsMenuBackground);

        for(iter = optionMenuButtons.begin(); iter != optionMenuButtons.end(); ++iter){
            objectMgrPtr->addVisible(&(*iter));
            clickMgrPtr->addObject(&(*iter));
        }

    }else{
        optionsMenuBackground.rendered = false;
        for(iter = optionMenuButtons.begin(); iter != optionMenuButtons.end(); ++iter){
            iter->hoverable = false;
            iter->rendered = false;
            clickMgrPtr->removeObject(&(*iter));
            objectMgrPtr->removeObjects();
        }

    }


}
