#pragma once
#include "Precompile.hpp"

struct vehicles {
    std::vector<std::string> vehicleTypes;
    std::vector<std::string> names;
    std::vector<std::string> manufacturers;
    std::vector<std::string> models;
    std::vector<bool> isReserved;
    std::vector<std::string> reservationDates;
    std::vector<std::string> locations;
    std::vector<int> prices;
    std::vector<std::string> reservedByIds;
};