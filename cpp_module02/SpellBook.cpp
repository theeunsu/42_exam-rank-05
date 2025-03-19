#include "SpellBook.hpp"


SpellBook::SpellBook()
{
}

SpellBook::~SpellBook()
{
	for (std::map<std::string, ASpell*>::iterator it = _spellBook.begin(); it != _spellBook.end(); ++it)
		delete it->second;
	_spellBook.clear();
}

void SpellBook::learnSpell(ASpell* spell)
{
	if(spell)
		_spellBook[spell->getName()] = spell->clone();
}

void SpellBook::forgetSpell(std::string const &spellName)
{
	std::map<std::string, ASpell *>::iterator it = _spellBook.find(spellName);
	if (it != _spellBook.end())
	{
		delete it->second;
		_spellBook.erase(it);
	}
}

ASpell* SpellBook::createSpell(std::string const &spellName)
{
	std::map<std::string, ASpell *>::iterator it = _spellBook.find(spellName);
	if (it != _spellBook.end())
		return it->second; // another version: return _spellBook[spellName];
	return NULL;
}
