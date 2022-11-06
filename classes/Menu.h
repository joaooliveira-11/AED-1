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

        ///@brief Use of map to change a class' UcCode to its corresponding name.
        ///@returns The corresponding UC's name given an UCcode
        ///@param uccode The UC's code.
        ///@note Time complexity: O(1)
        static string UcCodeToName1(const string &uccode);

        ///@brief Converts hour from float to time.
        ///@returns An hour converted from float to time.
        ///@param time The hour we want to convert.
        ///@note Time complexity: O(1)
        static string Double_to_hour1(double time);
};

#endif
