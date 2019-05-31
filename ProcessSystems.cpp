/* A program that finds any unknown process in linux.
 *
 * @author: Jubayer Ahmed
 * @function: UnknownProcessFinding returns a map containing process name and frequency of the process
 */

#include <iostream>
#include <unordered_map>
#include <fstream>
#include <string>

using namespace std;

unordered_map<string, int> UnknownProcessFinding(void)
{
	string line;
	string processlist_filename = "process_whitelist.txt";
	ifstream fstrm1 (processlist_filename);

	if (!fstrm1.is_open())
    	cout << "error while opening file " << processlist_filename << '\n';
	else if (fstrm1.bad())
    	cout << "error while reading file " << processlist_filename << '\n';

	unordered_map<string, int> umapWhiteListProcess;

	while(getline(fstrm1, line)) {
		umapWhiteListProcess[line] ++;
	}

	string runningprocesslist_filename = "runningProcessesInSystem.txt";
	string command = "ps -Ao \"%a\" > " + runningprocesslist_filename;

	int i = system (command.c_str());

	if(i != 0)
		perror("Could not get process list from system");
	
	ifstream fstrm2 (runningprocesslist_filename);

	if (!fstrm2.is_open())
    	cout << "error while opening file " << runningprocesslist_filename << '\n';
	else if (fstrm2.bad())
    	cout << "error while reading file " + runningprocesslist_filename << '\n';

	unordered_map<string, int> unknownProcessListMap;

	while(getline(fstrm2, line)) {

		// Declare an iterator to unordered_map
		unordered_map<string, int>::iterator it;
		// Find if an element with key exists or not.
		// find() returns an iterator
 
		it = umapWhiteListProcess.find(line);

		// Check if iterator points to end of map
		if (it != umapWhiteListProcess.end())
		{
			//cout << "Process Found - ";
			//cout << it->first << "::" << it->second << endl;
		}
		else
		{
			cout << "Process Not Found: " << line <<"\n";
			unknownProcessListMap[line] ++;
		}
	}

	return unknownProcessListMap;
}

int main()
{

	//construct map from known white list processes

	unordered_map<string, int> processListMap = UnknownProcessFinding();

	for ( auto unkown_process_it = processListMap.begin(); unkown_process_it != processListMap.end(); ++unkown_process_it )
	    	cout << " Unknown Process name: " << unkown_process_it->first << " Frequency: " << unkown_process_it->second << "\n";

	cout << "\n";

	return 0;
}

SOURCE=Tracking_Unknown_Process.cpp
MYPROGRAM=processfinder
CC=g++

all: $(MYPROGRAM)



$(MYPROGRAM): $(SOURCE)

	$(CC) -std=c++11 $(SOURCE) -o$(MYPROGRAM)

clean:

	rm -f $(MYPROGRAM)
