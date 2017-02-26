#include<iostream>
#include<vector>

using namespace std;

int main(){
	vector<int>t[3]; //three towers A,B,C represented as an array of 3 vectors
	int n,candidate,to,from,move=0;

	    cout<<"Please enter an ODD numnberm of rings to move: ";
	    cin>>n;
	    cout<<endl;

   //initializing the 3 towers
   for(int i=n+1;i>=1;i--)
	t[0].push_back(i);
	t[1].push_back(n+1);
	t[2].push_back(n+1);

   //initialize towers and candidates
   	from=0;
	if((n%2)==1) to=1;
             else to=2;
	candidate=1;

while(t[1].size()<n+1){
	t[to].push_back(t[from].back());
        t[from].pop_back();
	cout<<"move number "<<++move<<": Transfer ring"<< candidate<<"from tower"<< char(from+65)<<" to tower "<<char(to+65)<<endl;

	//If there is/are odd number(s) of ring(s)
	if(n%2==1){
            if(t[(to+1)%3].back() < t[(to+2)%3].back())
                from=(to+1)%3;
            else
                from=(to+2)%3;

	//get next "to tower"
	if(t[(from)].back() < t[(from+1)%3].back())
	    to=(from+1)%3;
	    else to=(from+2)%3;

	//get next candidate
	candidate=(t[from].back()); 
        } else {
            if(t[(to+1)%3].back() < t[(to+2)%3].back())
                from=(to+1)%3;
            else
                from=(to+2)%3;

	//get next "to tower"
	if(t[(from)].back() < t[(from+2)%3].back())
                to=(from+2)%3;
            else
                to=(from+1)%3;
	
	//get next candidate
	candidate=(t[from].back());
        }
    }
    return 0;
}
