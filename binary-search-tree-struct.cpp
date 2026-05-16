/****************************************************************************************/
/*                                    Pre-Processing                                    */
/****************************************************************************************/

#include <bits/stdc++.h>
#define Made_By_Karimskee        \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
#define PI acos(-1.0)
#define resetColor "\033[0m\n" // Reset terminal color
using namespace std;

struct node {
    int val = 0;
    bool isEmpty = true;
    node* right = NULL;
    node* left = NULL;
};

/****************************************************************************************/
/*                                Functions Declaration                                 */
/****************************************************************************************/

void space(long long n);         // Print n blank lines (for better program interface purpose)
void clear();                    // Clears terminal
string color(const string& hex); // ANSI terminal color set
node* createBinaryTree(vector<int> elements = {});
bool isTreeEmpty(node* root);
node* searchTree(node* root, int val);
void insertNode(node* root, int val);
void deleteNode(node* root, int val);
void printBinaryTree(node* root);
int numOfNodes(node* root, int count = 0);
int numOfLeaves(node* root, int count = 0);
int heightOfTree(node* root, int height = 0);


/****************************************************************************************/
/*        ██╗  ██╗ █████╗ ██████╗ ██╗███╗   ███╗███████╗██╗  ██╗███████╗███████╗        */
/*        ██║ ██╔╝██╔══██╗██╔══██╗██║████╗ ████║██╔════╝██║ ██╔╝██╔════╝██╔════╝        */
/*        █████╔╝ ███████║██████╔╝██║██╔████╔██║███████╗█████╔╝ █████╗  █████╗          */
/*        ██╔═██╗ ██╔══██║██╔══██╗██║██║╚██╔╝██║╚════██║██╔═██╗ ██╔══╝  ██╔══╝          */
/*        ██║  ██╗██║  ██║██║  ██║██║██║ ╚═╝ ██║███████║██║  ██╗███████╗███████╗        */
/*        ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝╚═╝     ╚═╝╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝        */
/****************************************************************************************/

/****************************************************************************************/
/*                              Global Variables & Structs                              */
/****************************************************************************************/

/**
 * My own implementation of a binary search tree
 */
int main() {
    // UI
    clear();
    cout << color("#00FF00");
    space(100);

    node* thisIsEmpty = createBinaryTree();
    
    isTreeEmpty(thisIsEmpty);

    space(1);

    vector<int> elements = { 5, 3, 6, 4, 1, 7, 8, 12, 0 };
    node* bst = createBinaryTree(elements);

    space(1);

    cout << "Height of the tree: " << heightOfTree(bst) << endl;

    space(1);

    isTreeEmpty(bst);
    
    space(1);

    searchTree(bst, -1);
    searchTree(bst, 8);
    searchTree(bst, 5);

    space(1);

    cout << "Visualization of the BST as a map:" << endl;
    printBinaryTree(bst);
    
    space(1);

    cout << "Number of nodes: " << numOfNodes(bst, 0) << endl;
    cout << "Number of leaves: " << numOfLeaves(bst) << endl;

    space(1);

    insertNode(bst, 15);
    
    space(1);

    cout << "Visualization of the BST as a map after adding '15':" << endl;
    printBinaryTree(bst);

    space(1);

    cout << "Height of the tree: " << heightOfTree(bst) << endl;
    
    space(1);

    insertNode(bst, 4);
    
    cout << "Deleting some values from the BST." << endl;
    deleteNode(bst, 4);
    deleteNode(bst, -1);
    deleteNode(bst, 0);
    deleteNode(bst, 4);
    deleteNode(bst, 3);
    deleteNode(bst, 5);
    deleteNode(bst, 0);
    deleteNode(bst, 5);
    deleteNode(bst, 7);

    insertNode(bst, 7);

    cout << "Visualization of the BST as a map after deleting and inserting some values:" << endl;
    printBinaryTree(bst);

    cout << "Height of the tree: " << heightOfTree(bst) << endl;

    cout << resetColor;
}

/****************************************************************************************/
/*                                 Functions Definitions                                */
/****************************************************************************************/

node* createBinaryTree(vector<int> elements) {
    node* root = new node();

    if (elements.empty()) {
        cout << "Created an empty Binary Search Tree." << endl;
        return root;
    }

    root->val = elements.front();

    for (auto element : elements) {
        node* itr = root;

        while (true) {
            if (itr->isEmpty) {
                itr->val = element;
                itr->isEmpty = false;
                break;
            }
            else if (element < itr->val) {
                node* left = itr->left;
                if (left == NULL)
                    left = new node();

                itr->left = left;
                itr = left;
            }
            else if (element > itr->val) {
                node* right = itr->right;
                if (right == NULL)
                    right = new node();

                itr->right = right;
                itr = right;
            }
            else
                break;
        }
    }

    cout << "Binary Search Tree has been initialized with the given value/s." << endl;
    return root;
}

