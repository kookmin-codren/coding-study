#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int max_value = 0; // �ִ� �� 0���� �ʱ� ����
void dfs(vector<int> num_copy, int cnt, int b) // ���� �迭, ���� ��ȯ ��, ���� ��ȯ �ؾ��� ��
{	
	int length = num_copy.size(); // �ؿ��� c_length�� ���Ҷ� size�Լ��� �״�� ���� �񱳰� �ȵ�
	if (cnt == b) // ��ȯ�� Ƚ���� �ʼ� ��ȯ���� ��ġ�ϸ� �� �ƴ� ��� 27��
	{
		int c_length = 0; // �迭�� ���ڷ� �ٲٱ� ���� ������� �ݺ���
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
		max_value = max(max_value, value); //�ٲ� �迭�� ���ڿ� ���� �ִ񰪰� ��

		return;
	}
	for (int i = 0; i < length-1; i++) //�迭�� 0��°���� �ٲ��ִ� �ݺ���
	{
		for (int j = i + 1; j < length; j++)
		{	
			int tmp = num_copy[i]; //�迭�� i��°�� j��°�� �ٲ���(i<j)
			num_copy[i] = num_copy[j];
			num_copy[j] = tmp;
			dfs(num_copy, cnt + 1, b); //�ٲ� �迭�� ����Լ�
			num_copy[j] = num_copy[i]; //return �Ͽ� ������ �����·� ���� �Ŀ� �ٽ� �ݺ���
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
		int a, b; //���ڿ� ��ȯȽ��
		cin >> a>>b;
		vector<int> num;
		while (a > 0) //�迭�� ������� ����
		{
			num.insert(num.begin(), 1, a % 10);
			a /= 10;
		}
		vector<int> num_copy = num; // ������� ���ƿ� ���� ������� num�� �����ؼ� ��������� �ʿ� ����
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