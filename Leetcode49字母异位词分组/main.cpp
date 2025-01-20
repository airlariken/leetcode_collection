#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    // TIP Press <shortcut actionId="RenameElement"/> when your caret is at the
    // <b>lang</b> variable name to see how CLion can help you rename it.
    // auto lang = "C++";
    // std::cout << "Hello and welcome to " << lang << "!\n";

    map<string, vector<string>> maps;

    vector<vector<string>> res;
    for (auto & str : strs) {
        string t_str = str;
        sort(t_str.begin(), t_str.end());
        maps[t_str].emplace_back(str);
        // TIP Press <shortcut actionId="Debug"/> to start debugging your code.
        // We have set one <icon src="AllIcons.Debugger.Db_set_breakpoint"/>
        // breakpoint for you, but you can always add more by pressing
        // <shortcut actionId="ToggleLineBreakpoint"/>.
    }

    for (const auto& it : maps)
        res.push_back(it.second);

    for (const auto& it : res) {
        for (const auto& str : it)
            cout<<str<<'\t';
        cout<<endl;
    }

    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.