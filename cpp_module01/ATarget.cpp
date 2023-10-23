#include "ATarget.hpp"

ATarget::ATarget(std::string const &type) : type(type)
{
}

ATarget::~ATarget()
{
}

std::string const &ATarget::getType() const
{
    return (this->type);
}

void ATarget::getHitBySpell(ASpell const &aspell_ref) const
{
    std::cout << this->type << " has been " << aspell_ref.getEffects() << "!\n";
}
