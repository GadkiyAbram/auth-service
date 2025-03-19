#ifndef SELECT_H
#define SELECT_H

#include "../QueryBase/QueryBase.h"
#include <vector>
#include <string>
#include <sstream>
#include "../../../constants/db/Query/Query.h"


class Select : public QueryBase {
private:
    std::ostringstream query;
    std::string table;
    std::vector<std::string> columns;
    Condition whereConditions;
    std::vector<Condition> andWhereConditions;
    std::vector<std::string> params;

    void select(const std::vector<std::string> &columns);

public:
    Select(const std::vector <std::string> &columns);
    Select& from(const std::string &table);
    Select& where(const Condition &where);
    Select& andWhere(const Condition &andWhere);

    std::pair<std::string, std::vector<std::string>> build();
};

#endif
