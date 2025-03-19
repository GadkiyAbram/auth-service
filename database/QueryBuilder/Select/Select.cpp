#include "Select.h"
#include <iostream>

Select::Select(const std::vector <std::string> &columns) {
    this->select(columns);
    this->query << "SELECT ";
}

void Select::select(const std::vector <std::string> &columns) {
    this->columns = columns;
}

Select& Select::from(const std::string &table) {
    this->table = table;

    return *this;
}

Select& Select::where(const Condition &where) {
    this->whereConditions = where;

    return *this;
}

Select& Select::andWhere(const Condition &andWhere) {
    this->andWhereConditions.push_back(andWhere);

    return *this;
}

std::pair<std::string, std::vector<std::string>> Select::build() {
    int paramPosition = 1;

    if (this->columns.empty()) {
        this->query << "*";
    } else {
        for (size_t i = 0; i < columns.size(); ++i) {
            this->query << columns[i];

            if (i < columns.size() - 1) {
                this->query << ", ";
            }
        }
    }

    this->query << " FROM " << this->table;

    if (!this->whereConditions.isEmpty()) {
        this->query << " WHERE " << this->whereConditions.column << this->whereConditions.op << " $" << paramPosition++ << " ";
        this->params.push_back(this->whereConditions.value);
    }

    if (!this->andWhereConditions.empty()) {
        for (const auto &condition : this->andWhereConditions) {
            if (!condition.isEmpty()) {
                this->query << " AND " << condition.column << " " << condition.op << " $" << paramPosition++ << " ";
            }
        }
    }

    this->query << ";";

    return {this->query.str(), this->params};
}