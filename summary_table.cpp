/*
 * summary_table
 * Reads the input stream (single ended fastq) and reports the most frequent DNA fragments.
 * usable for QC of barcodes (sample barcodes, cellular barcode) in scRNA-seq
 * compiled with gcc >= 4.8.5
 * usage: 
 * gunzip -c data/test.R3.fq.gz | summary_table > data/test.R3.table.csv 2> messages.txt
 * head data/file.R3.table.csv
 * cat messages.txt 
 */

#include <iostream>
#include <string>
#include <map>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <chrono>
#include <iomanip>
#include <ctime>

using namespace std;
using namespace std::chrono;

int main(int argc, char* argv[])
{
	auto start = steady_clock::now();
	string s_read;
	map <string, int> frequency;
	map <string, int> ::iterator it;
	int i = 0;
	while(!cin.eof()){ 
		getline(cin, s_read);

		if (i % 4 == 1){
			try{
				frequency.at(s_read)++;
			}
			catch(const out_of_range& oor){
				frequency.insert(pair<string, int>(s_read, 1));
			}			
		}
		i++;
	}
	int total_reads = i-1;
	

	vector<pair<string, int>> pairs;

	for(auto itr = frequency.begin(); itr != frequency.end(); itr++)
		pairs.push_back(*itr);

	sort(pairs.begin(), pairs.end(), [=](const pair<string, int>& a, const pair<string, int>& b ){return a.second > b.second;});


	cout<<"read,count,frequency"<<endl;
	for (auto itr = pairs.begin(); itr != pairs.end(); itr++)
		cout << itr->first << "," << itr->second << "," << setprecision(5) << 1.0 * itr->second/total_reads << endl;

   
	auto end = steady_clock::now();
	auto duration = end - start;
    auto h = duration_cast<hours>(duration);
    auto m = duration_cast<minutes>(duration - h);
    auto s = duration_cast<seconds>(duration - m);
        
    tm t{};
   
    t.tm_hour = h.count();
    t.tm_min  = m.count();
    t.tm_sec = s.count();

    // put_time is not supported till gcc5
    //cerr << "I found " << frequency.size() << " barcodes in " << total_reads << " reads in " << put_time(&t, "%H:%M:%S") << endl;
    cerr << "I found " << frequency.size() << " barcodes in " << total_reads << " reads in " << t.tm_hour<<":"<< t.tm_min<<":"<<t.tm_sec << " (H:M:S)" <<endl;

	return 0;
}
