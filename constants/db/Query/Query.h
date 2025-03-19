#ifndef CONSTANTS_QUERY_H
#define CONSTANTS_QUERY_H

struct Condition {
    std::string op;
    std::string column;
    std::string value;

    bool isEmpty() const {
        return column.empty() || value.empty();
    }
};

#endif
