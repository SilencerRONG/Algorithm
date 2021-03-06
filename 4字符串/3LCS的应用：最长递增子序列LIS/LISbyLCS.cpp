#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::max;
using std::sort;

void LCS(string &str1, string &str2, string &str){
	int size1 = str1.length();
	int size2 = str2.length();
	vector<vector<int> > chess(size1+1, vector<int>(size2+1));
	for(int i = 0; i <= size1; i++){ //第0列
		chess[i][0] = 0;
	}
	for(int j = 0; j <= size2; j++){ //第0行
		chess[0][j] = 0;
	}

	for(int i = 1; i <= size1; i++){
		for(int j = 1; j <= size2; j++){
			if(str1[i-1] == str2[j-1]){
				chess[i][j] = chess[i-1][j-1] + 1;
			}else{
				chess[i][j] = max(chess[i][j-1], chess[i-1][j]);
			}
		}
	}

	int i = size1;
	int j = size2;
	while( (i != 0) && (j != 0)){
		if(str1[i-1] == str2[j-1]){
			str.push_back(str1[i-1]);
			i--;
			j--;
		}else{
			if(chess[i][j-1] > chess[i-1][j]){  //不妨假设chess[i][j]来自top
				j--;
			}else{
				i--;
			}
		}
	}
    reverse(str.begin(), str.end());
}

int main(){
	string str1 = "567128";
	string str2 = str1;
	sort(str2.begin(), str2.end());
	string str;
	LCS(str1, str2, str);
	cout << str.c_str() << endl;    //LCS可能不唯一
	//cout << str << endl;
	return 0;
}
