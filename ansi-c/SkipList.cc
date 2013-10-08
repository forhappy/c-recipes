/*
 * ========================================================================
 *
 *       Filename:  SkipList.hh
 *
 *    Description:  SkipList implementation.
 *
 *        Created:  10/08/2013 09:29:23 AM
 *
 *         Author:  Fu Haiping (forhappy), haipingf@gmail.com
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * ========================================================================
 */

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>

#define MAX_LEVEL 10
const float P = 0.8;

using namespace std;

// Skip Node Declaration
struct SkiplistNode {
    int value;
    SkiplistNode **follows;

    SkiplistNode(int level, int &value) {
        follows = new SkiplistNode*[level + 1];
        memset(follows, 0, sizeof(SkiplistNode*) * (level + 1));
        this->value = value;
    }

    ~SkiplistNode() {
        delete[] follows;
    }
};

// Skip List Declaration
struct skiplist
{
    SkiplistNode *header;
    int value;
    int level;
    skiplist() {
        header = new SkiplistNode(MAX_LEVEL, value);
        level = 0;
    }

    ~skiplist() {
        delete header;
    }

    void display();
    bool contains(int &);
    void insert(int &);
    void remove(int &);
};

// Main: Contains Menu
int main()
{
    skiplist ss;
    int choice, n;
    while (1)
    {
        cout<<endl<<"-----------------------"<<endl;
        cout<<endl<<"Operations on Skip list"<<endl;
        cout<<endl<<"-----------------------"<<endl;
        cout<<"1.Insert Element"<<endl;
        cout<<"2.Delete Element"<<endl;
        cout<<"3.Search Element"<<endl;
        cout<<"4.Display List "<<endl;
        cout<<"5.Exit "<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice)
        {
        case 1:
             cout<<"Enter the element to be inserted: ";
             cin>>n;
             ss.insert(n);
             if(ss.contains(n))
                 cout<<"Element Inserted"<<endl;
             break;
        case 2:
             cout<<"Enter the element to be deleted: ";
             cin>>n;
             if(!ss.contains(n))
             {
                 cout<<"Element not found"<<endl;
                 break;
             }
             ss.remove(n);
             if(!ss.contains(n))
                 cout<<"Element Deleted"<<endl;
             break;
        case 3:
             cout<<"Enter the element to be searched: ";
             cin>>n; 
             if(ss.contains(n))
                 cout<<"Element "<<n<<" is in the list"<<endl;
             else
                 cout<<"Element not found"<<endl;
        case 4:
             cout<<"The List is: ";
             ss.display();
             break;
        case 5:
             exit(1);
             break;
        default:
             cout<<"Wrong Choice"<<endl;
        }
    }
    return 0;
}

// Random Value Generator
float frand()
{
    return (float) rand() / RAND_MAX;
}

// Random Level Generator
int random_level()
{
    static bool first = true;
    if (first) {
        srand((unsigned)time(NULL));
        first = false;
    }
    int lvl = (int)(log(frand()) / log(1.-P));
    return lvl < MAX_LEVEL ? lvl : MAX_LEVEL;
}

// Insert Element in Skip List
void skiplist::insert(int &value)
{
    SkiplistNode *x = header;
    SkiplistNode *update[MAX_LEVEL + 1];
    memset(update, 0, sizeof(SkiplistNode*) * (MAX_LEVEL + 1));
    for (int i = level; i >= 0; i--) {
        while (x->follows[i] != NULL && x->follows[i]->value < value) {
            x = x->follows[i];
        }
        update[i] = x;
    }

    x = x->follows[0];
    if (x == NULL || x->value != value) {
        int lvl = random_level();
        if (lvl > level) {
            for (int i = level + 1;i <= lvl;i++) {
                update[i] = header;
            }
            level = lvl;
        }
        x = new SkiplistNode(lvl, value);
        for (int i = 0;i <= lvl;i++) {
            x->follows[i] = update[i]->follows[i];
            update[i]->follows[i] = x;
        }
    }
}

// Delete Element from Skip List
void skiplist::remove(int &value)
{
    SkiplistNode *x = header;
    SkiplistNode *update[MAX_LEVEL + 1];
    memset (update, 0, sizeof(SkiplistNode*) * (MAX_LEVEL + 1));
    for (int i = level;i >= 0;i--) {
        while (x->follows[i] != NULL && x->follows[i]->value < value) {
            x = x->follows[i];
        }
        update[i] = x;
    }

    x = x->follows[0];
    if (x->value == value) {
        for (int i = 0;i <= level;i++) {
            if (update[i]->follows[i] != x)
                break;
            update[i]->follows[i] = x->follows[i];
        }
        delete x;
        while (level > 0 && header->follows[level] == NULL) {
            level--;
        }
    }
}

// Display Elements of Skip List
void skiplist::display()
{
    const SkiplistNode *x = header->follows[0];
    while (x != NULL) {
        cout << x->value;
        x = x->follows[0];
        if (x != NULL)
            cout << " - ";
    }
    cout <<endl;
}



// Search Elemets in Skip List
bool skiplist::contains(int &s_value)
{
    SkiplistNode *x = header;
    for (int i = level;i >= 0;i--) {
        while (x->follows[i] != NULL && x->follows[i]->value < s_value) {
            x = x->follows[i];
        }
    }
    x = x->follows[0];
    return x != NULL && x->value == s_value;
}
