/* This class serves as a master class for a 'Clickable' which creates multiple 'GenericBtn's
when clicked.

CURRENTLY only functions for a specific size button and strict hover/click behaviours. (e.g. returning an actionID string)
*/

#ifndef DROPDOWNMENU_H
#define DROPDOWNMENU_H

#include <Clickable.hpp>
#include <buttons/GenericBtn.hpp>
#include <ClickManager.hpp>
class GenericBtn;


class DropDownMenu : public Clickable {
    public:
        DropDownMenu();
        //Passes pointers to the object. Required for most member functions to work
        DropDownMenu(ObjectManager* objectMgrPtr, ClickManager* clickMgrPtr);
        virtual ~DropDownMenu();

        //Adds and a button to the menu using an existing buttonAssetID
        virtual void addBtn(std::string buttonID, std::string labelIn,std::string actionIDIn);
        //Adds and a button to the menu and sets the buttonAssetID
        virtual void addBtn(std::string buttonID, std::string labelIn,std::string buttonAssetID,std::string actionIDIn);
        //Positions the buttons in descending order vertically down
        virtual void positionButtons();

        virtual void isClicked(bool toggleClick);
        virtual void setHovered(bool setHovered);

        std::string buttonAssetID; //String used to load the texture of the buttons
        std::list<GenericBtn> buttons; //List of genericBtns

        ObjectManager* objectMgrPtr;
        ClickManager* clickMgrPtr;
        bool hasNestedClickable = true;



    protected:

    private:
};

#endif // DROPDOWNMENU_H
