#include<iostream>
#include<vector>

//복잡도 4의 지수

using namespace std;


int dice[10];
int basic_root[20] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40};
int ten_root[8] = {10, 13, 16, 19, 25, 30, 35, 40};
int twenty_root[7] = {20, 22, 24, 25, 30, 35, 40};
int thirty_root[8] = {30, 28, 27, 26, 25, 30, 35, 40};
int ans = 0;

bool confirm_same(vector<int> arr_mal, int x) {

	int arr[4];

	for (int i = 0; i < 4; i++) {

		if ( arr_mal[x] == arr_mal[i] ) {
			if ( i != x )
				return true;
		}

		if(arr_mal[i] >= 10000) {
			arr[i] = arr_mal[i] - 10000;
		}	
		else if(arr_mal[i] >= 1000) {
			arr[i] = arr_mal[i] - 1000 + 1;
		}	
		else if(arr_mal[i] >= 100) {
			arr[i] = arr_mal[i] - 100;
		}
		else {
			arr[i] = arr_mal[i] + 100;
		}	
	}


	if (arr[x] >= 4 && arr[x] < 7) {
		for(int i = 0; i < 4; i++) {
			if (i != x && arr[i] == arr[x])
				return true;
		}
	}
	else if (arr[x] == 7 || arr[x] == 119) {
		if (arr[x] == 119) {
			arr[x] = 7;
		}
		for(int i = 0; i < 4; i++) {
			if (i != x && arr[i] == arr[x])
				return true;
			else if (i != x && arr[i]-100 == 19 )
				return true;
		}
	}


	return false;
};

bool confirm_other_root(vector<int> arr_mal, int x, int y) {
	for (int i = 0; i < 4; i++) {
		if ( i == x ) continue;

		if ( arr_mal[i] == y )
			return false;
	}

	return true;
}
 

//네 개의 말 위치
void DFS(int dice_index, vector<int> arr_mal, int sum) {
	if(dice_index == 10) {
		ans = max(sum, ans);
		return;
	}
	
	int count = 0;
	for (int i = 0; i < 4; i++) {
		
		if(arr_mal[i] == -1000) {
			count++;
			continue;
		}
		int stay = arr_mal[i];

		arr_mal[i] = dice[dice_index] + arr_mal[i];

		bool same_exist = confirm_same(arr_mal, i);

		if (same_exist == true) {
			arr_mal[i] = stay;
			continue;
		}

		if(arr_mal[i] >= 10000) {
			//thirty_root
			//size == 8
			if (arr_mal[i] - 10000 >= 8) {
				arr_mal[i] = -1000;
				DFS(dice_index+1, arr_mal, sum );
			}
			else
				DFS(dice_index+1, arr_mal, sum+thirty_root[arr_mal[i] - 10000] );
		}
		else if(arr_mal[i] >= 1000) {
			//twenty_root
			//size == 7
			if (arr_mal[i] - 1000 >= 7) {
				arr_mal[i] = -1000;
				DFS(dice_index+1, arr_mal, sum );
			}
			else
				DFS(dice_index+1, arr_mal, sum+twenty_root[arr_mal[i] - 1000] );
		}
		else if(arr_mal[i] >= 100) {
			//ten_root
			//size == 8
			if (arr_mal[i] - 100 >= 8) {
				arr_mal[i] = -1000;
				DFS(dice_index+1, arr_mal, sum );
			}

			else
				DFS(dice_index+1, arr_mal, sum+ten_root[arr_mal[i] - 100] );
		}
		else {
			// index로 가지고 노는 것
			if (arr_mal[i] >= 20) {
				arr_mal[i] = -1000;
				DFS(dice_index+1, arr_mal, sum );
			}
			else if ( basic_root[arr_mal[i]]%10 == 0 && basic_root[arr_mal[i]]/10 != 4) {
				if (basic_root[arr_mal[i]]/10 == 1 && confirm_other_root(arr_mal, i, 100) ) {
					arr_mal[i] = 100;
					DFS(dice_index+1, arr_mal, sum+10 );
				}
				else if (basic_root[arr_mal[i]]/10 == 2 && confirm_other_root(arr_mal, i, 1000)) {
					arr_mal[i] = 1000;
					DFS(dice_index+1, arr_mal, sum+20 );
				}
				else if (basic_root[arr_mal[i]]/10 == 3 && confirm_other_root(arr_mal, i, 10000)) {
					arr_mal[i] = 10000;
					DFS(dice_index+1, arr_mal, sum+30 );
				}
				else  {
					arr_mal[i] = stay;
					continue;
				}
					
			}
			else
				DFS(dice_index+1, arr_mal, sum+basic_root[arr_mal[i]] );
		}
		arr_mal[i] = stay;
	}

	if(count == 4)
		ans = max(sum, ans);

}

int main(void) {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 10; i++)
		cin >> dice[i];

	DFS(0, {-1, -1 , -1 ,-1}, 0);
	
	cout << ans;

	return 0;
}

