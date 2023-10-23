#pragma once

#include "ATarget.hpp"
#include <map>

class TargetGenerator
{
    public:
        TargetGenerator();
        ~TargetGenerator();

        void learnTargetType(ATarget *target_ptr);
        void forgetTargetType(std::string const &name);
        ATarget* createTarget(std::string const &name);

    private:
        std::map<std::string, ATarget *> arr_target;
};