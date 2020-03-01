#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

map<int,int> rot1 = { {1,7}, {2,4}, {3,1}, {4,8}, {5,5}, {6,2}, {7,9}, {8,6}, {9,3}};
map<int,int> rot2 = { {1,9}, {2,8}, {3,7}, {4,6}, {5,5}, {6,4}, {7,3}, {8,2}, {9,1}};
map<int,int> rot3 = { {1,3}, {2,6}, {3,9}, {4,2}, {5,5}, {6,8}, {7,1}, {8,4}, {9,7}};

vector<int> rotate_puzzle(vector<int> v, int num);
vector<int> moved_puzzle(vector<int> v, int dir, int num);

bool vertical_check(vector<int> v, vector<int> vv);
bool horizontal_check(vector<int> v, vector<int> vv, bool dir3, bool dir33, bool dir4, bool dir44);
bool compare(vector<int> full, vector<int> blank);

int main(){

	char p1[3][3], p2[3][3];
	int n=0;
	vector<int> full1, full2;
	vector<int> blank1, blank2;
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			cin>>p1[i][j];
			if(p1[i][j]=='*'){
				n++;
				full1.push_back(i*3+j+1);
			}
			else{
				blank1.push_back(i*3+j+1);
			}
		}
	}
	
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			cin>>p2[i][j];
			if(p2[i][j]=='*'){
				n++;
				full2.push_back(i*3+j+1);
			}
			else{
				blank2.push_back(i*3+j+1);
			}
		}
	}
	if(n != 9){
		cout<<"NO"<<endl;
		return 0;
	}

	// fix 1
	if(compare(full2, blank1)==0)	return 0;

	// fix 2
	if(compare(full1, blank2)==0)	return 0;

	cout<<"NO"<<endl;
	return 0;	
}

vector<int> rotate_puzzle(vector<int> v, int num)
{
	map<int,int> rot;
	vector<int> v_rot;

	if(num==1){
		for(int i=0; i<v.size(); i++){
			v_rot.push_back(rot1[v[i]]);
		}
	}
	else if(num==2){
		for(int i=0; i<v.size(); i++){
			v_rot.push_back(rot2[v[i]]);
		}
	}
	else{
		for(int i=0; i<v.size(); i++){
			v_rot.push_back(rot3[v[i]]);
		}
	}
	
	sort(v_rot.begin(), v_rot.end());
	return v_rot;
}

vector<int> moved_puzzle(vector<int> v, int dir, int num){
	vector<int> moved;
	if(dir==1 && (num==1||num==2)){
		for(int i=0; i<v.size(); i++){
			moved.push_back(v[i]-3*num);
		}
	}
	else if(dir==2 && (num==1||num==2)){
		for(int i=0; i<v.size(); i++){
			moved.push_back(v[i]+3*num);
		}
	}
	else if(dir==3 && (num==1||num==2)){
		for(int i=0; i<v.size(); i++){
			moved.push_back(v[i]-1*num);
		}
	}
	else if(dir==4 && (num==1||num==2)){
		for(int i=0; i<v.size(); i++){
			moved.push_back(v[i]+1*num);
		}
	}
	return moved;
}

bool vertical_check(vector<int> v, vector<int> vv)
{
	bool dir1=1, dir11=1, dir2=1, dir22=1, dir3=1, dir33=1, dir4=1, dir44=1;
	for(int i=0; i<v.size(); i++){
		if(v[i]-3<=0)	dir1=0; //cannot move
		if(v[i]-6<=0)	dir11=0;
		if(v[i]+3>=10)	dir2=0;
		if(v[i]+6>=10)	dir22=0;
		if(v[i]==1 || v[i]==4 || v[i]==7)	dir3=0;
		if(dir3==0)	dir33=0;
		if(v[i]==2 || v[i]==5 || v[i]==8)	dir33=0;
		if(v[i]==3 || v[i]==6 || v[i]==9)	dir4=0;
		if(dir4==0)	dir44=0;
		if(v[i]==2 || v[i]==5 || v[i]==8)	dir44=0;
	}
	vector<int> v_moved;
	if(dir1==1){
		v_moved=moved_puzzle(v, 1, 1);
		if(vv == v_moved){
			cout<<"YES"<<endl;
			return 0;
		}
		if(horizontal_check(v_moved, vv, dir3, dir33, dir4, dir44)==0)	return 0;
	}
	if(dir11==1){
		v_moved=moved_puzzle(v, 1, 2);
		if(vv == v_moved){
			cout<<"YES"<<endl;
			return 0;
		}
		if(horizontal_check(v_moved, vv, dir3, dir33, dir4, dir44)==0)	return 0;
	}
	if(dir2==1){
		v_moved=moved_puzzle(v, 2, 1);
		if(vv == v_moved){
			cout<<"YES"<<endl;
			return 0;
		}
		if(horizontal_check(v_moved, vv, dir3, dir33, dir4, dir44)==0)	return 0;
	}
	if(dir22==1){
		v_moved=moved_puzzle(v, 2, 2);
		if(vv == v_moved){
			cout<<"YES"<<endl;
			return 0;
		}
		if(horizontal_check(v_moved, vv, dir3, dir33, dir4, dir44)==0)	return 0;
		
	}

	if(horizontal_check(v, vv, dir3, dir33, dir4, dir44)==0)	return 0;

	return 1;
}

bool horizontal_check(vector<int> v, vector<int> vv, bool dir3, bool dir33, bool dir4, bool dir44)
{
	vector<int> v_moved2;
	if(dir3==1){
		v_moved2=moved_puzzle(v, 3, 1);
		if(vv == v_moved2){
			cout<<"YES"<<endl;
			return 0;
		}
	}
	if(dir33==1){
		v_moved2=moved_puzzle(v, 3, 2);
		if(vv == v_moved2){
			cout<<"YES"<<endl;
			return 0;
		}
	}
	if(dir4==1){
		v_moved2=moved_puzzle(v, 4, 1);
		if(vv == v_moved2){
			cout<<"YES"<<endl;
			return 0;
		}
	}
	if(dir44==1){
		v_moved2=moved_puzzle(v, 4, 2);
		if(vv == v_moved2){
			cout<<"YES"<<endl;
			return 0;
		}
	}
	return 1;
}

bool compare(vector<int> full, vector<int> blank)
{
	sort(blank.begin(), blank.end());
	sort(full.begin(), full.end());
	if(blank == full){
		cout<<"YES"<<endl;
		return 0;
	}
	if(vertical_check(full, blank)==0)	return 0;

	//rot
	vector<int> full_rot1, full_rot2, full_rot3;

	full_rot1 = rotate_puzzle(full, 1);
	if(full_rot1==blank){
		cout<<"YES"<<endl;
		return 0;
	}
	if(vertical_check(full_rot1, blank)==0)	return 0;

	full_rot2 = rotate_puzzle(full, 2);
	if(full_rot2==blank){
		cout<<"YES"<<endl;
		return 0;
	}
	if(vertical_check(full_rot2, blank)==0)	return 0;

	full_rot3 = rotate_puzzle(full, 3);
	if(full_rot3==blank){
		cout<<"YES"<<endl;
		return 0;
	}
	if(vertical_check(full_rot3, blank)==0)	return 0;

	return 1;
}


