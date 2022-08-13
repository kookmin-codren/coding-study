#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int max_value = 0; // 최대 값 0으로 초기 설정
void dfs(vector<int> num_copy, int cnt, int b) // 숫자 배열, 현재 교환 수, 최종 교환 해야할 수
{	
	int length = num_copy.size(); // 밑에서 c_length와 비교할때 size함수를 그대로 쓰면 비교가 안됨
	if (cnt == b) // 교환한 횟수와 필수 교환수가 일치하면 비교 아닐 경우 27줄
	{
		int c_length = 0; // 배열을 숫자로 바꾸기 위한 변수들과 반복문
		int x = 1;		 // ex) [1,2,3] ->123
		int y = 1;
		int value = 0;
		while (c_length < length)
		{
			value += (num_copy[length-y]) * x;
			x *= 10;
			y++;
			c_length++;
		}
		max_value = max(max_value, value); //바꾼 배열의 숫자와 기존 최댓값과 비교

		return;
	}
	for (int i = 0; i < length-1; i++) //배열의 0번째부터 바꿔주는 반복문
	{
		for (int j = i + 1; j < length; j++)
		{	
			int tmp = num_copy[i]; //배열의 i번째와 j번째를 바꿔줌(i<j)
			num_copy[i] = num_copy[j];
			num_copy[j] = tmp;
			dfs(num_copy, cnt + 1, b); //바꾼 배열로 재귀함수
			num_copy[j] = num_copy[i]; //return 하여 나오면 원상태로 복귀 후에 다시 반복문
			num_copy[i] = tmp;
		}
	}
}

int main()
{
	int x;
	cin >> x;
	for (int i = 1; i <= x; i++)
	{
		int a, b; //숫자와 교환횟수
		cin >> a>>b;
		vector<int> num;
		while (a > 0) //배열에 순서대로 저장
		{
			num.insert(num.begin(), 1, a % 10);
			a /= 10;
		}
		vector<int> num_copy = num; // 원래대로 돌아올 일이 있을까봐 num을 복사해서 사용했지만 필요 없음
		if(b>=num.size())
		{
			b = num.size();
		}
		dfs(num_copy, 0, b);
		cout << "#"<<i<<" "<<max_value<<endl;
		max_value = 0;
	}
	return 0;
}