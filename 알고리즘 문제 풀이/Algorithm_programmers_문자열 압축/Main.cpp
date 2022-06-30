#include <string>
#include <vector>
#include <iostream>
using namespace std;

int main() {

	string s;
	getline(cin, s);

    int answer = s.length();

    for (int size = 1; size <= s.length() / 2; size++) {
        string new_s;
        string before = "\n";
        int cnt = 1;

        for (int idx = 0; idx < s.length(); idx += size) {
            string s_tmp = s.substr(idx, size);
            //cout << s_tmp << endl;

            // Ã³À½ ÅÏÀÌ ¾Æ´Ò ¶§
            
            if (before.compare("\n") != 0) {
                if (before.compare(s_tmp) == 0) {
                    cnt++;
                    //cout << "cnt: " << cnt << endl;
                }
                else {
                    if(cnt != 1)
                        new_s += to_string(cnt);
                    new_s += before;
                    cnt = 1;
                }
            }

            if (idx + size >= s.length()) {
                if (cnt != 1)
                    new_s += to_string(cnt);
                new_s += s_tmp;
            }

            before = s_tmp;
        }

        //cout << new_s << endl;

        if (answer > new_s.length()) {
            answer = new_s.length();
        }
    }

    cout << answer << endl;
}
