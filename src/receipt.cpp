#include "receipt/receipt.hpp"

#include <iomanip>
#include <sstream>
#include <stdexcept>
#include <utility>

namespace receipt {
namespace {

std::string formatMoney(std::int64_t cents) {
    std::ostringstream output;
    output << '$' << cents / 100 << '.' << std::setw(2) << std::setfill('0')
           << cents % 100;
    return output.str();
}

std::int64_t roundTax(std::int64_t subtotal_cents, int tax_rate_basis_points) {
    const auto numerator =
        subtotal_cents * static_cast<std::int64_t>(tax_rate_basis_points);
    return (numerator + 5000) / 10000;
}

}  // namespace

Receipt::Receipt(std::string store_name, std::string receipt_number,
                 int tax_rate_basis_points)
    : store_name_(std::move(store_name)),
      receipt_number_(std::move(receipt_number)),
      tax_rate_basis_points_(tax_rate_basis_points) {
    if (tax_rate_basis_points < 0 || tax_rate_basis_points > 10000) {
        throw std::invalid_argument("tax rate must be between 0% and 100%");
    }
}

void Receipt::addItem(LineItem item) {
    if (item.description.empty()) {
        throw std::invalid_argument("item description cannot be empty");
    }
    if (item.quantity <= 0) {
        throw std::invalid_argument("item quantity must be positive");
    }
    if (item.unit_price_cents < 0) {
        throw std::invalid_argument("item price cannot be negative");
    }

    items_.push_back(std::move(item));
}

std::int64_t Receipt::subtotalCents() const {
    std::int64_t subtotal = 0;
    for (const auto& item : items_) {
        subtotal += item.unit_price_cents * item.quantity;
    }
    return subtotal;
}

std::int64_t Receipt::taxCents() const {
    return roundTax(subtotalCents(), tax_rate_basis_points_);
}

std::int64_t Receipt::totalCents() const {
    return subtotalCents() + taxCents();
}

std::string Receipt::format() const {
    std::ostringstream output;
    output << "================================\n"
           << store_name_ << '\n'
           << "Receipt #" << receipt_number_ << '\n'
           << "================================\n";

    for (const auto& item : items_) {
        const auto line_total = item.unit_price_cents * item.quantity;
        output << item.quantity << " x " << item.description << " @ "
               << formatMoney(item.unit_price_cents) << " = "
               << formatMoney(line_total) << '\n';
    }

    output << "--------------------------------\n"
           << "Subtotal: " << formatMoney(subtotalCents()) << '\n'
           << "Tax:      " << formatMoney(taxCents()) << '\n'
           << "Total:    " << formatMoney(totalCents()) << '\n'
           << "================================\n";

    return output.str();
}

}  // namespace receipt