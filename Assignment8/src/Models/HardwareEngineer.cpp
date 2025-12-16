#include "Models/HardwareEngineer.hpp"

/*
@brief Gets the hardware units count of the employee.
@return Hardware units count of the employee.
*/
int HardwareEngineer::GetHardwareCount() const {
    return hardwareCount_;
}

/*
@brief Sets the hardware count for the employee.
@param hardwareCount The new hardware count to assign to the employee.
*/
void HardwareEngineer::SetHardwareCount(int hardwareCount) {
    hardwareCount_ = hardwareCount;
}