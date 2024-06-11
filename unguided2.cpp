#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct TreeNode
{
    string data;
    vector<TreeNode *> children;
    TreeNode(const string &value) : data(value) {}
};

class Tree
{
private:
    TreeNode *root;

public:
    Tree() : root(nullptr) {}

    void insertNode(TreeNode *parent, const string &value)
    {
        TreeNode *newNode = new TreeNode(value);
        if (!root)
        {
            root = newNode;
            cout << "Node '" << value << "' berhasil ditambahkan sebagai root." << endl;
        }
        else
        {
            parent->children.push_back(newNode);
            cout << "Node '" << value << "' berhasil ditambahkan sebagai child dari '" << parent->data << "'." << endl;
        }
    }

    void displayChildAndDescendant(TreeNode *node)
    {
        if (!node)
            return;
        if (!node->children.empty())
        {
            cout << "Node '" << node->data << "' memiliki child: ";
            for (TreeNode *child : node->children)
            {
                cout << child->data << " ";
            }
            cout << endl;
        }
        for (TreeNode *child : node->children)
        {
            displayChildAndDescendant(child);
        }
    }

    TreeNode *getRoot() const
    {
        return root;
    }

    // Fungsi untuk mencari node parent berdasarkan namanya
    void searchParent(TreeNode *node, const string &parentName, TreeNode *&parent)
    {
        if (!node)
            return;

        if (node->data == parentName)
        {
            parent = node;
            return;
        }

        for (TreeNode *child : node->children)
        {
            searchParent(child, parentName, parent);
        }
    }
};

int main()
{
    Tree tree;
    TreeNode *parentNode = nullptr;
    int numNodes;
    cout << "Masukkan jumlah node tree: ";
    cin >> numNodes;
    for (int i = 0; i < numNodes; i++)
    {
        string nodeName;
        cout << "Masukkan nama node " << i + 1 << ": ";
        cin >> nodeName;
        if (!tree.getRoot())
        {
            tree.insertNode(nullptr, nodeName);
            parentNode = tree.getRoot();
        }
        else
        {
            string parentName;
            cout << "Masukkan nama parent node: ";
            cin >> parentName;
            // Cari parent node
            TreeNode *parent = nullptr;
            tree.searchParent(tree.getRoot(), parentName, parent);
            if (parent)
            {
                tree.insertNode(parent, nodeName);
            }
            else
            {
                cout << "Parent dengan nama '" << parentName << "' tidak ditemukan. Node '" << nodeName << "' ditambahkan sebagai root baru." << endl;
                tree.insertNode(nullptr, nodeName);
            }
        }
    }
    cout << "\nTree yang telah dibuat:\n";
    tree.displayChildAndDescendant(tree.getRoot());
    return 0;
}
