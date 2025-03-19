#ifndef QUERY_H
#define QUERY_H

#include "./Select/Select.h"
#include "./Insert/Insert.h"

class Query {
public:
    static Select select(const std::vector <std::string> &columns);
    static Insert insert();
};

#endif