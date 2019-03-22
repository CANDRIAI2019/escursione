#include <bits/stdc++.h>
using namespace std;

using si = long long;
using ui = unsigned long long;
using flt = long double;
using ch = char;
using str = string;
template<class T>
using vec = vector<T>;

ifstream in{"input.txt"};
ofstream out{"output.txt"};

struct Node {
	si level;
	si dislivelloMin = numeric_limits<si>::max();
};

int main() {
	si T;
	in >> T;

	for(int t = 0; t != T; ++t) {
		si N, M;
		in >> N >> M;

		vec<vec<Node>> nodes{};
		nodes.resize(N);
		for(int n = 0; n != N; ++n) {
			nodes[n].resize(M);
			for(int m = 0; m != M; ++m) {
				in >> nodes[n][m].level;
			}
		}
		nodes[0][0].dislivelloMin = 0;

		// for(int n = 0; n != N; ++n) {
		// 	for(int m = 0; m != M; ++m) {
		// 		cout << nodes[n][m].level << " ";
		// 	}
		// 	cout << "\n\n";
		// }

		deque<pair<si,si>> toProcess{};
		toProcess.push_back({0,0});
		while (!toProcess.empty()) {
			auto [x, y] = toProcess.front();
			constexpr pair<si,si> offsets[] {
				{1,0},
				{-1,0},
				{0, 1},
				{0, -1}
			};

			for(auto off : offsets) {
				auto [ox, oy] = off;
				si nx = x+ox;
				si ny = y+oy;

				if(nx < 0 || nx >= N || ny < 0 || ny >= M)
					continue;

				//cout << nx << " " << ny << "\n";
				
				si dislivello = max((si)abs(nodes[nx][ny].level - nodes[x][y].level), nodes[x][y].dislivelloMin);
				if (nodes[nx][ny].dislivelloMin > dislivello) {
					nodes[nx][ny].dislivelloMin = dislivello;
					toProcess.push_back({nx, ny});
					//cout << nx << " " << ny << "\n";					
				}
			}
			toProcess.pop_front();
		}

		out << "Case #" << t+1 << ": " << nodes.back().back().dislivelloMin << "\n";
	}

	return 0;
}