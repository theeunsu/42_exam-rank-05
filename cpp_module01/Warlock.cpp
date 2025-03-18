#include "Warlock.hpp"

Warlock::Warlock(const std::string &name, const std::string &title): _name(name), _title(title)
{
	std::cout << _name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
	std::cout << _name << ": My job here is done!" << std::endl;
	for (std::map<std::string, ASpell *>::iterator it = _spellBook.begin() ; it != _spellBook.end() ; ++it)
		delete it->second;
	_spellBook.clear();
}

const std::string &Warlock::getName() const
{
	return _name;
}

const std::string &Warlock::getTitle() const
{
	return _title;
}

void Warlock::setTitle(const std::string &title)
{
	_title = title;
}

void Warlock::introduce() const
{
	std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl;
}


void Warlock::learnSpell(ASpell *spell)
{
	if (spell)
		_spellBook[spell->getName()] = spell->clone();
}

void Warlock::forgetSpell(std::string spellName)
{
	std::map<std::string, ASpell *>::iterator it = _spellBook.find(spellName);
	if (it != _spellBook.end())
	{
		delete it->second;
		_spellBook.erase(it);
	}
}

void Warlock::launchSpell(std::string spellName, ATarget &target)
{
	std::map<std::string, ASpell*>::iterator it = _spellBook.find(spellName);
	if (it != _spellBook.end())
		_spellBook[spellName]->launch(target);

}
