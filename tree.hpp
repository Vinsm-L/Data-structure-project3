/*
** you can change the parameter or return value or add functions if necessary,
** but you have to let your teammates know it.
*/
#include <iostream>
#include <string>
#include <queue>
#include <list>
using namespace std;

struct Tnode {
		string name;
		bool gender;  // 0 represents male while 1 represents female
		bool alive;  // 0 represents dead while 1 represents alive
		Tnode* left;
		Tnode* right;
		Tnode* host; // forward points to the node of family host
		Tnode(string n = "-1", bool g = 0, bool a = 0, Tnode* h = NULL) {
			name = n;
			gender = g;
			alive = a;
			left = NULL;
			right = NULL;
			host = h;
		}
	};

	struct Fnode {
		string name;
		bool gender, alive;               //  some string should be converted to bool in some way
		string wifeName;
		bool wifeGender, wifeAlive;
		int kidsNumber;
		string* kidsName;
		bool* kidsGender;
		bool* kidsAlive;
	};

class tree {
public:
	tree();  //  default constructer

	~tree();  //  destructer

	/*
	** use the information in Fnode to create tree node. 
	** when root != NULL, we find the father node by name.
	*/
	void createNode(Fnode family);
	// function : find the node with given name
	// pre: the Name 
	// post: found: the pointer to  node with given name
	//		  else: NULL
	Tnode* layerTraverse(string Name);  //  find certain tree node by name, return NULL when find fail
	//  return root
	Tnode* getRoot();  
	//  we delete the certain tree node by letting its name be -1 
	bool deleteNode(string Name); 


private:
	Tnode* root;
	// function : link Tnodes to a series
	// pre : array of names, gender, alive, length of arrays
	// post : success: the pointer to the series we get
	//          else : NULL
	Tnode* toSeries(string* names, bool* genders, bool* alive, int length, Tnode* p_host);
};