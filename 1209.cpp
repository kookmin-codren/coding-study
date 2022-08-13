#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	for (int i = 1; i <= 10; i++)
	{
		int a;
		cin >> a;
		vector<vector<int>> map;
		vector<int> r;
		map.push_back(r);
		int result = 0;
		int r_sum = 0;
		int x_sum = 0;
		int c_sum = 0;
		for (int j = 0; j < 100; j++)
		{
			for (int k = 0; k < 100; k++)
			{
				int x;
				cin >> x;
				map[j].push_back(x);
				r_sum += x;
				if (j == k)
					x_sum += x;
			}
			result = max(result, r_sum);
			map.push_back(r);
			r_sum = 0;
		}
		result = max(result, x_sum);
		x_sum = 0;

		for (int j = 0; j < 100; j++)
		{
			for (int k = 0; k < 100; k++)
			{
				c_sum += map[k][j];
				if (j + k == 99)
					x_sum += map[k][j];
			}
			result = max(result, c_sum);
			c_sum = 0;
		}
		result = max(result, x_sum);

		cout << "#" << i << " " << result << endl;
		
	}
	return 0;
}