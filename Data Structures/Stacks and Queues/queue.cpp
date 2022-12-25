//
// Created by plcla on 5/21/2022.
//

#include "queue.h"

int32_t Queue::countStudents(std::vector<int32_t> &students, std::vector<int32_t> &sandwiches) {
    int32_t numOfTries = 0;

    while (!sandwiches.empty()) {
        if (numOfTries == students.size()) {
            break;
        }

        if (students.front() == sandwiches.front()) {
            students.erase(students.begin());
            sandwiches.erase(sandwiches.begin());

            numOfTries = 0;
        }
        else {
            students.push_back(students.front());
            students.erase(students.begin());

            numOfTries++;
        }
    }

    if (numOfTries == students.size())
        return students.size();
    else
        return 0;
}

int32_t Queue::timeRequiredToBuy(std::vector<int32_t> &tickets, int32_t k) {
    int32_t totalTime = 0;

    for (int32_t index = 0; index < tickets.size(); index++) {
        if (index < k && tickets[index] >= tickets[k]) {
            totalTime += tickets[k];
        }
        else if (index > k && tickets[index] >= tickets[k]) {
            totalTime += tickets[k] - 1;
        }
        else {
            totalTime += tickets[k];
        }
    }

    return totalTime;
}

int32_t Queue::firstUniqChar(std::string& s) {
    //KEY = num of occurrences; MAPPED = letter from sentence
    std::unordered_map<char, int32_t> numOfOccurrences;

    // construct map
    for (auto& ref : s) {
        if (numOfOccurrences.find(ref) != numOfOccurrences.end()) {
            numOfOccurrences[ref]++;
        }
        else {
            numOfOccurrences.insert(std::make_pair(ref, 1));
        }
    }

    // find unique occurrence
    for (int32_t index = 0; index < s.size(); index++) {
        if (numOfOccurrences.at(s[index]) == 1) {
            return index;
        }
    }
    return -1;
}

int32_t Queue::maxResult(std::vector<int32_t> &nums, int32_t k) {
    std::priority_queue<std::pair<int32_t, int32_t>> pq;

    int32_t maxScore;
    for (int32_t index = 1; index < nums.size(); index++) {
        while (!pq.empty() && (index - pq.top().second) > k)
            pq.pop();

        if (index == nums.size() - 1) {
            if (!pq.empty())
                maxScore = nums[index] + pq.top().first;
            else
                maxScore = nums[0];
        }
        else {
            if (!pq.empty())
                pq.push(std::make_pair(nums[index] + pq.top().first, index));
            else
                pq.push(std::make_pair(nums[index], index));
        }
    }

    return maxScore;
}
