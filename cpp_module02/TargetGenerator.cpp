#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator()
{

}

TargetGenerator::~TargetGenerator()
{
    std::map<std::string, ATarget *>::iterator it = _targetBook.begin();
    while (it != _targetBook.end())
    {
        delete it->second;
        it++;
    }
    _targetBook.clear();
}

void TargetGenerator::learnTargetType(ATarget *target)
{
    if (target)
        _targetBook.insert(std::pair<std::string, ATarget *>(target->getType(), target->clone()));
}

void TargetGenerator::forgetTargetType(const std::string &targetName)
{
    std::map<std::string, ATarget *>::iterator it = _targetBook.find(targetName);
    if (it != _targetBook.end())
        delete (it->second);
    _targetBook.erase(targetName);
}

ATarget *TargetGenerator::createTarget(const std::string &targetName)
{
    ATarget *target = NULL;

    std::map<std::string, ATarget *>::iterator it = _targetBook.find(targetName);
    if (it != _targetBook.end())
        target = _targetBook[targetName];
    return (target);
}