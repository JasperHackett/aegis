#ifndef DROPDOWNMENU_H
#define DROPDOWNMENU_H

#include <Clickable.hpp>
#include <buttons/GenericBtn.hpp>
#include <ClickManager.hpp>
class GenericBtn;


class DropDownMenu : public Clickable {
    public:
        DropDownMenu();
        DropDownMenu(ObjectManager* objectMgrPtr, ClickManager* clickMgrPtr);
        virtual ~DropDownMenu();

        virtual void addBtn(std::string buttonID, std::string labelIn,std::string actionIDIn);
        virtual void addBtn(std::string buttonID, std::string labelIn,std::string buttonAssetID,std::string actionIDIn);

        virtual void positionButtons();
        virtual void isClicked(bool toggleClick);
        virtual void setHovered(bool setHovered);

        std::string buttonAssetID; //String used to load the texture of the buttons
        std::list<GenericBtn> buttons;

        ObjectManager* objectMgrPtr;
        ClickManager* clickMgrPtr;
        bool hasNestedClickable = true;



    protected:

    private:
};

#endif // DROPDOWNMENU_H
