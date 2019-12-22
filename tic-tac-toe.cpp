#include<iostream>
#include<conio.h>
#include<math.h>
#include<iomanip>
#include<cstdlib>
using namespace std;
char arr[]={'#',' ',' ',' ',' ',' ',' ',' ',' ',' '};
char pl1;
char pl2;
char mark;

bool win(){
	if(mark=='X'||mark=='O'){
		if(arr[1]==mark&&arr[2]==mark&&arr[3]==mark)
		return true;
		else if (arr[4]==mark&&arr[5]==mark&&arr[6]==mark)
		return true;
		else if (arr[7]==mark&&arr[8]==mark&&arr[9]==mark)
		return true;
		else if(arr[1]==mark&&arr[4]==mark&&arr[7]==mark)
		return true;
		else if (arr[2]==mark&&arr[5]==mark&&arr[8]==mark)
		return true;
		else if(arr[3]==mark&&arr[6]==mark&&arr[9]==mark)
		return true;
		else if(arr[7]==mark&&arr[5]==mark&&arr[3]==mark)
		return true;
		else if(arr[1]==mark&&arr[5]==mark&&arr[9]==mark)
		return true;

	else
		return false;	
	}
}
int turn_change(int turn){
	if(turn==1)
	return 0;
	else if(turn==0)
	return 1;
}

void display()
{
	cout<<" "<<arr[7]<<" "<<"|"<<" "<<arr[8]<<" "<<"|"<<" "<<arr[9]<<" \n";	
	cout<<"---|---|---\n";
	cout<<" "<<arr[4]<<" "<<"|"<<" "<<arr[5]<<" "<<"|"<<" "<<arr[6]<<" \n";
	cout<<"---|---|---\n";
	cout<<" "<<arr[1]<<" "<<"|"<<" "<<arr[2]<<" "<<"|"<<" "<<arr[3]<<" ";
}

bool is_empty_pos(int pos){
	if(arr[pos]==' '){
		return true;
	}
	else{
		return false;
	}
}

bool is_board_full(){
	int c=0;
	for(int i=1;i<=9;i++)
		if(arr[i]!=' ')
			c+=1;
	for(int i=1;i<=9;i++){
		if(is_empty_pos(i)||c<9){
			return false;
		}
		else
		return true;
		}	
	}
void move(int turn){
		int pos;
		if(turn==1)
		{
			cout<<"Enter the position-->>";
			cin>>pos;
			if(pos<=9&&pos>0){
				mark=pl1;
				if(is_empty_pos(pos)){
					arr[pos]=mark;
				}
	
			else{
				cout<<"Position not empty!\n\n";	
				move(turn);
				}
			}
			else{
			cout<<"Wrong Input!\n\n";
			move(turn);
			}
		}
		else if(turn==0)
		{
		cout<<"Enter the position-->>";
			cin>>pos;
			if(pos<=9&&pos>0){
				mark=pl2;
				if(is_empty_pos(pos)){
					arr[pos]=mark;
				}
	
			else{
				cout<<"Position not empty!\n\n";	
				move(turn);
				}
			}
			else{
			cout<<"Wrong Input!\n\n";
			move(turn);
			}
		}

}

int main(){
		for(int i=1;i<=9;i++)
			arr[i]=' ';
		cout<<"<-------WELCOME TO TIC TAC TOE!------->\n\n";
		cout<<"Player 1 choose the symbol (X/O)>-->>";
		cin>>pl1;
		while(pl1!='X'&&pl1!='x'&&pl1!='O'&&pl1!='o'){
			cout<<"Player 1 choose the symbol (X/O)-->>";
			cin>>pl1;
		}
		pl1=toupper(pl1);
		if(pl1=='X'){
			pl2='O';
		}
		else{
			pl2='X';
		}
		int turn=1;
		while(1){
		move(turn);
		system("cls");
		cout<<"\n\n";
		display();
		cout<<"\n\n";
		if(win()){
			if(turn==1){
					cout<<"Congratulations!!!!....Player 1 Wins!!..\n\n";
					char c;
					cout<<"WANT TO REPLAY??(Y/N)-->>";
					cin>>c;
					if(c=='y'||c=='Y')
						main();
					else if(c=='n'||c=='N')
						return 0;
					else
						return 0;
					break;
			
				}
			else{
					cout<<"Congratulations!!!!....Player 2 Wins!!..\n\n";
					char c;
					cout<<"WANT TO REPLAY??(Y/N)-->>";
					cin>>c;
					if(c=='y'||c=='Y')
						main();
					else if(c=='n'||c=='N')
						return 0;
					else
						return 0;
					break;
				}
		}
		else if(is_board_full()){
			char c;
			cout<<"MATCH TIE!!!\n\n";
			cout<<"WANT TO REPLAY??-->>(Y/N)";
			cin>>c;
			if(c=='y'||c=='Y')
				main();
			else if(c=='n'||c=='N')
				return 0;
			else
				return 0;
			break;
		}
		turn=turn_change(turn);
		}
		return 0;
}
