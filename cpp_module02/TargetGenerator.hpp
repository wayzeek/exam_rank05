#pragma once

#include <map>
#include <algorithm>

#include "ATarget.hpp"

class ATarget;

class TargetGenerator
{
    public :
        TargetGenerator();
        ~TargetGenerator();

        void learnTargetType(ATarget *target);
        void forgetTargetType(const std::string &targetName);
        ATarget *createTarget(const std::string &targetName);
        
    private :
        std::map<std::string, ATarget *> _targetBook;
} ;