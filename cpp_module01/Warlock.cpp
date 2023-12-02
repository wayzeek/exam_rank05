#include "Warlock.hpp"

Warlock::Warlock(const std::string &name, const std::string &title) : _name(name), _title(title)
{
    std::cout << getName() << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
    std::cout << getName() << ": My job here is done!" << std::endl;

    std::map<std::string, ASpell *>::iterator it = _spellBook.begin();
    while (it != _spellBook.end())
    {
        delete it->second;
        it++;
    }
    _spellBook.clear();
}

const std::string &Warlock::getName() const
{
    return (_name);
}

const std::string &Warlock::getTitle() const
{
    return (_title);
}

void Warlock::setTitle(const std::string &title)
{
    _title = title;
}

void Warlock::introduce() const
{
    std::cout << getName() << ": I am " << getName() << ", " << getTitle() << "!" << std::endl;
}

void Warlock::learnSpell(ASpell * spell)
{
    if (spell)
        _spellBook.insert(std::pair<std::string, ASpell *>(spell->getName(), spell->clone()));
}

 void Warlock::forgetSpell(std::string spellName)
 {
    std::map<std::string, ASpell *>::iterator it = _spellBook.find(spellName);
    if (it != _spellBook.end())
        delete (it->second);
    _spellBook.erase(spellName);
 }

void Warlock::launchSpell(std::string spellName, const ATarget &target)
{
    std::map<std::string, ASpell *>::iterator it = _spellBook.find(spellName);
    if (it != _spellBook.end())
        target.getHitBySpell(*it->second);
}
