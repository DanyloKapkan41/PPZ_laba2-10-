#include <iostream>
using namespace std;
void filling(int*& nums, int i, int n, bool mode)
{
	if (mode) {
		if (i < n) {
			nums[i] = rand() % 5001;
			i++;
			filling(nums, i, n, mode);
		}
	}
	else {
		if (i < n) {
			do { cin >> nums[i]; } while (nums[i] < 0 || nums[i]>5000);
			cout << " writed...\n";
			i++;
			filling(nums, i, n, mode);
		}
	}
}
void extract(int* nums, int i, int n)
{
	if (i < n) {
		cout << nums[i] << ' ';
		i++;
		extract(nums, i, n);
	}
}
void change(int*& numb, int n)
{
	int x=0, y=0, i;
	int* numb1= new int[n];
	for (i = 0; i < n; i++)
	{
		if (numb[i] % 2 == 0)
		{
			numb1[x] = numb[i];
			x++;
		}else {
			numb1[n-y-1] = numb[i];
			y++;
		}
	}
	for (i = 0; i < n; i++)
	{
		numb[i] = numb1[i];
	}
	delete[] numb1;
}
int main()
{
	int n, modeint;
	bool mode;
	do {
		cout << "Enter array size(1 - 5000): ";
		cin >> n;
	} while (n < 1 || n > 5000);
	int* nums = new int[n];
	srand(time(NULL));
	do {
		cout << "Choose mode (1 - autoentering, 0 - enterig by yourself): ";
		cin >> modeint;
	} while (modeint < 0 || modeint > 1);
	mode = modeint;
	filling(nums, 0, n, mode);
	extract(nums, 0, n);
	cout << endl;
	change(nums, n);
	extract(nums, 0, n);
	delete[] nums;
}