bool isTreeEmpty(node* root) {
    if (root->isEmpty) {
        cout << "Tree is empty." << endl;
        return true;
    }

    cout << "Tree is not empty" << endl;
    return false;
}

void deleteNode(node* root, int val) {
    node* parent = NULL;
    node* current = root;

    while (current != NULL && current->val != val) {
        parent = current;
        if (val < current->val) {
            current = current->left;
        }
        else {
            current = current->right;
        }
    }

    while (true) {
        if (current == NULL) {
            cout << "The number " << val << " not found." << endl;
            return;
        }
        if (current->left == NULL && current->right == NULL) {
            if (parent == NULL) {
                delete root;
                root = NULL;
                return;
            }
            else {
                if (parent->left == current)
                    parent->left = NULL;
                else
                    parent->right = NULL;

                delete current;
                return;
            }
        }
        else if (current->left == NULL) {
            node* child = current->right;

            if (parent == NULL) {
                delete current;
                root = child;
                return;
            }
            else {
                if (parent->left == current)
                    parent->left = child;
                else
                    parent->right = child;

                delete current;
                return;
            }
        }
        else if (current->right == NULL) {
            node* child = current->left;

            if (parent == NULL) {
                delete current;
                root = child;
                return;
            }
            else {
                if (parent->left == current)
                    parent->left = child;
                else
                    parent->right = child;

                delete current;
                return;
            }
        }
        else {
            node* succParent = current;
            node* successor = current->right;

            while (successor->left != NULL) {
                succParent = successor;
                successor = successor->left;
            }
            // Replace current's val with successor's val
            current->val = successor->val;
            // Now delete successor, which has at most one child (right)
            if (succParent->left == successor) {
                succParent->left = successor->right;
            }
            else {
                succParent->right = successor->right;
            }
            delete successor;
            return;
        }
    }
}

node* searchTree(node* root, int val) {
    node* itr = root;

    while (true) {
        if (itr == NULL) {
            cout << "The number " << val << " has not been found." << endl;
            return NULL;
        }
        else if (itr->val == val) {
            cout << "The number " << val << " has been found." << endl;
            return itr;
        }
        else if (val < itr->val)
            itr = itr->left;
        else
            itr = itr->right;
    }
}

void insertNode(node* root, int val) {
    node* itr = root;

    while (true) {
        if (itr->val == val) {
            cout << "The number " << val << " already exists." << endl;
            return;
        }
        else if (val < itr->val) {
            if (itr->left == NULL) {
                itr->left = new node;
                itr = itr->left;

                itr->val = val;
                itr->isEmpty = false;
                cout << "The number " << val << " has been inserted to the tree." << endl;
                return;
            }

            itr = itr->left;
        }
        else {
            if (itr->right == NULL) {
                itr->right = new node;
                itr = itr->right;

                itr->val = val;
                itr->isEmpty = false;
                cout << "The number " << val << " has been inserted to the tree." << endl;
                return;
            }

            itr = itr->right;
        }
    }
}

void printBinaryTree(node* root) {
    if (root == NULL)
        return;

    if (root->left != NULL)
        cout << root->val << " -> " << root->left->val << endl;
    if (root->right != NULL)
        cout << root->val << " -> " << root->right->val << endl;

    printBinaryTree(root->left);
    printBinaryTree(root->right);
}

int numOfNodes(node* root, int count) {
    if (root == NULL)
        return 0;

    return 1 + numOfNodes(root->left, count) + numOfNodes(root->right, count);
}

int numOfLeaves(node* root, int count) {
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL)
        return 1;

    return numOfLeaves(root->left) + numOfLeaves(root->right);
}

int heightOfTree(node* root, int height) {
    if (height == 0 && root != NULL)
        height = 1;

    height = max({height,   
        root->left != NULL ? heightOfTree(root->left, height + 1) : height,
        root->right != NULL ? heightOfTree(root->right, height + 1) : height});

    return height;
}

void space(long long n) {
    for (int i = 0; i < n; i++)
        cout << endl;
}

void clear() {
    const char* wslEnv = getenv("WSLENV");

    if (wslEnv)
        system("clear");
    else
        system("cls");
}

string color(const string& hex) {
    if (hex[0] != '#' || hex.length() != 7)
        return ""; // Invalid hex format

    // Parse hex color (remove # and convert to integer)
    string hexValue = hex.substr(1);
    int rgb = stol(hexValue, nullptr, 16);

    int r = (rgb >> 16) & 0xFF;
    int g = (rgb >> 8) & 0xFF;
    int b = rgb & 0xFF;

    ostringstream ansi;
    ansi << "\033[38;2;" << r << ";" << g << ";" << b << "m";
    return ansi.str();
}
