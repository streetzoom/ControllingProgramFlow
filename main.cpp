/*
    This challenge is about using a collection (list) of integers and allowing the user
    to select options from a menu to perform operations on the list.

    Your program should display a menu options to the user as follows:

    P - Print numbers
    A - Add a number
    M - Display mean of the numbers
    S - Display the smallest number
    L - Display the largest number
    Q - Quit

    Enter your choice:

The program should only accept valid choices from the user, both upper and lowercase selections should be allowed.
If an illegal choice is made, you should display, "Unknown selection, please try again" and the menu options should be
displayed again.

If the user enters 'P' or 'p', you should display all of the elements (ints) in the list.
If the list is empty you should display "[] - the list is empty"
If the list is not empty then all the list element should be displayed inside square brackets separated by a space.
For example, [ 1 2 3 4 5 ]

If the user enters 'A' or 'a' then you should prompt the user for an integer to add to the list
which you will add to the list and then display it was added. For example, if the user enters 5
You should display, "5 added".
Duplicate list entries are OK

If the user enters 'M' or 'm'  you should calculate the mean or average of the elements in the list and display it.
If the list is empty you should display, "Unable to calculate the mean - no data"

If the user enters 'S' or 's' you should display the smallest element in the list.
For example, if the list contains [2 4 5 1],  you should display, "The smallest number is 1"
If the list is empty you should display, "Unable to determine the smallest number - list is empty"

If the user enters 'L' or 'l' you should display the largest element in the list
For example, if the list contains [2 4 5 1], you should display, "The largest number is 5"
If the list is empty you should display, "Unable to determine the largest number - list is empty"

If the user enters 'Q' or 'q' then you should display "Goodbye" and the program should terminate.

Additional functionality if you wish to extend this program.
- search for a number in the list and if found display the number of times it occurs in the list
- clearing out the list (make it empty again) (Hint: the vector class has a .clear() method)
- don't allow duplicate entries
- come up with your own ideas!
*/
#include <iostream>
#include <vector>
#include <algorithm>

int main () {

    std::vector<int> user_data {};

    char user_choice {};
    do {
        doAgain: // goto label to repeat do loop if user decide to !quit
        std::cout << std::endl;
        std::cout << "\nP - Print numbers" << std::endl;
        std::cout << "A - Add a number" << std::endl;
        std::cout << "M - Display mean of the numbers" << std::endl;
        std::cout << "S - Display the smallest number" << std::endl;
        std::cout << "L - Display the largest number" << std::endl;
        std::cout << "Q - Quit" << std::endl;
        std::cout << "\nEnter your choice:";
        std::cin >> user_choice;

        switch (user_choice) {
            case 'P':
            case 'p':
                if (!user_data.empty()) {
                    std::cout << "[ ";
                    for (auto vec: user_data) {
                        std::cout << vec << " ";
                    }
                    std::cout << " ]";
                } else {
                    std::cout << "[] - the list is empty";
                }
                break;
            case 'A':
            case 'a':
            {
                int add_number {};
                std::cout << "Enter an integer to add to the list: " << std::endl;
                std::cin >> add_number;
                user_data.push_back(add_number);
                std::cout << add_number << " added";
                break;
            }
            case 'M':
            case 'm':
            {
                if (!user_data.empty()) {
                    double average_data {};
                    double total_data{};
                    for (auto vec: user_data) {
                        total_data += vec;
                        average_data = total_data / user_data.size();
                    }
                    std::cout << "The mean is: " << average_data;
                } else {
                    std::cout << "Unable to calculate the mean - no data";
                }
                break;
            }
            case 'S':
            case 's':
                if (!user_data.empty()) {
                    std::cout << "The smallest number is: "
                              << *std::min_element(user_data.begin(), user_data.end());
                } else {
                    std::cout << "Unable to determine the smallest number - list is empty";
                }
                break;
            case 'L':
            case 'l':
                if (!user_data.empty()) {
                    std::cout << "The largest element is: "
                              << *std::max_element(user_data.begin(), user_data.end());
                } else {
                    std::cout << "Unable to determine the largest number - list is empty";
                }
                break;
            case 'q':
            case 'Q':
            {
                char confirm {};
                bool done {false};
                confirmAgain: // goto label to repeat user illegal choice
                std::cout << "\nAre you sure (Y/N)?" << std::endl;
                std::cin >> confirm;
                while (!done) {
                    if (confirm == 'Y' || confirm =='y') {
                        std::cout << "\nGoodbye...";
                        done = true;
                    } else if (confirm == 'N' || confirm == 'n') {
                        goto doAgain; // repeat do loop
                    } else {
                        std::cout << "Illegal choice";
                        goto confirmAgain; // repeat confirm
                    }
                }
                break;
            }
            default:
                std::cout << "Unknown selection, please try again" << std::endl;
        }
    } while (user_choice != 'Q' && user_choice != 'q');

    return 0;
}