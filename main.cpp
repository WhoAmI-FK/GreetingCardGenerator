#include "VisitorPattern.h"
#include "TemplateMethodPattern.h"
#include <vector>
class GreetingCardGenerator {
private:
	templates::GreetingCardTemplate* temp;
	std::vector<visitors::Person*> people;
public:
	std::vector<std::string> createGreetingCards() {
		std::vector<std::string> cards;
		for (auto person : people) {
			cards.push_back(temp->generateCardFor(person));
		}
		return cards;
	};
	void addPerson(visitors::Person* person) {
		people.push_back(person);
	}
	void setTemplate(templates::GreetingCardTemplate* newTemp){
		temp = newTemp;
	}
};


int main()
{
	visitors::Person* person1 = new visitors::Person("John", 40);
	visitors::Person* person2 = new visitors::Person("Joan", 80);
	visitors::Person* person3 = new visitors::Person("Brenda", 25);


	GreetingCardGenerator* generator = new GreetingCardGenerator;
	generator->addPerson(person1);
	generator->addPerson(person2);
	generator->addPerson(person3);

	generator->setTemplate(new templates::BirthdayCardTemplate("Bob"));
	for (auto card : generator->createGreetingCards()) {
		std::cout << card << "\n";
	}
	generator->setTemplate(new templates::NewYearsCardTemplate("Penelope"));
	for (auto card : generator->createGreetingCards()) {
		std::cout << card << "\n";
	}
	delete person1;
	delete person2;
	delete person3;


	return 0;
}