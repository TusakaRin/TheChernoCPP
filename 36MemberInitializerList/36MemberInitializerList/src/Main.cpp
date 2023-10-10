#include <iostream>

class Entity
{
private:
	std::string m_Name;
	int m_Score;
public:
	Entity() : m_Name("Unknown"), m_Score(0)  // write in order
	{
	}
	Entity(const std::string& name, int n) :m_Name(name), m_Score(n)
	{
	}
	const std::string& GetName() const { return m_Name; };
	const int& GetScore() const { return m_Score; };
};
int main()
{
	Entity e0;
	Entity e1("lk", 50);
	std::cout << e0.GetName() << e0.GetScore() << std::endl;
	std::cout << e1.GetName() << e1.GetScore() << std::endl;
}