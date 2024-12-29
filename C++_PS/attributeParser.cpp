#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    cin.ignore(); // Ignore the newline after the integer input

    unordered_map<string, string> hrml_map; // To store the tag-attribute map
    vector<string> tag_stack;              // To maintain the nesting hierarchy

    for (int i = 0; i < n; ++i) {
        string line;
        getline(cin, line);

        if (line[1] == '/') { // Closing tag
            tag_stack.pop_back();
        } else { // Opening tag
            stringstream ss(line);
            string tag, attr_name, attr_value;
            char temp;

            ss >> temp >> tag; // Read '<' and tag name
            tag.pop_back();    // Remove '>' if present

            // Construct full tag path
            string full_tag = tag_stack.empty() ? tag : tag_stack.back() + "." + tag;
            tag_stack.push_back(full_tag);

            // Parse attributes
            while (ss >> attr_name) {
                if (attr_name == ">") break; // End of tag
                ss >> temp >> attr_value;   // Read '=' and attribute value
                attr_value.pop_back();      // Remove trailing '>' if present
                attr_value = attr_value.substr(1, attr_value.size() - 2); // Remove quotes
                hrml_map[full_tag + "~" + attr_name] = attr_value;
            }
        }
    }

    for (int i = 0; i < q; ++i) {
        string query;
        getline(cin, query);

        if (hrml_map.find(query) != hrml_map.end()) {
            cout << hrml_map[query] << endl;
        } else {
            cout << "Not Found!" << endl;
        }
    }

    return 0;
}
