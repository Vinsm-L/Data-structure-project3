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


tree::tree() {
	root = NULL;
}

tree::~tree() {
	if (NULL != root) {
		queue<Tnode*> q;
		q.push(root);
		Tnode* p = NULL;
		while (!q.empty()) {
			p = q.front();
			q.pop();
			if (NULL != p -> left) {q.push(p -> left);}
			if (NULL != p -> right) {q.push(p -> right);}
			delete p;
		}
	}
}

	/*
	** use the information in Fnode to create tree node. 
	** when root != NULL, we find the father node by name.
	*/
void tree::createNode(Fnode family) {
	// process unusual condition: the name is not in the tree
	if (NULL != root && NULL == layerTraverse(family.name)) return;
	Tnode* p_father = NULL;
	// append or find father
	if (NULL == root) {
		// virtual father
		// root = new Tnode();
		// virtual mother
		// root -> left = new Tnode();
		
		// the first father
		p_father = root =  new Tnode(family.name, family.gender, family.alive, NULL);
		// append brothers: only the first man needs to add brothers
		// p_father -> right = toSeries(family.siblingName, family.siblingGender, family.siblingAlive, family.siblingNumber, root);
	} else {
		p_father = layerTraverse(family.name);
	}
	// append wife
	Tnode* p_wife = p_father -> left = new Tnode(family.wifeName, family.wifeGender, family.wifeAlive, p_father);

	// append childred
	p_wife -> right = toSeries(family.kidsName, family.kidsGender, family.kidsAlive, family.kidsNumber, p_father);
	return;
}

// function : find the node with given name
// pre: the Name 
// post: found: the pointer to  node with given name
//		  else: NULL
Tnode* tree::layerTraverse(string Name) {
	queue<Tnode*> q;
	q.push(root);
	Tnode* p = NULL;
	while (!q.empty()) {
		p = q.front();
		q.pop();
		if (NULL != p -> left) {q.push(p -> left);}
		if (NULL != p -> right) {q.push(p -> right);}
		if (p -> name == Name) return p;
	}
	return NULL;
}

Tnode* tree::getRoot() {return root;}

bool tree::deleteNode(string Name) {
	Tnode* p = layerTraverse(Name);
	if (NULL != p) {
		p -> name = "-1";
		return true;
	} else {
		return false;
	}
}

Tnode* tree::toSeries(string* names, bool* genders, bool* alive, int length, Tnode* p_host) {
	if (0 == length) {
		return NULL;
	} else {
		Tnode* head, *tail;
		head = tail = new Tnode(names[0], genders[0], alive[0], p_host); 
		for (int i = 1; i < length; i++) {
			tail -> right = new Tnode(names[i], genders[i], alive[i], p_host);
		}
		return head;
	}
}
