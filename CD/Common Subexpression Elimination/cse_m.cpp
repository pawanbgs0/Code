#include "cse.h"

// main function

int main()
{
    string file_name_with_ext;
    string input;
    vector<vector<int>> to_compare;
    vector<int> temp;

    cout << "Enter the File name with extension: ";
    cin >> file_name_with_ext;

    input = file_read(file_name_with_ext);
    auto res = make_tokens(input);

    auto all_common = all_possible_common_substring(res);

    auto beautified = beautify_common_subexpressions(all_common);

    for (auto &it: beautified)
        cout << it << endl;

    append_file(file_name_with_ext, beautified);
    return 0;
}