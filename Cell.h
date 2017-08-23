//
// Created by bana4m1ni0n on 8/15/17.
//

#ifndef DBSYSTEM_CELL_H
#define DBSYSTEM_CELL_H

#include <string>

class Cell {

private:
    std::string value; // member variable

public:
    // constructors
    Cell ();             // default
    Cell (std::string);  // parameter
    Cell (const Cell &); // copy
    ~Cell();             // destructor

    void setValue(std::string);  // modifiers
    void setValue(const Cell &); // function overloaded

    std::string getValue() const; //accessor

    // operators
    void operator = (std::string);
    void operator = (const Cell &aCell);

    bool operator == (std::string);
    bool operator == (const Cell &);

    bool operator != (std::string);
    bool operator != (const Cell &);

    bool operator <= (std::string);
    bool operator <= (const Cell &);

    bool operator >= (std::string);
    bool operator >= (const Cell &);

    bool operator < (std::string);
    bool operator < (const Cell &);

    bool operator > (std::string);
    bool operator > (const Cell &);

    friend std::ostream & operator << (std::ostream & out, const Cell & aCell);
    friend std::istream & operator >> (std::istream & in, Cell & aCell);

};


#endif //DBSYSTEM_CELL_H
