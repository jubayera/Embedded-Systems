#include <iostream>
#include <iomanip>      // std::setw

using namespace std;

void basic_pointer()
{
	char ch = 'Q';
	char* p = &ch; //p holds the address of ch
	cout << *p; //outputs the character 'Q'
	ch = 'Z'; //ch now holds 'Z'
	cout << *p; //outputs the character 'Z'
	*p = 'X'; //ch now holds 'X'
	cout << ch; //outputs the character 'X'
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
