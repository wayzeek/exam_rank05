#include "Warlock.hpp"

Warlock::Warlock(const std::string &name, const std::string &title) : _name(name), _title(title)
{
    std::cout << getName() << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
    std::cout << getName() << ": My job here is done!" << std::endl;
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
    _spellBook.learnSpell(spell);
}

 void Warlock::forgetSpell(std::string spellName)
 {
   _spellBook.forgetSpell(spellName);
 }

void Warlock::launchSpell(std::string spellName, const ATarget &target)
{
    ASpell *spell = _spellBook.createSpell(spellName);
    if (spell)
        target.getHitBySpell(*spell);
}
