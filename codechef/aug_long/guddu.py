t = int(input())
for i in range(t):
	n = int(input())
	ar = input().split()
	for i in range(len(ar)):
		ar[i] = int(ar[i])
	pref = [0]
	for i in range(n):
		pref.append(pref[i]^ar[i])
	b = dict()
	for i in range(n+1):
		if pref[i] not in b:
			b[pref[i]] = []
		b[pref[i]].append(i);
	ans=0
	for p in b:
		size = len(b[p])
		sum = [0 for i in range(size)]
		sum[size-1] = b[p][-1];
		for j in range(size-2,0,-1):
			sum[j] = sum[j+1] + b[p][j];
		contrib = 0;
		for j in range(size-1):
			contrib -= (size-1-j)*b[p][j];
			contrib += sum[j+1];
			contrib -= (size-1-j);
		ans += contrib;
	print(ans)
