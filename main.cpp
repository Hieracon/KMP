#include <iostream>
#include <string>

using namespace std;

int *determine_lps(string pattern){
	int size = pattern.length();
	static int *lps = new int [size];
	lps[0] = 0;
	int k=0;

	for(int i = 1; i < size; ++i){
        while(k>0 && pattern[k] != pattern[i] ){
			k = lps[k-1];
		}

		if( pattern[k] == pattern[i] ){
			k=k+1;
		}

		lps[i]=k;
	}
	return lps;
}

void kmp(string text, string pattern){
	int *lps = determine_lps(pattern);
	int matched_pos = 0;

	for(int it = 0; it < text.length(); ++it){
		while(matched_pos > 0 && pattern[matched_pos] != text[it]){
			matched_pos = lps[matched_pos - 1];
		}

		if(pattern[matched_pos] == text[it]){
			matched_pos = matched_pos + 1;
		}

		if(matched_pos == pattern.length()){
			cout << "Pattern found at position " << it - (pattern.length() - 1) << endl;
			matched_pos = lps[matched_pos - 1];
		}
	}
}

int main(){
	string text;
	string pattern;

        cout << "Insert text:";
        cin >> text;
        cout << "Insert pattern:";
        cin >> pattern;

        kmp(text, pattern);

	return 0;
}
