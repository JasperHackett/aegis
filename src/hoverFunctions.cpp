
#include <iostream>
#include <hoverFunctions.hpp>

void simpleSpriteChange(RenderObject* callingObject,bool isHovered){
    if(isHovered == true){
        std::cout << "hovered" << std::endl;
        callingObject->setSpritePosition("body",25,25);
    }else{
        std::cout << "not hovered" << std::endl;
        callingObject->setSpritePosition("body",50,50);
    }
}


