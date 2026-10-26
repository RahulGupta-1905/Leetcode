
class DisjointSet {
    vector<int> parent, size;

public:
    DisjointSet(int n) {
        parent.resize(n);
        size.assign(n, 1);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findUltPar(int node) {
        if (parent[node] == node)
            return node;

        return parent[node] = findUltPar(parent[node]);
    }

    void unionBySize(int x, int y) {
        int parX = findUltPar(x);
        int parY = findUltPar(y);

        if (parX == parY)
            return;

        if (size[parX] >= size[parY]) {
            size[parX] += size[parY];
            parent[parY] = parX;
        } else {
            size[parY] += size[parX];
            parent[parX] = parY;
        }
    }
};

class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        DisjointSet ds(m * n);

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0)
                    continue;

                int node = i * n + j;

                for (int d = 0; d < 4; d++) {
                    int nr = i + dx[d];
                    int nc = j + dy[d];

                    if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                        continue;

                    if (grid[nr][nc] != 0) {
                        int neighNode = nr * n + nc;
                        ds.unionBySize(node, neighNode);
                    }
                }
            }
        }

        unordered_map<int, long long> componentSum;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0)
                    continue;

                int node = i * n + j;
                int leader = ds.findUltPar(node);

                componentSum[leader] += grid[i][j];
            }
        }

        int ans = 0;

        for (auto [leader, sum] : componentSum) {
            if (sum % k == 0) {
                ans++;
            }
        }

        return ans;
    }
};
