/*
** you can change the parameter or return value or add functions if necessary,
** but you have to let your teammates know it.
*/

#include <string>
using namespace std;

class tree {
public:
	struct Tnode {
		string name;
		bool gender;  // 0 represents male while 1 represents female
		bool alive;  // 0 represents dead while 1 represents alive
		Tnode* left, right, forward; // forward points to its parent node
		Tnode(string n = "-1", bool g = 0, bool a = 0, Tnode* l = NULL, Tnode* r = NULL, Tnode* f = NULL) {
			name = n;
			gender = g;
			alive = a;
			left = l;
			right = r;
			forward = f;
		}
	};

	struct Fnode {
		string name, gender, alive;               //  some string should be converted to bool in some way
		string wifeName, wifeGender, wifeAlive;
		int kidsNumber, siblingNumber;
		string* kidsName, kidsGender, kidsAlive;
		string* siblingName, siblingGender, siblingAlive;
	};

	tree();  //  default constructer

	~tree();  //  destructer

	/*
	** use the information in Fnode to create tree node. 
	** when root != NULL, we find the father node by name.
	*/
	void createNode(Fnode family);

	Tnode preorderTraverse(string Name);  //  find certain tree node by name, return default Tnode when find fail

	Tnode* getRoot();  //  return root

	bool deleteNode(string Name);  //  we delete the certain tree node by letting its name be -1

private:
	Tnode* root;
};