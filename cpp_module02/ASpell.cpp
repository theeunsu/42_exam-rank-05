#include "ASpell.hpp"

ASpell::ASpell(std::string name, std::string effects) : _name(name), _effects(effects)
{

}

ASpell::~ASpell()
{

}


std::string ASpell::getName() const
{
	return _name;
}

std::string ASpell::getEffects() const
{
	return _effects;
}


void ASpell::launch(const ATarget &target) const
{
	target.getHitBySpell(*this);
}
