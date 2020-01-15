/*
*   Disjoint set(Union Find) Nive solution
*   Complexity O(N)
*/

#include <bits/stdc++.h>

using namespace std;

#define mx 1000
int parent[mx];

void make_set(int v)
{
    parent[v]=v;
}

// find parent of this set
int find_set(int v)
{
    if(v==parent[v]) return v;
    else return find_set(parent[v]);
}

// make set 'b' parent is set 'a' parent
void union_set(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if(a!=b) parent[b]=a;
}

int main()
{
    make_set(1);
    make_set(2);
    make_set(3);
    make_set(4);
    make_set(5);

    /*
        make_set
        parent:     index/set = [0][1][2][3][4][5].....[100]
                       parent = [ ][1][2][3][4][5].....[   ]
    */

    union_set(1,2);

    /*
        union_set
        parent:    index/set = [0][1][2][3][4][5].....[100]
                      parent = [ ][1][1][3][4][5].....[   ]
    */

    union_set(2,3);
    union_set(3,4);
    union_set(4,5);

    /*
        union_set
        parent:    index/set = [0][1][2][3][4][5].....[100]
                      parent = [ ][1][1][2][3][4].....[   ]
    */

    cout << find_set(5) << endl;
    cout << find_set(2) << endl;

    return 0;
}

