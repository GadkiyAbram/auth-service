#include "Insert.h"

Insert::Insert() {
    this->query << "INSERT INTO ";
}

Insert& Insert::into(
    const std::string &table,
    std::vector <std::string> columns
    ) {
    this->table = table;
    this->setColumns(columns);

    return *this;
}

Insert& Insert::values(
    std::vector <std::string> values
    ) {
    this->setValues(values);

    return *this;
}

Insert& Insert::setColumns(const std::vector<std::string> &columns) {
    this->columns = columns;

    return *this;
}

Insert& Insert::setValues(const std::vector<std::string> &values) {
    this->params = values;

    return *this;
}

std::pair<std::string, std::vector<std::string>> Insert::build() {
    int paramPosition = 1;

    if (this->columns.empty()) {
        throw std::runtime_error("Columns cannot be empty");
    }

    if (this->params.empty()) {
        throw std::runtime_error("Values cannot be empty");
    }

    if (this->columns.size() != this->params.size()) {
        throw std::runtime_error("Number of columns and values must match");
    }

    this->query << this->table << " (";

    for (size_t i = 0; i < this->columns.size(); ++i) {
        this->query << this->columns[i];
        if (i < this->columns.size() - 1) {
            this->query << ", ";
        }
    }

    this->query << ") VALUES (";

    for (size_t i = 0; i < this->params.size(); ++i) {
        this->query << "$" << paramPosition++;
        if (i < this->params.size() - 1) {
            this->query << ", ";
        }
    }

    this->query << ");";

    return {this->query.str(), this->params};
}
