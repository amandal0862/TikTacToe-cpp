#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

char space[3][3] = {{'1','2','3'}, {'4','5','6'}, {'7','8','9'}};
int row,column;
string n1="Player 1", n2="Player 2";
char token = 'x';
bool draw = false;

void display_board() {
	
	cout<<"       |       |       \n";
	cout<<"   "<<space[0][0]<<"   |   "<<space[0][1]<<"   |   "<<space[0][2]<<"   \n";
	cout<<"_______|_______|_______\n";
	cout<<"       |       |       \n";
	cout<<"   "<<space[1][0]<<"   |   "<<space[1][1]<<"   |   "<<space[1][2]<<"   \n";
	cout<<"_______|_______|_______\n";
	cout<<"       |       |       \n";
	cout<<"   "<<space[2][0]<<"   |   "<<space[2][1]<<"   |   "<<space[2][2]<<"   \n";
	cout<<"       |       |       \n";
}
void player_turn(){
	int digit;
	
	if(token=='x'){
		cout<<n1<<" please enter : ";
	}
	if(token == '0'){
		cout<<n2<<" please enter :  ";
	}
	cin>>digit;
	
	if(digit==1){
		row=0;
		column=0;
	}
	if(digit==2){
		row=0;
		column=1;
	}
	if(digit==3){
		row=0;
		column=2;
	}
	if(digit==4){
		row=1;
		column=0;
	}
	if(digit==5){
		row=1;
		column=1;
	}
	if(digit==6){
		row=1;
		column=2;
	}
	if(digit==7){
		row=2;
		column=0;
	}
	if(digit==8){
		row=2;
		column=1;
	}
	if(digit==9){
		row=2;
		column=2;
	}
	else if(digit<1 && digit>9){
		cout<<"Invalid entry !!!"<<endl;
	}
	if(token == 'x' && space[row][column] != 'x' && space[row][column] != '0'){
		space[row][column] = 'x';
		token = '0';
	}
	else if(token == '0' && space[row][column] != '0' && space[row][column] != 'x'){
		space[row][column] = '0';
		token = 'x';
	}
	else{
		cout<<"There is no empty space !"<<endl;
		player_turn();
	}
	display_board();
}
bool gameover(){
	for(int i=0; i<3; i++){
		if(space[i][0] == space[i][1] && space[i][0] == space[i][2] || space[0][i] == space[1][i] && space[1][i] == space[2][i])
			return false;
	}
	if(space[0][0] == space[1][1] && space[1][1] == space[2][2] || space[0][2] == space[1][1] && space[1][1] == space[2][0]){
		return false;
	}	
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			if(space[i][j] != 'x' && space[i][j] != '0'){
				return true;
			}
		}
	}
	draw = true;
	return false;
}
int main(){
// 	cout<<"Enter the name of first player : "<<endl;
// 	getline(cin, n1);
// 	cout<<"Enter the name of second player : "<<endl;
// 	getline(cin, n2);
	cout<<n1<<" is player1 so they will play first"<<endl;
	cout<<n2<<" is player2 so they will play second"<<endl;
	
	while(gameover()){
		display_board();
		player_turn();
		gameover();
	}
	if(token == 'x' && draw == false){
	    cout<<n1<<" Wins !!"<<endl;
	}
	else if(token == '0' && draw == false){
		cout<<n2<<" Wins !!"<<endl;
	}
	else{
		cout<<"Its a draw !"<<endl;
	}
}