#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator()
{
}

TargetGenerator::~TargetGenerator()
{
	for (std::map<std::string, ATarget *>::iterator it = _targetMap.begin(); it != _targetMap.end() ; ++it)
		delete it->second;
	_targetMap.clear();
}


void TargetGenerator::learnTargetType(ATarget* target)
{
	if (target)
		_targetMap[target->getType()] = target->clone();

}

void TargetGenerator::forgetTargetType(std::string const &type)
{
	std::map<std::string, ATarget *>::iterator it = _targetMap.find(type);
	if (it != _targetMap.end())
	{
		delete it->second;
		_targetMap.erase(it);
	}

}

ATarget* TargetGenerator::createTarget(std::string const &type)
{
	std::map<std::string, ATarget *>::iterator it = _targetMap.find(type);
	if (it != _targetMap.end())
		return it->second; // return _targetMap[type];
	return NULL;
}
