#ifndef ABILITYBUTTON_HPP
#define ABILITYBUTTON_HPP

#include <Clickable.hpp>
#include <TextLog.hpp>

class AbilityButton : public Clickable
{
    public:
        AbilityButton();
        AbilityButton(std::string actionID, ObjectManager* objectManagerPtr,std::string btnLabel);
        virtual ~AbilityButton();


        TextLog btnLabel = {5};
        virtual void setHovered(bool setHovered);

        virtual std::string returnID();


        //This is a unique identifier for the buttons action e.g. (atk_generic);
        std::string actionID;

        virtual void isClicked(bool toggleClick);

        ObjectManager* objectMgrPtr;

    protected:

    private:

};

#endif // ABILITYBUTTON_HPP
