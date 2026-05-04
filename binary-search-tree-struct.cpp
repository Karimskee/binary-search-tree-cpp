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
void printBinaryTree(node* root);
int numOfLeaves(node* root, int count = 0);
int numOfNodes(node* root, int count = 0);

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

    vector<int> elements = { 5, 3, 6, 4, 1, 7, 8, 12, 0 };
    node* bst = createBinaryTree(elements);

    isTreeEmpty(bst);

    searchTree(bst, -1);
    searchTree(bst, 8);
    searchTree(bst, 5);

    printBinaryTree(bst);
    space(1);

    cout << numOfNodes(bst, 0) << endl;
    cout << numOfLeaves(bst) << endl;

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