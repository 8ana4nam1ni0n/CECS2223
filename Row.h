//
// Created by bana4m1ni0n on 8/17/17.
//

#ifndef DBSYSTEM_ROW_H
#define DBSYSTEM_ROW_H

#include "Cell.h"

class Row {

private:
    Cell * columns;
    int length;

public:
    Row();
    Row(const Cell * columns, int length);
    Row(const Row & aRow);
    ~Row();

    void setColumns(const Cell & aCell);
    void setColumns(const Cell * cells, int length);

    Cell * getColumns() const;
    Cell getColumn(int position) const;
    int getLength() const;

    bool isEmpty() const;

    bool addColumn(const Cell & aCell);
    bool updateColumn(const Cell & aCell, int position);
    bool deleteColumn(int position);

    void clear();

};


#endif //DBSYSTEM_ROW_H
