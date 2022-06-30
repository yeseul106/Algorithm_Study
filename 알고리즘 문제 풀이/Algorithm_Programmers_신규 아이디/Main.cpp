#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    
     string answer = "";
    
    	while (true) {

		for (int i = 0; i < new_id.length(); i++) {

			char now_ch = new_id[i];

			// 1) 대문자 소문자로 치환
			if ('A' <= now_ch && now_ch <= 'Z')
				new_id[i] = tolower(now_ch);
			else {
				// 2) 기타 문자 제외
				if (!(('a' <= now_ch && now_ch <= 'z') || ('0' <= now_ch && now_ch <= '9')
					|| now_ch == '-' || now_ch == '_' || now_ch == '.')) {
					new_id.erase(new_id.begin() + i);
					i--;
				}
			}
		}
        bool two_end = false;
        // 3) 마침표가 2번 이상 연속된다면 하나의 마침표로 치환
        for (int i=0; i< new_id.length(); i++) {
            if (new_id[i] == '.') {
                if (two_end) {
                    new_id.erase(new_id.begin() + i);
                    i--;
                }
                else
                    two_end = true;
            }
            else {
                if(two_end) {
                    two_end = false;
                }
            }
        }    
            
		// 4) 마침표가 처음이나 끝에 위치
		if (new_id[0] == '.')
			new_id = new_id.substr(1, new_id.length()-1);
		if(new_id[new_id.length()-1] == '.')
			new_id = new_id.substr(0, new_id.length()-1);

		break;
	}

	// 5) 빈 문자열이라면 new_id에 "a"를 대입하기
	if (new_id.empty()) {
		new_id = "a";
	}

	// 6) new_id 길이가 16자 이상
	if (new_id.length() >= 16) {
		new_id = new_id.substr(0, 15);
    
    while(new_id[new_id.length() - 1]=='.') {
           if(new_id[new_id.length() - 1]=='.')
			        new_id = new_id.substr(0, new_id.length() - 1);
    }
	}
	else if (new_id.length() <= 2) {
		while (new_id.length() < 3) {
			new_id+= new_id[new_id.length() - 1];
		}
	}
    
    answer = new_id;
    
    return answer;
}
