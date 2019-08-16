/*
*  Doing the same job as 
*  https://github.com/vals/umis/blob/master/umis/umis.py#L1256
*  but only for headers like @A00794:25:HKKFJDMXX:1:1101:1506:1000:CELL_GGGGGGGG-TATTGGCT:UMI_CTAATT:SAMPLE_TCTTTCCC
*  and (hopefully) much faster
*  usage: 
*        mkdir demultiplexed
*        gunzip -c test/umitransformed.fq.gz | demultiplex_samples sample_barcodes.csv demultiplexed 2> messages.txt
*  sample_barcodes.csv is just a list of barcodes
*  		CTCTCTAT
*  		TATCCTCT
*  		GTAAGGAG
*  		ACTGCATA
*  		AAGGAGTA
*  		CTAAGC
*  		CGTCTAAT
*  		TCTCTCCG
*  		TCGACTAG
*  		TTCTAG      
*  output
*       for each barcode creates a file demultiplexed/CTCTCTAT.fq with reads for this sample
*       also creates garbage.fq for unassigned reads          
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
#include <fstream>
#include <sstream>
#include <set>

using namespace std;
using namespace std::chrono;

string find_barcode(string s_looking_for, vector<string> v_barcodes)
{
	//
}

int main(int argc, char* argv[])
{
	auto start = steady_clock::now();
	string s_f_barcodes(argv[1]);
	string out_dir_name(argv[2]);
	string s_buf;
	cout << s_f_barcodes << " " <<out_dir_name<<endl;

	set<string> set_barcodes;
	vector<string> v_barcodes;
	map<string,ofstream> m_f_barcodes;

	ifstream f_barcodes;
	f_barcodes.open(s_f_barcodes);
	while(f_barcodes >> s_buf){
		v_barcodes.push_back(s_buf);
		m_barcodes.insert(s_buf);

		ofstream of_buf(s_buf);
		m_fof_barcodes.push_back(of_buf);
	}
	f_barcodes.close();

	string s_read[4];
	
	int i = 0;
	while(!cin.eof()){
		for (i=0;i<4;i++) 
			getline(cin, s_read[i]);

		size_t pos = s_read[0].rfind("_") + 1;
		string s_sample_name = s_read[0].substr(pos);
		cout<<s_sample_name<<endl;

		i++;
	}
	/*
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
*/
	return 0;
}
