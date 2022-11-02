///@file Menu.h

#include <string>
using namespace std;

#ifndef AED_1_MENU_H
#define AED_1_MENU_H

///@brief A class for the staring menu.
class Menu {
    public:
        ///@brief Runs the interactive user menu.
        static void readmenu();

        static string UcCodeToName1(const string &uccode);

        static string Double_to_hour1(double time);
};

#endif
