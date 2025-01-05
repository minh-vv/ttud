#include <iostream>
#include <vector>
#include <set>

using namespace std;

int n1, n2, L, M, P; // Số cổ phiếu nhóm công nghệ, bán lẻ, giới hạn L, M, và số cặp không đầu tư cùng nhau
vector<pair<int, int>> restrictions; // Danh sách các cặp không đầu tư cùng nhau
int result = 0;

// Hàm kiểm tra tính hợp lệ của tập hợp cổ phiếu
bool isValid(const vector<int>& chosen, const vector<int>& tech, const vector<int>& retail) {
    set<int> chosenSet(chosen.begin(), chosen.end());
    
    // Kiểm tra điều kiện số lượng
    if (chosen.size() > L) return false;

    // Kiểm tra điều kiện nhóm
    int techCount = 0, retailCount = 0;
    for (int stock : chosen) {
        if (find(tech.begin(), tech.end(), stock) != tech.end()) techCount++;
        if (find(retail.begin(), retail.end(), stock) != retail.end()) retailCount++;
    }
    if (techCount == 0 || retailCount == 0 || techCount > M || retailCount > M) return false;

    // Kiểm tra điều kiện không chọn cặp
    for (const auto& pair : restrictions) {
        if (chosenSet.count(pair.first) && chosenSet.count(pair.second)) {
            return false;
        }
    }

    return true;
}

// Hàm quay lui
void backtrack(int index, const vector<int>& allStocks, vector<int>& chosen, const vector<int>& tech, const vector<int>& retail) {
    if (index == allStocks.size()) {
        if (isValid(chosen, tech, retail)) {
            result++;
        }
        return;
    }

    // Không chọn cổ phiếu hiện tại
    backtrack(index + 1, allStocks, chosen, tech, retail);

    // Chọn cổ phiếu hiện tại
    chosen.push_back(allStocks[index]);
    backtrack(index + 1, allStocks, chosen, tech, retail);
    chosen.pop_back();
}

int main() {
    cin >> n1 >> n2 >> L >> M >> P;

    vector<int> tech(n1), retail(n2);
    for (int i = 0; i < n1; i++) tech[i] = i + 1;
    for (int i = 0; i < n2; i++) retail[i] = n1 + i + 1;

    vector<int> allStocks;
    allStocks.insert(allStocks.end(), tech.begin(), tech.end());
    allStocks.insert(allStocks.end(), retail.begin(), retail.end());

    restrictions.resize(P);
    for (int i = 0; i < P; i++) {
        cin >> restrictions[i].first >> restrictions[i].second;
    }

    vector<int> chosen;
    backtrack(0, allStocks, chosen, tech, retail);

    cout << result << endl;

    return 0;
}
