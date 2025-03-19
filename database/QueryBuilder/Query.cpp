#include "Query.h"

Select Query::select(const std::vector <std::string> &columns) {
    Select s(columns);

    return s;
}

Insert Query::insert() {
    Insert i;

    return i;
}