/*
*   Disjoint set(Union Find) Union By Rank
*   Complexity probably Constant time
*/

#include <bits/stdc++.h>

using namespace std;

#define mx 1000
int parent[mx];
int Rank[mx];

void make_set(int v)
{
    parent[v]=v;
    Rank[v]=0;
}

// find the root parent of this set and make this root parent for all visited sets
int find_set(int v)
{
    if(v==parent[v]) return v;
    else return parent[v]=find_set(parent[v]);
}

// make parent based on max rank/depth level of tree
void union_set(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if(a!=b)
    {
        if(Rank[a]<Rank[b]) swap(a,b);
        parent[b]=a;
        if(Rank[a]==Rank[b]) Rank[a]++;
    }
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
                       Rank   = [ ][0][0][0][0][0].....[   ]

       Five sets :  [1] [2] [3] [4] [5]

    */

    union_set(1,2);

    /*
        union_set
        parent:    index/set = [0][1][2][3][4][5].....[100]
                      parent = [ ][1][1][3][4][5].....[   ]
                      Rank   = [ ][1][0][0][0][0].....[   ]

        Four sets :     [1] [3] [4] [5]
                        /
                      [2]
    */

    union_set(2,3);
    union_set(3,4);
    union_set(4,5);

    /*
        union_set
        parent:    index/set = [0][1][2][3][4][5].....[100]
                      parent = [ ][1][1][1][1][1].....[   ]
                      Rank   = [ ][1][0][0][0][0].....[   ]

        One sets :         [1] ----------- Rank 1
                        /  |  \  \
                      [2] [3] [4] [5] ---- Rank 0
    */

    cout << find_set(5) << endl;
    cout << find_set(2) << endl;

    return 0;
}

