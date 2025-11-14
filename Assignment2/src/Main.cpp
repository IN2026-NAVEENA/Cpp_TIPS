#include "StudentManager.hpp"
#include "UiUtility.hpp"

/// @brief Entry point of the program.
int main()
{
    StudentManager studentManager;
    UiUtility uiUtility(studentManager);
    uiUtility.Run();
    return 0;
}