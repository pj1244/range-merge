#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <string>
using namespace std;


class RangeMerge {
public:
	vector<vector<int> > merge(vector<vector<int> >& intervals) {
		if (intervals.empty())
			return vector<vector<int> >();
		sort(intervals.begin(), intervals.end());
		vector<vector<int> > res;
		res.push_back(intervals[0]);
		for (unsigned int i = 1; i < intervals.size(); ++i) {
			if (res.back()[1] >= intervals[i][0]) {
				res.back()[1] = max(res.back()[1], intervals[i][1]);
			}
			else {
				res.push_back(intervals[i]);
			}
		}
		return res;
	};

	vector<vector<int> > GetRange(const string & strRange) {

		int iLeft = -1, iMid = -1, iRight = -1;
		vector<vector<int> > out;

		for (int i = 0; i < strRange.length(); ++i) {
			if (strRange[i] == '[') {
				iLeft = i;
			}
			else if (strRange[i] == ',') {
				iMid = i;
			}
			else if (strRange[i] == ']') {
				iRight = i;
			}
			if (iLeft >=0 && iMid>=0 && iRight>=0) {

				if (iLeft < iMid && iMid < iRight) {
					int iStart = atoi((strRange.substr(iLeft+1, iMid - iLeft-1 )).c_str());
					int iEnd = atoi((strRange.substr(iMid+1, iRight - iMid-1)).c_str());
					vector<int> vec;
					vec.push_back(iStart);
					vec.push_back(iEnd);
					out.push_back(vec);
				}
				else {
					cerr << "error position, " << iLeft << " " << iMid << " " << iRight << endl;
				}
				
				iLeft = -1;
				iMid = -1;
				iRight = -1;
			}
		}

		return out;
	};

	void print(vector<vector<int> > vt) {
		for (vector<vector<int> >::iterator range = vt.begin(); range != vt.end(); range++) {
			printf("[%d, %d]", (*range)[0], (*range)[1]);
		};
	};
};

int main()
{
	//_Range range;
	while (true)
	{
		RangeMerge merge;
		string strRange;
		cout << "please input range, for example: [1,3][2,5][6,6]" << endl;
		cin >> strRange;
		vector<vector<int> > vt = merge.GetRange(strRange);
		vector<vector<int> > out = merge.merge(vt);
		cout << "the result is ";
		merge.print(out);
		cout << endl<<"-------------------"<<endl;
	}
	return 0;
}
