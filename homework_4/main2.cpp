//
//  Using STL
//

//
//  #1: Merge linked lists
//  Runtime O: O(n+m) n=length of list1, m = length of list2
//  Spacetime O: O(n+m)
//

#include <iostream>
#include <list>

std::list<int> mergeSortedLists(std::list<int>& list1, std::list<int>& list2) {
    std::list<int> merged;
    auto it1 = list1.begin();
    auto it2 = list2.begin();

    while (it1 != list1.end() && it2 != list2.end()) {
        if (*it1 < *it2) {
            merged.push_back(*it1);
            ++it1;
        } else {
            merged.push_back(*it2);
            ++it2;
        }
    }

    // Append remaining elements
    merged.insert(merged.end(), it1, list1.end());
    merged.insert(merged.end(), it2, list2.end());

    return merged;
}

//
//  #2: delete Nth node
//  Runtime O: O(n) n=length of list
//  Spacetime O: O(1)
//

bool deleteNthFromEnd(std::list<int>& lst, int n) {
    if (n <= 0 || lst.empty()) return false;

    auto fast = lst.begin();
    auto slow = lst.begin();

    // Advance `fast` n steps
    for (int i = 0; i < n; ++i) {
        if (fast == lst.end()) return false;
        ++fast;
    }

    // Special case: remove first element
    if (fast == lst.end()) {
        lst.pop_front();
        return true;
    }

    // Move `fast` to end, `slow` follows
    auto prev = slow;
    while (fast != lst.end()) {
        ++fast;
        ++slow;
        if (fast != lst.end()) ++prev;
    }

    lst.erase(slow);
    return true;
}

//
//  #3
//  Runtime O: O(n log n) n=length of list
//  Spacetime O: O(n)
//

#include <string>
#include <fstream>
#include <sstream>

struct Name {
    std::string first;
    std::string last;

    bool operator<(const Name& other) const {
        return (first == other.first) ? (last < other.last) : (first < other.first);
    }
};

int main() {
    std::list<Name> nameList;

    std::ofstream out("list.txt", std::ios::app);
    out << "YourFirst YourLast\n";
    out.close();

    std::ifstream in("list.txt");
    std::string line;
    while (std::getline(in, line)) {
        std::istringstream iss(line);
        Name n;
        if (iss >> n.first >> n.last) {
            nameList.push_back(n);
        }
    }
    in.close();

    nameList.sort();

    std::ofstream sorted("sorted_names.txt");
    for (const auto& name : nameList) {
        sorted << name.first << " " << name.last << "\n";
    }
    sorted.close();

    return 0;
}

int main() {
    std::list<Name> nameList;

    std::ofstream out("list.txt", std::ios::app);
    out << "YourFirst YourLast\n";
    out.close();

    std::ifstream in("list.txt");
    std::string line;
    while (std::getline(in, line)) {
        std::istringstream iss(line);
        Name n;
        if (iss >> n.first >> n.last) {
            nameList.push_back(n);
        }
    }
    in.close();

    nameList.sort();

    std::ofstream sorted("sorted_names.txt");
    for (const auto& name : nameList) {
        sorted << name.first << " " << name.last << "\n";
    }
    sorted.close();

    return 0;
}
