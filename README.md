
# Algorithms & Data Structures – Repeat Project – August 2023
# Ordered Array and Set of Leads Program

Welcome to the Ordered Array and Set of Leads Program, a C++ project designed to implement and test ordered array and set functionality.

## Table of Contents

- [Overview](#overview)
- [Project Details](#project-details)
  - [Q1: Ordered Array](#q1-ordered-array)
  - [Q2: MySet](#q2-myset)
  - [Q3: Lead Analysis](#q3-lead-analysis)
- [Usage](#usage)
- [License](#license)
- [Project URL](#url)


## Overview

This project aims to implement and test an ordered array class and a set class based on the ordered array. Additionally, it involves lead analysis functionality to process and categorize leads from sales representatives.

## Project Details

### Q1: Ordered Array

Implement a templated `OrderedArray` class with various methods to manage an array with natural ordering.

- `OrderedArray(int grow_size)`: Constructor for an `OrderedArray` with a customizable growth size.
- `OrderedArray()`: Default constructor with a sensible default growth size.
- `~OrderedArray()`: Destructor to free allocated memory.
- `void push(const T& newElement)`: Inserts an element in order.
- `int length()`: Returns the number of elements in the array.
- `T getElement(int index)`: Returns an element at a given index.
- `bool remove(int index)`: Removes an element at the given index.
- `int search(const T& target)`: Searches for a target value in the array.
- `void clear()`: Empties the array and frees memory.

### Q2: MySet

Extend the `OrderedArray` to create a `MySet` class for efficient storage of unique values.

- Overload `|` (union) and `&` (intersection) operators.

### Q3: Lead Analysis

Implement lead analysis functionality to process and categorize leads from sales representatives.

- Accept two CSV files with lead data.
- Output three separate CSV files containing common and unique leads.

## Usage

## Installation


## License


## Project URL

* [GitHub URL link](https://github.com/teomeo12/ADS_2023_RPT_TeodorDonchev_SD3a.git)

This project is part of the ADS module, Software Development, DkIT.
