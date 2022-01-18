#include <iostream>
#include <vector>
#include <cstdio>
#include <limits.h>
#include <cassert>
using namespace std;

//找交叉函式
int FindCrossMax(vector<int> &array, int front, int middle, int end) {
	int LeftMax = INT_MIN, LeftSum = 0;
	int RightMax = INT_MIN, RightSum = 0;
	for (int i = middle; i >= front; --i) {
        LeftSum += array[i];
        LeftMax = max(LeftMax, LeftSum);
    }
	for (int i = middle + 1; i <= end; ++i) {
        RightSum += array[i];
        RightMax = max(RightMax, RightSum);
    }
    return max(max(LeftMax, RightMax), LeftMax + RightMax);
}

//找最大子集合函式
int FindMaxSubarray(vector<int> &array, int front, int end) {
    if (front == end) return array[front];
    int middle = (front + end) / 2;
    int LeftMax = FindMaxSubarray(array, front, middle);
    int RightMax = FindMaxSubarray(array, middle + 1, end);
    int cross = FindCrossMax(array, front, middle, end);
    return max(max(LeftMax, RightMax), cross);
}

//找最大子集合轉換函式
int Max(vector<int> &array, int length) {
    return FindMaxSubarray(array, 0, length - 1);
}


//主程式
int main() {
	int *p = new int[100000];
	int j = 0, sign = 1, space = 0;
	char ch;
	p[j] = 0;

	//輸入字串
	while(1) {
		ch = getchar();
		if(ch == EOF) {	
			p[j] = p[j] * sign;
			if(space == 1) break;
			else{
				j++;
				break;
			}
		}
		else if((int)ch == 32) {
			p[j] = p[j] * sign;
			j++;
			p[j] = 0;
			sign = 1;
			space = 1;
			continue;
		}
		else {
			space = 0;
			if(ch == '-'){
				sign = -1;
				p[j] = 0;
			}
			else p[j] = p[j] * 10 + (int)ch - 48;
		}
	}
	vector<int> array(p, p + j);
	cout << Max(array, j) << endl;
	return 0;
}


