#include <bits/stdc++.h> 



vector<int> kMaxSumCombination(vector<int> &A, vector<int> &B, int n, int K){
	
	vector<int> c;
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	// int n = A.size();


	priority_queue<pair<int, pair<int, int> > > pq;

	
	set<pair<int, int> > my_set;

	
	pq.push(make_pair(A[n - 1] + B[n - 1],
					make_pair(n - 1, n - 1)));

	my_set.insert(make_pair(n - 1, n - 1));

	
	for (int count = 0; count < K; count++)
	{
		// tuple format (sum, (i, j)).
		pair<int, pair<int, int> > temp = pq.top();
		pq.pop();

		c.push_back(temp.first);

		int i = temp.second.first;
		int j = temp.second.second;

		int sum = A[i - 1] + B[j];

		
		pair<int, int> temp1 = make_pair(i - 1, j);

		// insert only if the pair (i - 1, j) is
		// not already present inside the map i.e.
		// no repeating pair should be present inside
		// the heap.
		if (my_set.find(temp1) == my_set.end())
		{
			pq.push(make_pair(sum, temp1));
			my_set.insert(temp1);
		}

		// insert (A[i] + B[j - 1], (i, j - 1))
		// into max heap.
		sum = A[i] + B[j - 1];
		temp1 = make_pair(i, j - 1);

		// insert only if the pair (i, j - 1)
		// is not present inside the heap.
		if (my_set.find(temp1) == my_set.end())
		{
			pq.push(make_pair(sum, temp1));
			my_set.insert(temp1);
		}
	}
    return c;
}

