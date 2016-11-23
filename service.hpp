/*
** you can change the parameter or return value or add functions if necessary,
** but you have to let your teammates know it.
*/

#include <iostream>
#include <string>
#include <queue>
#include <list>
#include "tree.hpp"
using namespace std;

/*
** all the user inputs and outputs are implemented in this class.
** also each function should contain some outputs to prompt the user.
*/
class service : public tree {
public:
	service() {} 

	~service() {} 
	
	/*
	** we divide the inputs into different Fnode, gradually we build a family tree.
	** when some item doesn't exist, the input is a string "No".
	*/
	void createFamilyTree();

	void deleteMember(string Name);  //  delete certain member by Name

	void findMember(string Name);  //  find certain member by Name and then output the information

	void findMother(string Name);  //  find mother of the member with the Name and then output information

	void findFather(string Name);  //  find father of the member with the Name and then output information

	void findKids(string Name);  //  find kids of the member with the Name and then output information

	void findSibling(string Name);  //  find sibling of the member with the Name and then output information

	void aliveNumber();  //  output the the number of alive members

	void maleNumber();  //  output the the number of male members

	void femaleNumber();  //  output the the number of female members

	/*
	** print the whole family tree with individuals' information
	** try to show it in an easily comprehensible way
	*/
	void printFamilyTree();
};
