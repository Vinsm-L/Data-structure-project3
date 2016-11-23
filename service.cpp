/*
** you can change the parameter or return value or add functions if necessary,
** but you have to let your teammates know it.
*/
#include <iostream>
#include <string>
#include <queue>
#include <list>
#include "service.hpp"
using namespace std;

void service::createFamilyTree() {
	cout << "create family tree: " << endl;
	cout << "you should input the information of the male members in the family tree according to their seniority." << endl;
	cout << "input the total number of the male members: ";
	int male_num;
	cin >> male_num;
	while (male_num--) {
		Fnode male_member;

		cout << "input the name, survival of a male member. e.g. Michale dead / Tom alive" << endl;
		string g, a;
		cin >> male_member.name >> a;
		if (a == "alive") {
			male_member.alive = 1;
		} else {
			male_member.alive = 0;
		}
		male_member.gender = 0;

		cout << "input the name, survival of the male member's wife. input NO if he doesn't have a wife." << endl;
		cin >> male_member.wifeName;
		if (male_member.wifeName != "NO") {
			cin >> a;
			if (a == "alive") {
				male_member.wifeAlive = 1;
			} else {
				male_member.wifeAlive = 0;
			}
			male_member.wifeGender = 1;
		} else {
			male_member.wifeName = "-1";
			male_member.wifeGender = 0;
			male_member.wifeAlive = 0;
		}
		
		cout << "input the number of the kids of the male member. input 0 if he doesn't have a kid." << endl;
		cin >> male_member.kidsNumber;
		if (male_member.kidsNumber == 0) {
			male_member.kidsName = NULL;
			male_member.kidsGender = NULL;
			male_member.kidsAlive = NULL;
		} else {
			male_member.kidsName = new string[male_member.kidsNumber];
			male_member.kidsGender = new bool[male_member.kidsNumber];
			male_member.kidsAlive = new bool[male_member.kidsNumber];
			for (int i = 0; i < male_member.kidsNumber; i++) {
				cout << "input the " << i+1 << "th kid's name, gender, survival. e.g. Lily female alive" << endl;
				cin >> male_member.kidsName[i] >> g >> a;
				if (g == "male") {
					male_member.kidsGender[i] = 0;
				} else {
					male_member.kidsGender[i] = 1;
				}
				if (a == "dead") {
					male_member.kidsAlive[i] = 0;
				} else {
					male_member.kidsAlive[i] = 1;
				}
			}
		}
/*
		cout << "input the number of the sibling of the male member. input 0 if he doesn't have a sibling." << endl;
		cin >> male_member.siblingNumber;
		if (male_member.siblingNumber == 0) {
			male_member.siblingName = NULL;
			male_member.siblingGender = NULL;
			male_member.siblingAlive = NULL;
		} else {
			male_member.siblingName = new string[male_member.siblingNumber];
			male_member.siblingGender = new bool[male_member.siblingNumber];
			male_member.siblingAlive = new bool[male_member.siblingNumber];
			for (int i = 0; i < male_member.siblingNumber; i++) {
				cout << "input the " << i+1 << "th sibling's name, gender, survival." << endl;
				cin >> male_member.siblingName[i] >> g >> a;
				if (g == "male") {
					male_member.siblingGender[i] = 0;
				} else {
					male_member.siblingGender[i] = 1;
				}
				if (a == "dead") {
					male_member.siblingAlive[i] = 0;
				} else {
					male_member.siblingAlive[i] = 1;
				}
			}
		}
*/
		createNode(male_member);
	}
}
void service::deleteMember(string Name) {
  Tnode* p = layerTraverse(Name);
  if (p == NULL) {
    cout << "Can't find this member" << endl;
    return;
  }
  p -> name = "-1";
  cout << "Delete success." << endl;
}
void service::findMember(string Name) {
  Tnode* t = layerTraverse(Name);
  if (t == NULL || t -> name == "-1")
  return;
  Tnode* r = NULL;
    if (t -> host == NULL || t -> host -> left == t) {
    	cout << "Name:" << t -> name << endl;
		cout << "Gender:";
		if (t -> gender == 0)
		cout << "male" << endl;
		else
		cout << "female" << endl;
		cout << "Whether alive:";
		if (t -> alive == 0)
		cout << "no" << endl;
		else
		cout << "yes" << endl;
		if (t -> gender == 0 && t -> left -> name != "-1")
		cout << "Wife:" << t -> left -> name << endl;
		else if (t -> host -> name != "-1")
		cout << "Husband:" << t -> host -> name << endl;
		cout << "Children:";
		if (t -> gender == 1 && t -> right == NULL)
		cout << "None";
		else {
		if (t -> gender == 0)
		r = t -> left -> right;
		else
		r = t -> right;
		while (r != NULL) {
		if (r -> name == "-1") {
		r = r -> right;
		continue;
		}
		cout << r -> name << "(";
		if (r -> gender == 0)
		cout << "male) ";
		else
		cout << "female) ";
		r = r -> right;
		}
		cout << endl;
		}
		cout << "------------------------------------------------------------------" << endl;
		return;
	}
    cout << "Name:" << t -> name << endl;
    cout << "Gender:";
    if (t -> gender == 0)
      cout << "male" << endl;
    else
      cout << "female" << endl;
    cout << "Whether alive:";
    if (t -> alive == 0)
      cout << "no" << endl;
    else
      cout << "yes" << endl;
    r = t -> host;
    if (r -> name != "-1") 
	cout << "Father:" << r -> name << endl;
	if (r -> left -> name != "-1") 
	cout << "Mother:" << r -> left -> name << endl;
	if (t -> gender == 1 && t -> host -> left == t && t -> host -> name != "-1")
	cout << "Husband:" << t -> host -> name << endl;
    else if (t -> left != NULL)
    cout << "Wife:" << t -> left -> name << endl;
    cout << "Siblings:";
    r = t -> host -> left -> right;
    if (r -> right == NULL)
    cout << "None";
	else
    while (r != NULL) {
      if (r -> name == t -> name || r -> name == "-1") {
        r = r -> right;
        continue;
      }
      cout << r -> name << "(";
      if (r -> gender == 0)
      cout << "male) ";
	  else
	  cout << "female) ";
      r = r -> right;
    }
    cout << endl;
    cout << "Children:";
    if (t -> left == NULL)
    cout << "None";
    else {
    r = t -> left -> right;
    if (r == NULL)
	cout << "None";
    else
    while (r != NULL) {
      if (r -> name == "-1") {
        r = r -> right;
        continue;
      }
      cout << r -> name << "(";
      if (r -> gender == 0)
      cout << "male) ";
	  else
	  cout << "female) ";
      r = r -> right;
    }
}
    cout << endl;
    cout << "------------------------------------------------------------------" << endl;
}
void service::findMother(string Name) {
  Tnode* p = layerTraverse(Name);
  if (p == NULL || p -> name == "-1") {
    cout << "Can't find this member" << endl;
    cout << "------------------------------------------------------------------" << endl;
    return;
  }
  if (p -> host != NULL && p != p -> host -> left)
  findMember(p -> host -> left -> name);
  else
  cout << "None" << endl; 
  cout << "------------------------------------------------------------------" << endl;
}
void service::findFather(string Name) {
  Tnode* p = layerTraverse(Name);
  if (p == NULL || p -> name == "-1") {
    cout << "Can't find this member" << endl;
    cout << "------------------------------------------------------------------" << endl;
    return;
  }
  if (p -> host != NULL && p != p -> host -> left)
  findMember(p -> host -> name);
  else
  cout << "None" << endl; 
  cout << "------------------------------------------------------------------" << endl;
}
void service::findKids(string Name) {
  Tnode* p = layerTraverse(Name);
  if (p == NULL || p -> name == "-1") {
    cout << "Can't find this member" << endl;
    cout << "------------------------------------------------------------------" << endl;
    return;
  }
  if (p -> gender == 0 && (p -> left == NULL || p -> left -> right == NULL)) {
  	cout << "None" << endl;
  	cout << "------------------------------------------------------------------" << endl;
	  return; 
  }
  if (p -> gender == 1 && p -> right == NULL) {
  	cout << "None" << endl;
  	cout << "------------------------------------------------------------------" << endl;
	  return; 
  }
  if (p -> gender == 0)
  p = p -> left -> right;
  else
  p = p -> right;
  while (p != NULL) {
    if (p -> name == "-1") {
      p = p -> right;
      continue;
    }
    findMember(p -> name);
    p = p -> right;
  }
}
void service::findSibling(string Name) {
  Tnode* p = layerTraverse(Name);
  if (p == NULL || p -> name == "-1") {
    cout << "Can't find this member" << endl;
    cout << "------------------------------------------------------------------" << endl;
    return;
  }
  if (p -> host == NULL || p == p -> host -> left) {
  	cout << "None" << endl;
  	cout << "------------------------------------------------------------------" << endl;
	return; 
  }
  p = p -> host -> left -> right;
  if (p -> right == NULL) {
  	cout << "None" << endl;
	  return; 
  }
  while (p != NULL) {
    if (p -> name == Name || p -> name == "-1") {
      p = p -> right;
      continue;
    }
    findMember(p -> name);
    p = p -> right;
  }
}
void service::aliveNumber() {
  int sum = 0;
  list<Tnode*> q;
  q.push_back(getRoot());
  Tnode* t;
  list<Tnode*>::iterator it;
  for (it = q.begin(); it != q.end(); ++it) {
    t = *it;
    if (t -> left != NULL)
      q.push_back(t -> left);
    if (t -> right != NULL)
      q.push_back(t -> right);
  }
  for (it = q.begin(); it != q.end(); ++it) {
    t = *it;
    if (t -> alive == 1 && t -> name != "-1")
      sum++;
  }
  cout << "Alive Number:" << sum << endl;
}
void service::maleNumber() {
  int sum = 0;
  list<Tnode*> q;
  q.push_back(getRoot());
  Tnode* t;
  list<Tnode*>::iterator it;
  for (it = q.begin(); it != q.end(); ++it) {
    t = *it;
    if (t -> left != NULL)
      q.push_back(t -> left);
    if (t -> right != NULL)
      q.push_back(t -> right);
  }
  for (it = q.begin(); it != q.end(); ++it) {
    t = *it;
    if (t -> gender == 0 && t -> name != "-1")
      sum++;
  }
  cout << "Male Number:" << sum << endl;
}
void service::femaleNumber() {
  int sum = 0;
  list<Tnode*> q;
  q.push_back(getRoot());
  Tnode* t;
  list<Tnode*>::iterator it;
  for (it = q.begin(); it != q.end(); ++it) {
    t = *it;
    if (t -> left != NULL)
      q.push_back(t -> left);
    if (t -> right != NULL)
      q.push_back(t -> right);
  }
  for (it = q.begin(); it != q.end(); ++it) {
    t = *it;
    if (t -> gender == 1 && t -> name != "-1")
      sum++;
  }
  cout << "Female Number:" << sum << endl;
}
void service::printFamilyTree() {
  list<Tnode*> q;
  q.push_back(getRoot());
  Tnode* t;
  Tnode* r;
  list<Tnode*>::iterator it;
  for (it = q.begin(); it != q.end(); ++it) {
    t = *it;
    if (t -> left == NULL)
    continue;
    q.push_back(t -> left);
    if (t -> left -> right == NULL)
    continue;
    t = t -> left -> right;
    while (t != NULL) {
    	q.push_back(t);
    	t = t -> right;
    }
  }
  for (it = q.begin(); it != q.end(); ++it) {
    t = *it;
    findMember(t -> name);
  }
}