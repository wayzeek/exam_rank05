#include "SpellBook.hpp"

SpellBook::SpellBook()
{

}

SpellBook::~SpellBook()
{
    std::map<std::string, ASpell *>::iterator it = _spellBook.begin();
    while (it != _spellBook.end())
    {
        delete it->second;
        it++;
    }
    _spellBook.clear();
}

void SpellBook::learnSpell(ASpell *spell)
{
    if (spell)
        _spellBook.insert(std::pair<std::string, ASpell *>(spell->getName(), spell->clone()));
}

void SpellBook::forgetSpell(const std::string &spellName)
{
    std::map<std::string, ASpell *>::iterator it = _spellBook.find(spellName);
    if (it != _spellBook.end())
        delete (it->second);
    _spellBook.erase(spellName);
}

ASpell *SpellBook::createSpell(const std::string &spellName)
{
    ASpell *spell = NULL;

    std::map<std::string, ASpell *>::iterator it = _spellBook.find(spellName);
    if (it != _spellBook.end())
        spell = _spellBook[spellName];
    return (spell);
}