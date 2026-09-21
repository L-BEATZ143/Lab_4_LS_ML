#pragma once

#include <cstdint>
#include <string>
#include <vector>

namespace receipt {

struct LineItem {
    std::string description;
    int quantity;
    std::int64_t unit_price_cents;
};

class Receipt {
public:
    // tax_rate_basis_points: 825 means 8.25%.
    Receipt(std::string store_name, std::string receipt_number,
            int tax_rate_basis_points = 0);

    void addItem(LineItem item);

    [[nodiscard]] std::int64_t subtotalCents() const;
    [[nodiscard]] std::int64_t taxCents() const;
    [[nodiscard]] std::int64_t totalCents() const;
    [[nodiscard]] std::string format() const;

private:
    std::string store_name_;
    std::string receipt_number_;
    int tax_rate_basis_points_;
    std::vector<LineItem> items_;
};

}  // namespace receipt