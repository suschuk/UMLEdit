#include <string>
#include <vector>

class UML
{
public:
	UML(std::string name);
	std::string ParseProperty(std::string);
	std::string ParseMethod(std::string);
protected:
	void addProperty(std::string);
	void addMethod(std::string);

private:
	std::string name_;
	std::vector<std::string> property_;
	std::vector<std::string> method_;
	std::string rawItem;
};

class Dependence
{

public:

	Dependence(UML*, UML*, std::string = 0);
	void setDependenceType(std::string);

protected:

private:

	UML* item1_;
	UML* item2_;
	std::string dependeceType;
};