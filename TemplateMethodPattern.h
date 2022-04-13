#pragma once
#include <iostream>
#include <string>
#include "VisitorPattern.h"

namespace templates {
	class GreetingCardTemplate: public visitors::Visitor {
	private:
		std::string from;
	protected:
		virtual std::string intro(const std::string& to) {
			return "Dear " + to + ",\n";
		}
		virtual std::string occasion() {
			return "Just writing to say Hi! Hope all is well with you.";
		}
		virtual std::string closing(const std::string& from) {
			return "Sincerely,\n" + from + "\n";
		}
	public:
		GreetingCardTemplate(const std::string& from): from(from) {

		}
		~GreetingCardTemplate() {};
		std::string generateCardFor(visitors::Person* person) {
			return person->accept(this); 
		}
		std::string handlePerson(const std::string& name, int age) override {
			return intro(name) + occasion() + closing(from);
 		}
	};
	class BirthdayCardTemplate :public GreetingCardTemplate {
	public:
		BirthdayCardTemplate(const std::string& from)
			:GreetingCardTemplate(from)
		{

		}

	protected:
		std::string occasion() override {
			return "Happy Birthday! Hope you have a wonderful day and lots of cake.";
		};
	};

	class NewYearsCardTemplate : public GreetingCardTemplate {
	public:
		NewYearsCardTemplate(const std::string& from)
			:GreetingCardTemplate(from)
		{

		}

	protected:

		std::string intro(const std::string& to) override {
			return to + "!!!\n";
		}
		std::string occasion() override {
			return "Happy New Years!!! See you at the gym tomorrow!\n";
		}
	};
};