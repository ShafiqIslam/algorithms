#include <iostream>
#include <list>
#include <string>
#include <functional>
#include <utility>
using namespace std;

#define HASH_SIZE 100

class HashTable
{
private:
    list< pair<string, string> >* hash_table;

    int hash_function(string s)
    {
        //hash<std::string> hash_fn;
        //size_t hash = hash_fn(s);
        return hash<std::string>{}(s) % HASH_SIZE;
    }
public:
    HashTable()
    {
        hash_table = new list< pair<string, string> >[HASH_SIZE];
    }

    void store(string key, string value)
    {
        int index = hash_function(key);

        auto p = make_pair(key, value);
        hash_table[index].push_back(p);
    }

    string getValueOfKey(string key)
    {
        int index = hash_function(key);
        list< pair<string, string> >::iterator it = hash_table[index].begin();
        for ( ; it != hash_table[index].end(); ++it) {
            auto p = *it;
            if(p.first == key)
                return p.second;
        }
        return "Uncaught Reference! Key does not exist!";
    }

    void deleteKey(string key)
    {
        int index = hash_function(key);
        list< pair<string, string> >::iterator it = hash_table[index].begin();
        for ( ; it != hash_table[index].end(); ++it) {
            auto p = *it;
            if(p.first == key) {
                hash_table[index].erase(it);
                cout << "Key deleted!" << endl;
                return;
            }
        }
        cout << "Uncaught Reference! Key does not exist!" << endl;
        return;

    }

    void print_table()
    {
        for(int i=0; i<HASH_SIZE; i++) {
            list< pair<string, string> >::iterator it = hash_table[i].begin();
            for ( ; it != hash_table[i].end(); ++it) {
                auto p = *it;
                cout << p.first << "-" << p.second;
                cout << "  ";
            }
            cout<<endl;
        }
    }
};

int main()
{
    HashTable phone_book;

    phone_book.store("Jon", "01731858108");
    phone_book.store("Yegritte", "01793155677");
    phone_book.store("Arya", "01682588143");
    phone_book.store("Tyrion", "01674068385");
    phone_book.store("Sam", "01816814512");
    phone_book.store("Dany", "01686875605");
    phone_book.store("Brienne", "01969137234");
    phone_book.store("Hodor", "01737855870");

    //phone_book.print_table();

    cout << phone_book.getValueOfKey("Dany") << endl << endl;

    phone_book.deleteKey("Brienne");
    cout << phone_book.getValueOfKey("Brienne") << endl;

    cout<<endl;
    return 0;
}



/*

                    Theories
                ===============


Data Structure: Chained Hash Table


Hash table (hash map) is used to implement an associative array, a structure that can map keys to values.
A hash table uses a hash function to compute an index into an array of buckets or slots,
from which the desired value can be found.
Ideally, the hash function will assign each key to a unique bucket, but it is possible that two keys will
generate an identical hash causing both keys to point to the same bucket. Instead, most hash table designs
assume that hash collisions. So, different keys that are assigned by the hash function to the same bucket
will occur and must be accommodated in some way.

So, there is two important things.

1. Hashing Function: taken care by C++ built in hash function.
2. Collision Resolution Policy: To manage multiple keys in the bucket array, a chained list can be used.


Complexity:
-----------
            Average	    Worst case
Space	    O(n)	    O(n)
Search	    O(1)	    O(n)
Insert	    O(1)	    O(n)
Delete	    O(1)	    O(n)

The worst case is when all the keys are hashed to just one bucket. Then it turns into a single linked list.
Otherwise it has a constant runtime.

*/
