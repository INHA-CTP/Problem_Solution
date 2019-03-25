/*
	Author : Young Jo,An
	Date : 19.03.25
	Problem Number: 4195
	Problem Name: 친구 네트워크
*/
#include <cstdio>

const int PRIME = 30011;
//왜 10007도 가능한지 의문...


struct data {
	char str[21];
	int parent;
	int cnt;
};

struct hashmap {
	data m[PRIME];
} map, tmp;

void c_strcpy(char* dest, char* src) {
	int i = 0;
	while (src[i]) {
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

bool c_strcmp(char* a, char* b) {
	int i = 0;
	while (a[i] && b[i]) {
		if (a[i] != b[i]) {
			return false;
		}
		i++;
	}
	if (a[i] || b[i]) {
		return false;
	}
	return true;
}

long long power(long long a, long long b) {
	if (b == 0) {
		return 1;
	}
	if (b & 1) {
		return (power(a, b - 1) % PRIME*a%PRIME) % PRIME;
	}
	return power((a%PRIME*a%PRIME) % PRIME, b / 2) % PRIME;
}

long long make_hash(char* str) {
	long long hash = 0;
	long long i = 0;
	while (str[i]) {
		hash = (hash + (power(26, i) % PRIME*str[i] % PRIME) % PRIME) % PRIME;
		i++;
	}
	return hash;
}

long long insert_hash(long long hash, char* str) {
	while (map.m[hash].str[0]) {
		hash++;
		hash %= PRIME;
	}
	c_strcpy(map.m[hash].str, str);
	map.m[hash].parent = hash;
	map.m[hash].cnt = 1;
	return hash;
}

long long find_hash(long long hash, char* str) {
	while (map.m[hash].str[0]) {
		if (c_strcmp(map.m[hash].str, str)) {
			return hash;
		}
		hash++;
		hash %= PRIME;
	}
	return -1;
}

int find(int here) {
	if (map.m[here].parent == here) {
		return here;
	}
	return map.m[here].parent = find(map.m[here].parent);
}

void merge(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v) {
		return;
	}
	map.m[u].cnt += map.m[v].cnt;
	map.m[v].parent = u;
}

int c_max(int a, int b) {
	return ((a > b) ? a : b);
}

int main() {
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		map = tmp;
		int f;
		scanf("%d", &f);
		char a[21], b[21];
		for (int i = 0; i < f; i++) {
			scanf("%s %s", a, b);
			long long a_hash = make_hash(a);
			long long b_hash = make_hash(b);
			long long a_ret = find_hash(a_hash, a);
			long long b_ret = find_hash(b_hash, b);
			if (a_ret == -1) {
				a_ret = insert_hash(a_hash, a);
			}
			if (b_ret == -1) {
				b_ret = insert_hash(b_hash, b);
			}
			merge(a_ret, b_ret);
			printf("%d\n", c_max(map.m[find(a_ret)].cnt, map.m[find(b_ret)].cnt));
		}
	}
	return 0;
}