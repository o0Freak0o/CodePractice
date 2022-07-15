const int N = 3e5 + 10;
/*
���鼯
**/
class Solution {
private:
    int p[N];
public:
    int find(int x) {
        if (x != p[x])  p[x] = find(p[x]);
        return p[x];
    }
    void merge(int a, int b) {
        int x = find(a), y = find(b);
        if (x == y)     return;
        p[x] = y;
    }
    bool gcdSort(vector<int>& nums) {
        vector<int> nums1 = nums;
        for (int i = 1; i < N; i++) p[i] = i;
        // �ֽ�������
        for (auto c:nums) {
            int k = c;
            //�����Ӻϲ����ܾ������������ӵ��㷨��ͨ������ȷ�������ӵ�ͬʱ���Զ����˷��������������Ż�
            for (int i = 2; i <= c / i; i++) {
                bool flag = false;
                while (c % i == 0)
                    c /= i, flag = true;
                if (flag)
                    merge(k, i);
            }
            // �ϲ�������
            if (c > 1)
               merge(k, c);
        }
        sort(nums1.begin(), nums1.end());
        // �Ա�ԭ����
        for (int i = 0; i < nums1.size(); i++) {
            if (nums1[i] == nums[i])    continue;
            if (find(nums1[i]) != find(nums[i]))    return false;
        }
        return true;
    }
};