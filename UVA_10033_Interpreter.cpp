Solution 1:
--------------
#include<cstdio>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
string memory[1010];

string _register[15];
int actual_memory[1010];

int convert_to_int(string& s){
	int i = 0;
	int result = 0;
	while(s.size() > i){
		result = (result * 10) + (s[i] - '0'); 
		++i;
	}
	return result;
}

void convert_to_char(string &s, int i){
	s[0] = ((i /100)) + '0';
	s[1] = ((i % 100)/10) + '0';
	s[2] = ((i % 100)%10) + '0';
}
int main(){
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int N;
	scanf("%d\n\n", &N);
	string demo = "100";
	int n;
	n = convert_to_int(demo);
	for(int i = 0; i < N; ++i){
		int instruction = 0;
		int j = 0;
		//memset(actual_memory, 0, sizeof(actual_memory));
		if(i > 0) printf("\n");
		for(int l = 0; l < 10; ++l){
			// _register[l][0] = '0';
			// _register[l][1] = '0';
			// _register[l][2] = '0';
			// _register[l][3] = '/0';
			_register[l] = "000";
		}
		for(int l = 0; l < 1000; ++l){
			// memory[l][0] = '0';
			// memory[l][1] = '0';
			// memory[l][2] = '0';
			// memory[l][3] = '/0';
			memory[l] = "000";		
		}
		//memset(_register, 0, sizeof(_memory));
		while(getline(cin, memory[j]) && !memory[j].empty()){ 
		// int primero, segundo, tercero;
		// primero = memory[j][0] - '0';
		// second = memory[j][1]- '0';
		// tercero = memory[j][2] - '0';
		// actual_memory[j] = primero * 100 + segundo * 10; 
		// tercero;
		++j; 
		}
		bool done = false;
		int k = 0;
		int temp;
		while(!done)
		{
			int start = memory[k][0] - '0';
			int first = memory[k][1] - '0';
			int second = memory[k][2] - '0';
			switch(start){
				case 1:
					if(convert_to_int(memory[k]) == 100){
						instruction++;
						done = true;
					}
					else{
						instruction++;
						++k;
					}
				break;
				case 2:
					convert_to_char(_register[first], second);
					++instruction;
					++k;
				break;
				case 3:
					temp = (convert_to_int(_register[first])+ second) % 1000;
					convert_to_char(_register[first], temp); 
					++instruction;
					++k;
				break;
				case 4:
					temp = (convert_to_int(_register[first]) * second) % 1000;
					convert_to_char(_register[first], temp) ; 
					++instruction;
					++k;
				break;
				case 5:
					_register[first] = _register[second];
					++instruction;
					++k;
				break;
				case 6:
					temp = ((convert_to_int(_register[first]) + convert_to_int(_register[second]))% 1000);
					convert_to_char(_register[first],temp);
					++instruction;
					++k;
				break;
				case 7:
					temp = ((convert_to_int(_register[first]) * convert_to_int(_register[second]))% 1000);
					convert_to_char(_register[first],temp);
					++instruction;
					++k;
				break;
				case 8:
					_register[first] = memory[convert_to_int(_register[second])];
					++instruction;
					++k;
				break;
				case 9:
					memory[convert_to_int(_register[second])] = _register[first];
					++instruction;
					++k;
				break;
				case 0:
					if(convert_to_int(_register[second]) != 0){
						k = convert_to_int(_register[first]);
						++instruction;
					}
					else{
						instruction++;
						++k;
					}
				break;
				}
		}
		printf("%d\n", instruction);
	}
	
	return 0;
}


//Solution 2:

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;
 
int StoI(string s)
{
    int R;
    R = (s[0] - '0')*100;
    R += (s[1]- '0')*10;
    R += (s[2]- '0');
    return R;
}
 
string ItoS(int I)
{
    string R = "000";
    R[2] = I%10 + '0';
    I /= 10;
    R[1] = I%10 + '0';
    I /= 10;
    R[0] = I%10 + '0';
 
    return R;
}
int main()
{
    int N, nCommands;
    char C1, C2, C3;
    char d, n,s,a;
    char instr[5];
 
    scanf("%d", &N);
    fgets(instr, sizeof(instr), stdin);
    fgets(instr, sizeof(instr), stdin);
 
    bool exit = false;
    string RAM[1000];
    string Ts;
    vector<int>Results;
    int PC;
 
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<1000; j++) RAM[j] = "000";
        PC=0;
 
        while(fgets(instr, sizeof(instr), stdin) != NULL)
        {
 
            if (instr[0] == '\n') break;
 
            RAM[PC][0] = instr[0];
            RAM[PC][1] = instr[1];
            RAM[PC++][2] = instr[2];
 
        }
 
        string Registers[10];
        int T;
        for (int j=0; j<10; j++) Registers[j] = "000";
        nCommands =0;
        exit = false;
        PC=0;
    while(!exit)
    {
        nCommands++;
            switch(RAM[PC][0])
            {
                case '1':
                    exit = true;
                    PC++;
                break;
 
                case '2':
                    d = RAM[PC][1];
                    n = RAM[PC][2];
 
                    Registers[d - '0'] =  ItoS(n - '0');
                    PC++;
 
                break;
 
                case '3':
                    d = RAM[PC][1];
                    n = RAM[PC][2];
 
                    Registers[d - '0'] = ItoS((StoI(Registers[d - '0']) + (n - '0'))%1000);
                    PC++;
                break;
 
                case '4':
                    d = RAM[PC][1];
                    n = RAM[PC][2];
                    Registers[d - '0'] = ItoS((StoI(Registers[d - '0'])*(n - '0'))%1000);
                    PC++;
                break;
 
                case '5':
                    d = RAM[PC][1];
                    s = RAM[PC][2];
                    Registers[d - '0'] = Registers[s - '0'];
                    PC++;
                break;
 
                case '6':
                    d = RAM[PC][1];
                    s = RAM[PC][2];
                    Registers[d - '0'] = ItoS((StoI(Registers[d - '0']) + StoI(Registers[s - '0']))%1000);
                    PC++;
                break;
 
                case '7':
                    d = RAM[PC][1];
                    s = RAM[PC][2];
                    Registers[d - '0'] = ItoS((StoI(Registers[d - '0']) * StoI(Registers[s - '0']))%1000);
                    PC++;
                break;
 
                case '8':
                    d = RAM[PC][1];
                    a = RAM[PC][2];
 
                    Registers[d - '0'] = RAM[ StoI(Registers[a - '0'])];
                    PC++;
 
                break;
 
                case '9':
                    s = RAM[PC][1];
                    a = RAM[PC][2];
                    PC++;
                    RAM[StoI(Registers[a - '0'])] = Registers[s - '0'];
                break;
 
                case '0':
                    d = RAM[PC][1];
                    s = RAM[PC][2];
 
                    if (StoI(Registers[s - '0']) != 0)
                        PC = StoI(Registers[d - '0']);
                    else PC++;
                break;
 
            }
 
    }
        cout << nCommands << endl;
        if (i < N-1) cout << endl;
 
    }
 
    return 0;
}
