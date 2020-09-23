#include<iostream>
#include<vector>
#include<iterator>
#include<list>
#include<map>
#include<unordered_map>
#include<forward_list>

using std::cout;
using std::endl;


template<typename BDItr> void my_reverse_imp(BDItr fst, BDItr lst, std::bidirectional_iterator_tag _) {
    typename std::iterator_traits<BDItr>::difference_type n = std::distance(fst, lst);
    while (n > 0)
    {
        std::swap(*fst++, *--lst);
        n -= 2;
    }    
}

template<typename BDItr> void my_reverse(BDItr fst, BDItr lst) {
    my_reverse_imp(fst, lst, typename std::iterator_traits<BDItr>::iterator_category());
}

template<typename Itr> void print_elements(Itr fst, Itr lst) {
    while (fst != lst)
    {
        std::cout << *fst++ << " ";

    }
}

int main() {
    std::vector<int> v = {1,2,3,4,5};
    my_reverse(v.begin(), v.end());
    print_elements(v.begin(), v.end());

    //std::forward_list<int> fl = {1,2,3,4,5};
    //my_reverse(fl.begin(), fl.end());

    return 0;
}