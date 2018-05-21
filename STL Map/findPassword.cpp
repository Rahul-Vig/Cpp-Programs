#include<iostream>
#include<map>
#include<vector>

using namespace std;

int main(){

	vector<string> in{"011", "0111", "01110", "111", "0111", "10111"};
	//vector<string> in{"10","0111","100","111","1","00111"};

	int num_frags=in.size();
	cout << "Num Frags: " << num_frags << endl;
	int num_bits=0;
	for(string i:in)
		num_bits+=i.length();

	cout << "Num Bits: " << num_bits << endl;
	int num_files=num_frags/2;

	cout << "Num Files: " << num_files << endl;

	int file_size=num_bits/num_files;

	cout << "File Size: " << file_size << endl;

	map<string, int> d;
	for(string i:in){
		cout << "i: " << i << endl;
		for(string j:in){
			cout << "j: " << j << endl;
			string s=i+j;
			if (s.size()==file_size){
			cout << "s: "<<s << endl;
				if(d.find(s)==d.end())
					d[s]=1;
				else
					d[s]++;
	   }
		}
	}

	// find the max element of the map
	int max=0;
	string val;
	for (auto i:d){  // i is a pair
    	cout<<i.first<<" appears: "<<i.second<<" times."<<endl;
    	if(i.second>max){
    		val=i.first;
    		max=i.second;
    	}
    }
    cout<<"The secret string is: "<<val<<endl;

}
