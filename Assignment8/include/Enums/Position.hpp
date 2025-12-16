#pragma once

#include<ostream>

/*@brief Represents the different job positions available for employees.*/
enum class Position {
    Junior,
    Senior,
    Lead,
};

/*
@brief Outputs the string representation of a Position to the given stream.
@param out The output stream to which the position string will be written.
@param position The Position value to convert to a string.
@return A reference to the output stream after writing the position.
*/
inline std::ostream& operator<< (std::ostream& out, Position position) {
    switch(position) {
        case Position::Junior:
            out << "Junior";
            break;
        case Position::Senior:
            out << "Senior";
            break;
        case Position::Lead:
            out << "Lead";
            break;
        default:
            out << "None";
            break;
    }
    return out;
}