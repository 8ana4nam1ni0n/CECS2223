//
// Created by bana4m1ni0n on 8/17/17.
//

#include "Row.h"

Row::Row() : columns(nullptr), length(0) {}

Row::Row(const Cell * columns, int length) {
   // definition
}

Row::Row(const Row & aRow) {
    bool empty = aRow.isEmpty();
    if (empty) {
        this->columns = nullptr;
        this->length = 0;
    }
    else {
        this->columns = new Cell[aRow.getLength()];
        for (int i = 0; i < aRow.getLength(); i++) {
            this->columns[i] = aRow.getColumns()[i];
        }
        this->length = aRow.getLength();
    }
}

Row::~Row() {
    this->clear();
}

void Row::setColumns(const Cell & aCell) {
    bool empty = this->isEmpty();
    if (!empty) {
        this->clear();
    }
    this->columns = new Cell[1];  // dynamic array
    this->length = 1;
    this->columns[0] = aCell;
}

void Row::setColumns(const Cell * cells, int length) {
    bool hasElements = !(cells == nullptr);
    bool empty =  this->isEmpty();
    if (hasElements) {
        if (!empty) {
            this->clear();
        }
        this->columns = new Cell[length];
        for (int i = 0; i < length; i++) {
            this->columns[i] = cells[i];
        }
        this->length = length;
    }
}

Cell * Row::getColumns() const {
    return this->columns;
}

Cell Row::getColumn(int position) const {
    return this->columns[position];
}

int Row::getLength() const {
    return this->length;
}

void Row::clear() {
    delete [] this->columns;
    this->columns = nullptr;
}

bool Row::isEmpty() const {
    return this->length == 0;
}

bool Row::addColumn(const Cell &aCell) {
    bool empty = this->isEmpty();
    if (empty) {
        this->setColumns(aCell);
    }
    else {
        Cell * tmpCell = new Cell[this->length + 1];
        for (int i = 0; i < this->length; i++) {
            tmpCell[i] = this->columns[i];
        }
        this->clear(); // delete [] this->columns;
        this->columns = new Cell[this->length + 1];
        for (int i = 0; i < this->length; i++) {
            this->columns[i] = tmpCell[i];
        }
        delete[] tmpCell;
        this->columns[this->length] = aCell;
        this->length += 1;
    }
    return true;  // **implement on exception handling class**
}

bool Row::deleteColumn(int position) {
    bool canDelete = true;
    bool empty = this->isEmpty();
    if (empty || position > this->length) {
        canDelete = false;
    }
    else {
        Cell * tempCell = new Cell[this->length - 1];
        for (int i = 0, j = 0; i < this->length; i++) {
            if (position == i) {
                continue;
            }
            tempCell[j] = this->columns[i];
            j++;
        }
        this->clear();
        this->columns = new Cell[this->length - 1];
        for (int i = 0; i < this->length - 1; i++) {
            this->columns[i] = tempCell[i];
        }
        delete [] tempCell;
        this->length -= 1;
    //
    }
    return canDelete;
}