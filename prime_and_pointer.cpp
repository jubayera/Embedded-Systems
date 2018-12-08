#include <iostream>
#include <iomanip>      // std::setw

using namespace std;

enum Level {INITIAL, INTERMEDIATE, EXPERT};

struct Passenger {

	string name; //passenger name
	Level pref_level;
	bool isFreqFlyer;
	string freqFlyerNo;

};

void flyer_Pointer(void)
{
	Passenger *p;
	p = new Passenger;
	p->name = "Jubayer";
	p->pref_level = EXPERT;
	p->isFreqFlyer = false;
	p->freqFlyerNo = "65899";
}

void flyerOperation_struct(void)
{
	Passenger pass = {"Jubayer", EXPERT, true, "29856"};
}

void basic_pointer()
{
	char ch = 'Q';
	char* p = &ch; //p holds the address of ch
	cout << *p; //outputs the character 'Q'
	ch = 'Z'; //ch now holds 'Z'
	cout << *p; //outputs the character 'Z'
	*p = 'X'; //ch now holds 'X'
	cout << ch; //outputs the character 'X'

	char c[] = {'a', 'r', 't', 's'};
	char* p_c = c; //p points to c[0]
	char* q = &c[0]; //q also points to c[0]
	cout << c[2] << p_c[2] << q[2];
}

int main()
{
    int num,i,count,n;
    cout << "Enter max range: ";
    cin >> n;
    for(num = 1;num<=n;num++)
    {
        count = 0;
        for(i=2;i<=num/2;i++){
            if(num%i==0){
                count++;
                break;
            }
        }

        if(count==0 && num!= 1)
            cout << num << setw(3);
    }

    basic_pointer();

    return 0;
}
