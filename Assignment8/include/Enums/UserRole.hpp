#pragma once

#include<ostream>

/*@brief Represents the different roles that a user can have in the system.*/
enum class UserRole {
    ManagementStaff,
    HardwareEngineer,
    SoftwareEngineer,
};

/*
@brief Outputs the string representation of a UserRole to the given stream.
@param out The output stream to which the role string will be written.
@param role The UserRole value to convert to a string.
@return A reference to the output stream after writing the role.
*/
inline std::ostream& operator<< (std::ostream& out, UserRole role) {
    switch (role)
    {
        case UserRole::ManagementStaff:
            out << "Management Staff";
            break;
        case UserRole::HardwareEngineer:
            out << "Hardware Engineer";
            break;
        case UserRole::SoftwareEngineer:
            out << "Software Engineer";
            break;
        default:
            out << "None";
            break;
    }
    return out;
} 