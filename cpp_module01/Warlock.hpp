#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include <map>
#include "ASpell.hpp"

class Warlock
{
	private:
		std::string _name;
		std::string _title;

		Warlock();
		Warlock(const Warlock &other);
		Warlock &operator=(const Warlock &other);

		std::map<std::string, ASpell *> _spellBook;
		

	public:
		Warlock(const std::string &name, const std::string &title);
		~Warlock();

		const std::string &getName() const;
		const std::string &getTitle() const;

		void setTitle(const std::string &);
		
		void introduce() const;

		void learnSpell(ASpell *);
		void forgetSpell(std::string);
		void launchSpell(std::string, ATarget &);
};

#endif
