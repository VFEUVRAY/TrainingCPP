/*
** ETNA PROJECT, 17/05/2021 by feuvra_v
** xorlist
** File description:
**      xor
*/

#include <vector>
#include <iostream>
#include <cassert>

using namespace std;

typedef struct list_s {
    int data;
    struct list_s *npx;
} list_t;

list_t *insert(list_t *list, int data)
{
    list_t *new_link = (list_t *) malloc(sizeof(list_t));

    if (list)
        list->npx = (list_t *) (((uintptr_t) (list->npx) ^ 0) ^ ((uintptr_t) new_link));
    new_link->data = data;
    new_link->npx = (list_t *) ((list ? ((uintptr_t) (list)) : 0) ^ 0);
    return (new_link);
}

std::vector<int> printList(list_t *list)
{
    std::vector<int> result;
    list_t *prev = 0;
    list_t *temp;

    while (list) {
        result.push_back(list->data);
        temp = list;
        list = (list_t *) ((uintptr_t) (list->npx) ^ (uintptr_t) (prev));
        prev = temp;
    }
    return (result);
}


/*
int main()
{
    list_t *list = (list_t *) malloc(sizeof(list_t));
    std::vector<int> res;
    list->data = 15;
    list->npx = NULL;
    list = NULL;
    list = insert(list, 5);
    list = insert(list, 1);
    list = insert(list, 12);
    res = printList(list);
    //cout<<list->data<<endl;
    //list = (list_t *) ((uintptr_t) list->npx ^ 0);
    //cout<<list->data<<endl;
    for (auto it = res.begin() ; it != res.end() ; it++)
        cout<<*it<<endl;
    return (1);
}
*/

int main ()
{
    int t;
    cin>>t;
    while(t--)
    {
        list_t *head = NULL;
        int n, tmp;
        cin>>n;
        while(n--)
        {
            cin>>tmp;
            head = insert(head, tmp);
        }
        vector<int> vec = printList (head);
        for(int x : vec)
        cout<<x<<" ";
        cout<<endl;
        for(int i = vec.size() - 1;i>=0;i--){
            cout<<vec[i]<<" ";
        }
        cout<<"\n";
    }
	return (0);
}