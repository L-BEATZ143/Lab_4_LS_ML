# Receipt Repository Template

A small C++17 starter repository for generating formatted receipts.

## What is included

- `Receipt` domain class with line items and totals
- Currency-safe integer pricing in cents
- Tax calculation using basis points (`825` means `8.25%`)
- Validation for item descriptions, quantities, prices, and tax rates
- Formatted console output
- CMake and direct compiler build instructions

## Run with the compiler

```bash
g++ -std=c++17 -Wall -Wextra -Wpedantic \
    -Iinclude main.cpp src/receipt.cpp -o receipt_app
./receipt_app
```

## Build with CMake

```bash
cmake -S . -B build
cmake --build build
./build/receipt_app
```

## Customize the template

Edit `main.cpp` to connect the receipt model to your application:

```cpp
receipt::Receipt receipt("Your Store", "R-0001", 825);
receipt.addItem({"Product name", 2, 1299});
```

Prices are integer cents, so `1299` represents `$12.99`. This avoids
floating-point rounding problems when calculating totals.

## Suggested extensions

- Load items from a database or checkout form
- Add customer, payment, and transaction metadata
- Export receipts as JSON, CSV, HTML, or PDF
- Add a persistent receipt number generator