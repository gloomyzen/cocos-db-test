#include "base.h"

using namespace mb::battleModule;

base::base() {}

std::deque<nodeTasks> base::getTasks() {
    std::deque<nodeTasks> result;

    result.emplace_back([this]() {
        return eTasksStatus::STATUS_OK;
    });

    return result;
}
