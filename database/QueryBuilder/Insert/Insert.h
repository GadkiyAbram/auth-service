#ifndef INSERT_H
#define INSERT_H

#include "../QueryBase/QueryBase.h"
#include <vector>
#include <string>
#include <sstream>


class Insert : public QueryBase {
private:
    std::ostringstream query;
    std::string table;
    std::vector<std::string> columns;
    std::vector<std::string> params;

    Insert& setColumns(const std::vector<std::string> &columns);
    Insert& setValues(const std::vector<std::string> &values);

public:
    Insert();
    Insert& into(const std::string &table);
    Insert& values(
        std::vector<std::string> columns,
        std::vector<std::string> values
        );
    std::pair<std::string, std::vector<std::string>> build();
};


#endif
