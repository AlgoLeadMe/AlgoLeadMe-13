#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 500001

int n, m;
int arr[MAX];
int tree[MAX * 4];

void init(int node, int start, int end) {
    if (start == end) {
        tree[node] = arr[start];
        return;
    }
    int mid = (start + end) / 2;
    init(node * 2, start, mid);
    init(node * 2 + 1, mid + 1, end);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

void update(int node, int start, int end, int idx, int diff) {
    if (idx < start || idx > end) return;
    tree[node] += diff;
    if (start != end) {
        int mid = (start + end) / 2;
        update(node * 2, start, mid, idx, diff);
        update(node * 2 + 1, mid + 1, end, idx, diff);
    }
}

int query(int node, int start, int end, int k) {
    if (start == end) return start;
    int mid = (start + end) / 2;
    if (tree[node * 2] >= k)
        return query(node * 2, start, mid, k);
    else
        return query(node * 2 + 1, mid + 1, end, k - tree[node * 2]);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &arr[i]);

    init(1, 1, n);

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int cmd;
        scanf("%d", &cmd);
        if (cmd == 1) {
            int b, c;
            scanf("%d %d", &b, &c);
            update(1, 1, n, b, c);
        }
        else {
            int k;
            scanf("%d", &k);
            printf("%d\n", query(1, 1, n, k));
        }
    }
    return 0;
}
