//
// Created by plcla on 5/21/2022.
//

#ifndef STACKS_QUEUES_LEETCODESOLUTIONS_QUEUE_H
#define STACKS_QUEUES_LEETCODESOLUTIONS_QUEUE_H

#include <cstdint>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

class Queue {
private:
    int32_t findMaxFromIndex(const std::vector<int32_t>& nums, int32_t steps, int32_t index);
    bool isInArray(const std::vector<int32_t>& nums, int32_t num);
    int32_t getMaxScore(const std::vector<int32_t>& nums);
    void emptyQueue(std::priority_queue<int32_t>& queue);

public:
    /* ****************************** */
    /* ****************************** */
    /* ----QUEUE BUILT WITH STACK---- */
    /* ****************************** */
    /* ****************************** */

    int32_t countStudents(std::vector<int32_t>& students, std::vector<int32_t>& sandwiches);
    int32_t timeRequiredToBuy(std::vector<int32_t>& tickets, int32_t k);
    int32_t firstUniqChar(std::string& s);

    /* ****************************** */
    /* ****************************** */
    /* ----STACK BUILT WITH QUEUE---- */
    /* ****************************** */
    /* ****************************** */

    int32_t maxResult(std::vector<int32_t>& nums, int32_t k);
};


#endif //STACKS_QUEUES_LEETCODESOLUTIONS_QUEUE_H
