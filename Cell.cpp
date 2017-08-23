//
// Created by bana4m1ni0n on 8/15/17.
//

#include "Cell.h"

Cell::Cell() : value("") {}

Cell::Cell(std::string value) {
    this->value = value;
}

Cell::Cell(const Cell & otracelda) {
    this->value = otracelda.getValue();
}

Cell::~Cell() {}

void Cell::setValue(std::string value) {
    this->value = value;
}

void Cell::setValue(const Cell & aCell) {
    this->value = aCell.getValue();
}

std::string Cell::getValue() const {
    return this->value;
}

void Cell::operator = (std::string value) {
    this->value = value;
}

void Cell::operator = (const Cell &aCell) {
    this->value = aCell.getValue();
}

bool Cell::operator == (std::string value) {
    return this->value.compare(value) == 0;
}

bool Cell::operator == (const Cell &aCell) {
    return *(this) == aCell.getValue();
//    return this->value.compare(aCell.getValue()) == 0;
}

bool Cell::operator != (std::string value) {
    return !(*(this) == value);
//    return this->value.compare(value) != 0;
}

bool Cell::operator != (const Cell &aCell) {
    return !(*(this) == aCell);
}

bool Cell::operator <= (std::string value) {
    return this->value.compare(value) <= 0;
}

bool Cell::operator <= (const Cell &aCell) {
    return *(this) <= aCell.getValue();
}

bool Cell::operator >= (std::string value) {
    return this->value.compare(value) >= 0;
}

bool Cell::operator >= (const Cell &aCell) {
    return *(this) >= aCell.getValue();
}

bool Cell::operator < (std::string value) {
    return this->value.compare(value) < 0;
}

bool Cell::operator < (const Cell &aCell) {
    return *(this) < aCell.getValue();
}

bool Cell::operator > (std::string value) {
    return this->value.compare(value) > 0;
}

bool Cell::operator > (const Cell &aCell) {
    return *(this) > aCell.getValue();
}

std::ostream & operator << (std::ostream & out, const Cell & aCell) {
    out << aCell.getValue();
}

std::istream & operator >> (std::istream & in, Cell & aCell) {
    std::string input;
    in >> input;
    aCell.setValue(input);
    return in;
}







