#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

class Student_info
{
    struct Student
    {
        string name;
        string USN;
        long int phone_no;
        float cgpa;
    };

    struct Snode
    {
        Student data;
        Snode *left = nullptr;
        Snode *right = nullptr;
    };

    Snode *root = nullptr;
    unordered_map<string, Student> std_map;

    Snode *Make_node(Student std)
    {
        Snode *newnode = new Snode;
        newnode->data.name = std.name;
        newnode->data.USN = std.USN;
        newnode->data.phone_no = std.phone_no;
        newnode->data.cgpa = std.cgpa;
        return newnode;
    }

    void setleft(Snode *node, Student std)
    {
        node->left = Make_node(std);
    }

    void setright(Snode *node, Student std)
    {
        node->right = Make_node(std);
    }

    void inorder(Snode *root)
    {
        if (!root)
            return;
        inorder(root->left);
        cout << root->data.name << "\t" << root->data.USN << "\t"
             << root->data.phone_no << "\t" << root->data.cgpa << endl;
        inorder(root->right);
    }

    void modify_tree(Snode *root, string name, string usn, long int phone, float cgpa)
    {
        if (!root)
            return;
        else if (root->data.USN == usn)
        {
            root->data.name = name;
            root->data.phone_no = phone;
            root->data.cgpa = cgpa;
        }
        else if (root->data.USN > usn)
            modify_tree(root->left, name, usn, phone, cgpa);
        else
            modify_tree(root->right, name, usn, phone, cgpa);
    }

    Snode *del_stud(Snode *root, string usn)
    {
        if (!root)
            return nullptr;
        if (root->data.USN > usn)
            root->left = del_stud(root->left, usn);
        else if (root->data.USN < usn)
            root->right = del_stud(root->right, usn);
        else
        {
            if (!root->left && !root->right)
            {
                delete root;
                return nullptr;
            }
            else if (!root->right)
            {
                Snode *tmp = root->left;
                delete root;
                return tmp;
            }
            else if (!root->left)
            {
                Snode *tmp = root->right;
                delete root;
                return tmp;
            }
            else
            {
                Snode *rcld = root->right;
                while (rcld->left)
                    rcld = rcld->left;
                root->data = rcld->data;
                root->right = del_stud(root->right, rcld->data.USN);
            }
        }
        return root;
    }

    int count(Snode *root)
    {
        if (!root)
            return 0;
        else
            return 1 + count(root->left) + count(root->right);
    }

public:
    void Insert_student(string n, string usn, long int phone, float cgpa)
    {
        Student s;
        s.name = n;
        s.phone_no = phone;
        s.USN = usn;
        s.cgpa = cgpa;

        if (std_map.find(usn) != std_map.end())
        {
            cout << "Student with USN " << usn << " is already present\n";
            return;
        }
        else
        {
            std_map[usn] = s;
        }

        if (!root)
        {
            root = Make_node(s);
        }
        else
        {
            Snode *p = root;
            Snode *q = root;

            while (q && q->data.USN != usn)
            {
                p = q;
                if (p->data.USN > usn)
                    q = p->left;
                else
                    q = p->right;
            }

            if (p->data.USN > usn)
                setleft(p, s);
            else
                setright(p, s);
        }
    }

    bool search_student(string usn)
    {
        return std_map.find(usn) != std_map.end();
    }

    void Student_display(string usn)
    {
        if (std_map.find(usn) != std_map.end())
        {
            Student st = std_map[usn];
            cout << "Name: " << st.name << endl;
            cout << "USN: " << st.USN << endl;
            cout << "Contact Info: " << st.phone_no << endl;
            cout << "CGPA: " << st.cgpa << endl;
        }
        else
            cout << "Student not found\n";
    }

    void modify_data(string name, string usn, long int phone, float cgpa)
    {
        if (std_map.find(usn) != std_map.end())
        {
            std_map[usn].name = name;
            std_map[usn].phone_no = phone;
            std_map[usn].cgpa = cgpa;
            modify_tree(root, name, usn, phone, cgpa);
            cout << "Data modified successfully\n";
        }
        else
            cout << "Student not found\n";
    }

    void remove_stud(string usn)
    {
        if (std_map.find(usn) != std_map.end())
        {
            std_map.erase(usn);
            root = del_stud(root, usn);
            cout << "Student with USN " << usn << " deleted successfully\n";
        }
        else
            cout << "Student not found :(\n";
    }

    void Display()
    {
        if (!root)
        {
            cout << "No students to display\n";
            return;
        }
        cout << "Name\tUSN\tContact\tCGPA\n";
        inorder(root);
    }

    int count_students()
    {
        return count(root);
    }

    void maxmin_stud(int k, int flag)
    {
        if (std_map.empty())
        {
            cout << "No students to display :( \n";
            return;
        }

        vector<Student> vec;
        for (auto itr = std_map.begin(); itr != std_map.end(); itr++)
            vec.push_back(itr->second);

        if (flag)
        {
            sort(vec.begin(), vec.end(), [](Student &a, Student &b)
                 { return a.cgpa > b.cgpa; });
            cout << "Top " << k << " students with highest CGPA:\n";
        }
        else
        {
            sort(vec.begin(), vec.end(), [](Student &a, Student &b)
                 { return a.cgpa < b.cgpa; });
            cout << "Top " << k << " students with lowest CGPA:\n";
        }

        for (int i = 0; i < vec.size() && i < k; i++)
        {
            cout << "USN: " << vec[i].USN << endl;
            cout << "Name: " << vec[i].name << endl;
            cout << "CGPA: " << vec[i].cgpa << endl;
            cout << "-------------------\n";
        }
    }
};
