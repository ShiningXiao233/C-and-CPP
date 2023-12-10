#include <iostream>

using namespace std;

const int N = 5e3+10;
int a[N], t[N];
int n;

#include <vector>

int mysolve()
{
	vector<int>lis;//这里求的是严格递增lis
	for(int i=1; i<=n; ++i)
		{
			cin>>t[i];
			if(lis.empty()||t[i]>lis.back())lis.push_back(t[i]);//严格递增你如果要放最后，那你必须>lis数组当前最后一个，如果是单调不下降则是>=
			else lis[lower_bound(lis.begin(),lis.end(),t[i])-lis.begin()]=t[i];//严格递增如果你要替换，那么如果有相等的，必须替换掉，否则会出现=的情况，所以用lower_bound.如果是单调不下降，用upper_bound，即允许=存在
		}
    return lis.size();
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        t[i] = a[i];
    }   
    int ans = 0;     
    for (int i = 1; i <= n; ++i) {
        if (i < n) t[i] = max(0, a[i + 1] - 1);
        ans = max(ans, mysolve());
        if (i > 1) t[i] = a[i - 1] + 1;
        ans = max(ans, mysolve());
        t[i] = a[i];
    }
    cout << ans << endl;
    return 0;
}