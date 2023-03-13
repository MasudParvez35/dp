set <int> p;
void sieve() {
	vector<int> vis(Mx);
	for(int i = 3; i*i <= Mx; i += 2) 
    {
		if(vis[i] == 0)  {
			for(int j = i*i; j <= Mx; j += 2*i) {
				vis[j] = 1;
			}
		}
	}
	p.insert(2);
	for(int i = 3; i <= Mx; i += 2) {
		if(vis[i] == 0) p.insert(i);
	}
}
