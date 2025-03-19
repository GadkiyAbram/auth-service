#ifndef GYRODATA_MICROSERVICES_QUERYBASE_H
#define GYRODATA_MICROSERVICES_QUERYBASE_H

#include <string>
#include <sstream>
#include <vector>

class QueryBase {
public:
    virtual ~QueryBase() = default;
    virtual std::pair<std::string, std::vector<std::string>> build() = 0;
};

#endif
