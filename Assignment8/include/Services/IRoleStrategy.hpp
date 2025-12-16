#pragma once

class IRoleStrategy {
    public:
        /*
        @brief Determines whether this role is allowed to add employees.
        @return True if the role can add employees, false otherwise.
        */
        virtual bool canAddEmployee() const = 0;

        /*
        @brief Determines whether this role is allowed to remove employees.
        @return True if the role can add employees, false otherwise.
        */
        virtual bool canRemoveEmployee() const = 0;

        /*
        @brief Determines whether this role is allowed to update position of an employees.
        @return True if the role can add employees, false otherwise.
        */
        virtual bool canUpdatePosition() const = 0;

        /*
        @brief Determines whether this role is allowed to update salary of an employees.
        @return True if the role can add employees, false otherwise.
        */
        virtual bool canUpdateSalary() const = 0;

        /*
        @brief Determines whether this role is allowed to view salary of an employees.
        @return True if the role can add employees, false otherwise.
        */
        virtual bool canViewSalary() const = 0;

        /*
        @brief Determines whether this role is allowed to view hardware count of an employees.
        @return True if the role can add employees, false otherwise.
        */
        virtual bool canViewHardwareCount() const = 0;

        /*
        @brief Determines whether this role is allowed to update hardware count of an employees.
        @return True if the role can add employees, false otherwise.
        */
        virtual bool canUpdateHardwareCount() const = 0;

        /*
        @brief Virtual destructor for the IRoleStrategy interface.
        */
        virtual ~IRoleStrategy() = default;
};