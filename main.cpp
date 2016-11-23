/*
** main function.
** implement the menu in this file. You can refer to your Agenda project's menu.
** different user instructions call the corresponding function in class service.
*/

#include <iostream>
#include <string>
#include <queue>
#include <list>
#include "service.hpp"
using namespace std;

int main() {
	service familyTreeService;

	cout << "--------------------------------------------menu--------------------------------------------" << endl;
	cout << "family tree service program. input the following instructions to get corresponding service." << endl;
	cout << endl;
	cout << "cft    --    create a family tree" << endl;
	cout << "dm     --    delete a member in the family tree by name" << endl;
	cout << "fm     --    find a certain member in the family tree by name" << endl;
	cout << "fmm    --    find the mother of the member with the name" << endl;
	cout << "fmf    --    find the father of the member with the name" << endl;
	cout << "fmk    --    find the kids of the member with the name" << endl;
	cout << "fms    --    find the sibling of the member with the name" << endl;
	cout << "can    --    count the number of the alive members in the family tree" << endl;
	cout << "cmn    --    count the number of the male members in the family tree" << endl;
	cout << "cfn    --    count the number of the female members in the family tree" << endl;
	cout << "pft    --    print the information of the members in the family tree" << endl;
	cout << "menu   --    look up the menu to find instructions" << endl;
	cout << "o      --    quit service" << endl;
	cout << "--------------------------------------------------------------------------------------------" << endl;
	cout << endl << "@: ";

	string oper;
	while (true) {
		cin >> oper;
		if (oper == "cft") {
			familyTreeService.createFamilyTree();
			cout << "Create success." << endl;
			cout << "@: ";
			continue;
		}
		if (oper == "dm") {
			cout << "please input the name of the member: " << endl;
			string Name;
			cin >> Name;
			familyTreeService.deleteMember(Name);
			cout << "@: ";
			continue;
		}
		if (oper == "fm") {
			cout << "please input the name of the member: " << endl;
			string Name;
			cin >> Name;
			familyTreeService.findMember(Name);
			cout << "@: ";
			continue;
		}
		if (oper == "fmm") {
			cout << "please input the name of the member: " << endl;
			string Name;
			cin >> Name;
			familyTreeService.findMother(Name);
			cout << "@: ";
			continue;
		}
		if (oper == "fmf") {
			cout << "please input the name of the member: " << endl;
			string Name;
			cin >> Name;
			familyTreeService.findFather(Name);
			cout << "@: ";
			continue;
		}
		if (oper == "fmk") {
			cout << "please input the name of the member: " << endl;
			string Name;
			cin >> Name;
			familyTreeService.findKids(Name);
			cout << "@: ";
			continue;
		}
		if (oper == "fms") {
			cout << "please input the name of the member: " << endl;
			string Name;
			cin >> Name;
			familyTreeService.findSibling(Name);
			cout << "@: ";
			continue;
		}
		if (oper == "can") {
			cout << "count alive member: " << endl;
			familyTreeService.aliveNumber();
			cout << "@: ";
			continue;
		}
		if (oper == "cmn") {
			cout << "count male member: " << endl;
			familyTreeService.maleNumber();
			cout << "@: ";
			continue;
		}
		if (oper == "cfn") {
			cout << "count female member: " << endl;
			familyTreeService.femaleNumber();
			cout << "@: ";
			continue;
		}
		if (oper == "pft") {
			cout << "print member information: " << endl;
			familyTreeService.printFamilyTree();
			cout << "@: ";
			continue;
		}
		if (oper == "menu") {
			cout << "--------------------------------------------menu--------------------------------------------" << endl;
			cout << "family tree service program. input the following instructions to get corresponding service." << endl;
			cout << endl;
			cout << "cft    --    create a family tree" << endl;
			cout << "dm     --    delete a member in the family tree by name" << endl;
			cout << "fm     --    find a certain member in the family tree by name" << endl;
			cout << "fmm    --    find the mother of the member with the name" << endl;
			cout << "fmf    --    find the father of the member with the name" << endl;
			cout << "fmk    --    find the kids of the member with the name" << endl;
			cout << "fms    --    find the sibling of the member with the name" << endl;
			cout << "can    --    count the number of the alive members in the family tree" << endl;
			cout << "cmn    --    count the number of the male members in the family tree" << endl;
			cout << "cfn    --    count the number of the female members in the family tree" << endl;
			cout << "pft    --    print the information of the members in the family tree" << endl;
			cout << "menu   --    look up the menu to find instructions" << endl;
			cout << "o      --    quit service" << endl;
			cout << "--------------------------------------------------------------------------------------------" << endl;
			cout << endl << "@: ";
			continue;
		}
		if (oper == "o") {
			cout << "thanks for using our program." << endl;
			break;
		}
		cout << "@: ";
	}
	
	return 0;
} 