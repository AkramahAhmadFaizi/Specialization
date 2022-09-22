#include<iostream>
#include<fstream>
#include<string>
#include<set>
#include<sstream>

using namespace std;

int main()
{
	ifstream file;
	ofstream file2;
	set<string> st;
	file.open("sespecialization.txt");
	file2.open("uniquese.txt");
	if (file2.is_open())
		cout << "file2 opened properly"<<endl;
	else
		cout << "file2 not opened"<<endl;
	if (file.is_open())
	{
		string data;
		string line;
		int count=0;
		while (file.good())
		{
			file >> data;
			
			if (data == "Specialization:")
			{
				getline(file, line);
				stringstream ss(line);
				while (ss.good())
				{
					string substr;	
					ss.seekg(1, ios::cur);
					getline(ss, substr, ',');
					/*file2 << substr << endl;*/
					cout << substr << endl;
					st.insert(substr);
					count++;
				}

			}

		}
		cout << count << endl;
		file.close();
	}
	else
		cout << "file did not open properly";
	int count = 0;
	for (auto sts : st)
	{
		file2 << sts << endl;
		count++;
	}
	cout << count << endl;
	file2.close();
}