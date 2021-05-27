/*
** ETNA PROJECT, 19/04/2021 by feuvra_v
** open_closed
** File description:
**      check if opening character has closing equivalent
*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

/*
typedef struct opener_list {
    char op;
    struct opener_list *next;
}openers_t;

std::map<char,char> get_map()
{
    std::map<char, char> opclos_map;
    opclos_map.insert(pair<char,char>('"', '"'));
    opclos_map.insert(pair<char,char>('\'', '\''));
    opclos_map.insert(pair<char,char>('(', ')'));
    opclos_map.insert(pair<char,char>('<', '>'));
    opclos_map.insert(pair<char,char>('[', ']'));
    opclos_map.insert(pair<char,char>('{', '}'));
    return (opclos_map);
}

char **get_opclose_array()
{
    char array[2][7] = {{"\"'(<[{"},{"\"')>]}"}};
    /*
    char **array = (char **) malloc(sizeof(char *) * 2);
    array[0] = (char *) malloc(sizeof(char) * 6);
    array[1] = (char *) malloc(sizeof(char) * 6);
    array[0][0] = '"';
    array[1][0] = '"';
    array[0][1] = '\'';
    array[1][1] = '\'';
    array[0][2] = '(';
    array[1][2] = ')';
    array[0][3] = '<';
    array[1][3] = '>';
    array[0][4] = 
}

bool is_opener(string str)
{
    size_t i = 0;
    size_t len = str.size();
    while (i < len) {
        switch (str[i]) {
            case '"': return(true);
            case '\'': return(true);
            case '(': return(true);
            case '<': return(true);
            case '[': return(true);
            case '{': return(true);
        }
        i = i + 1;
    }
    return (false);
}

bool is_ender(string str)
{
    size_t i = 0;
    size_t len = str.size();
    while (i < len) {
        switch (str[i]) {
            case '"': {return(true);};
            case '\'': return(true);
            case ')': return(true);
            case '>': return(true);
            case ']': return(true);
            case '}': return(true);
        }
        i = i + 1;
    }
    return (false);
}
*/

void add_opener(char c, std::vector<int> *count)
{
    (*count)[c] = (*count)[c] + 1;
    cout<<(*count)[c]<<endl;
}

void sub_ender(char c, std::vector<int> *count)
{
    char opener;

    switch (c) {
        case (')'): 
            opener = '(';
            break;
        case ('>'): 
            opener = '<';
            break;
        case (']'):
            opener = '[';
            break;
        case ('}'): 
            opener = '{';
            break;
    }
    (*count)[opener] = (*count)[opener] - (((*count)[opener] > 0 ) * 1);
}

void dup_openend(char c, std::vector<int> *count)
{
    (*count)[c] = 1 * !(*count)[c];
}

std::vector<void (*)(char, std::vector<int> *)> make_char_array()
{
    std::vector<void (*)(char, std::vector<int> *)> char_array(256, nullptr);
    char_array['"'] = dup_openend;
    char_array['\''] = dup_openend;
    char_array['('] = add_opener;
    char_array[')'] = sub_ender;
    char_array['<'] = add_opener;
    char_array['>'] = sub_ender;
    char_array['['] = add_opener;
    char_array[']'] = sub_ender;
    char_array['{'] = add_opener;
    char_array['}'] = sub_ender;
    return (char_array);
}

bool open_closed(std::string s)
{
    //std::map<char, char> opclos_map = get_map();
    std::vector<void (*)(char, std::vector<int> *)> char_array = make_char_array();
    std::vector<int> count(256, 0);
    //openers_t *list = NULL;
    size_t i = 0;
    size_t len = s.size();

    while (i < len) {
        if (char_array[s[i]]) {
            cout<<"here"<<endl;
            char_array[s[i]](s[i], &count);
        }
        i = i + 1;
    }
    if (count['"'] + count['\''] + count['('] + count['['] + count['<'] + count['{'])
        return (false);
    return(true);
}


int main() {
    /*
    std::map<char,int> hashmap;
    std::vector<int> yo(256, 0);

    yo['"'] = 1;
    hashmap.insert(pair<char,int>('B', 0));
    hashmap.insert(pair<char,int>('Z', 1));
    hashmap.insert(pair<char,int>('q', 19800));
    cout<<yo['"']<<endl;
    cout<<yo[23]<<endl;
    cout<<hashmap.find('q')->second<<endl;
    */
    cout<<open_closed("[<>]")<<endl;
    return (0);
}