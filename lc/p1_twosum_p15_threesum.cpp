#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cstddef>

struct Pair
{
    int p1, p2;
};

void insertInMap(std::unordered_map<int, int> &num2freq, int thisNum)
{
    if (num2freq.find(thisNum) == num2freq.end())
    {
        num2freq[thisNum] = 1;
    }
    else
    {
        num2freq[thisNum]++;
    }
}

std::vector<Pair> findTwoSumUnique(std::vector<int>::iterator dataItr, std::vector<int> &data, int target)
{
    std::vector<Pair> result;
    std::unordered_set<int> set;
    std::unordered_set<int> seen;
    for (; dataItr != data.end(); dataItr++)
    {
        int thisVal = *dataItr;
        if (set.find(target - thisVal) != set.end())
        {
            if (seen.find(thisVal) == seen.end())
            {
                result.push_back({thisVal, target - thisVal});
                seen.insert(thisVal);
                seen.insert(target - thisVal);
            }
        }
        set.insert(thisVal);
    }
    return result;
}

std::vector<Pair> findTwoSum(std::vector<int>::iterator dataItr, std::vector<int> &data, int target)
{
    std::vector<Pair> result;
    std::unordered_map<int, int> num2freq;
    for (; dataItr != data.end(); dataItr++)
    {
        int thisNum = *dataItr;
        auto compItr = num2freq.find(target - thisNum);
        if (compItr != num2freq.end())
        {
            int numTimesSeen = compItr->second;
            for (int i = 0; i < numTimesSeen; i++)
            {
                Pair p;
                p.p1 = thisNum;
                p.p2 = target - thisNum;
                result.push_back(p);
            }
        }
        insertInMap(num2freq, thisNum);
    }
    return result;
}
void uniquify(std::vector<std::vector<int>> &results)
{
    struct Elems
    {
        int p1, p2, p3;

        bool operator==(const Elems &other) const
        {
            return this->p1 == other.p1 && this->p2 == other.p2 && this->p3 == other.p3;
        }
    };

    class MyHashFunction
    {
    public:
        // id is returned as hash function
        size_t operator()(const Elems &t) const
        {
            return static_cast<size_t>(t.p1 ^ t.p2 ^ t.p3);
        }
    };
    std::unordered_set<Elems, MyHashFunction> uniqueTriplets;
    for (const auto &triplet : results)
    {
        uniqueTriplets.insert({triplet[0], triplet[1], triplet[2]});
    }

    results.clear();
    for (const auto &u : uniqueTriplets)
    {
        std::vector<int> t = {u.p1, u.p2, u.p3};
        results.push_back(t);
    }
}

std::vector<std::vector<int>> threeSum(std::vector<int> &nums)
{
    std::vector<std::vector<int>> result;
    if (nums.size() < 3)
    {
        return result;
    }
    else if (nums.size() == 3)
    {
        if (nums[0] + nums[1] + nums[3] == 0)
        {
            result.push_back(nums);
        }
        return result;
    }
    for (auto dataItr = nums.begin(); dataItr != nums.end(); dataItr++)
    {
        int target = -1 * (*dataItr);
        std::vector<int>::iterator startIdx = dataItr + 1;
        std::vector<Pair> twoSumResults = findTwoSum(startIdx, nums, target);
        for (auto pair : twoSumResults)
        {
            std::vector<int> localRes = {pair.p1, pair.p2, *dataItr};
            result.push_back(localRes);
        }
    }
    return result;
}
