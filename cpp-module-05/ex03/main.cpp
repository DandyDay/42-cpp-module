#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <iostream>

int main()
{
	// Test 1
	std::cout << "----------Test 1----------" << std::endl;
	try
	{
		Intern someRandomIntern;
		AForm *rrf, *ppf, *scf, *nsf;
		Bureaucrat signer("Signer", 50);

		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		signer.signForm(*rrf);
		signer.executeForm(*rrf);

		scf = someRandomIntern.makeForm("shrubbery creation", "Bender");
		signer.signForm(*scf);
		signer.executeForm(*scf);

		ppf = someRandomIntern.makeForm("presidential pardon", "Bender");
		signer.signForm(*ppf);
		signer.executeForm(*ppf);

		nsf = someRandomIntern.makeForm("no such form", "Bender");
		signer.signForm(*nsf);
		signer.executeForm(*nsf);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
