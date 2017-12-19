#ifndef GENERICBTN_HPP
#define GENERICBTN_HPP

#include <Clickable.hpp>
#include <ClickManager.hpp>

class GenericBtn : public Clickable {

public:

    using Clickable::Clickable;

    ClickManager* clickMgrPtr;

    GenericBtn();
    //Constructer for giving a text label to the object. Useful for buttons
    GenericBtn(ObjectManager* objectMgrPtr, std::string labelText);
    GenericBtn(ClickManager* clickMgrPtr);
    GenericBtn(ClickManager* clickMgrPtr,std::string actionIDIn);
    ~GenericBtn();


    virtual void isClicked(bool toggleClick);
    virtual void setHovered(bool setHovered);

    virtual std::string getActionID();
    virtual void setActionID(std::string actionIDIn);

//    virtual void setHoverValue(sf::IntRect hoverValIn);
//    virtual void setDefaultPos(sf::IntRect defaultValIn);

    std::string actionID;



protected:

private:


};


#endif
