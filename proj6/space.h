//Header and implementtion file for the shape class.
//Richard Danylo Summer 2019

#ifndef SPACE_H
#define SPACE_H
#include <iostream>
#include "colors.h"
    
class space {
    private:
        int status; // 0 = Blank, 1 = Black, 2 = White
    public:
        space(int new_status = 0) {
            status = new_status;
        }
        void set(int new_status = 0) {
            status = new_status;
        }
        void flip() {
            if (status == 1) {
                status = 2;
            } else if (status == 2) {
                status = 1;
            }
        }
        int get() const{
            return status;
        }
        void display(ostream& outs) const{
            if (status == 0) {
                outs << " ";
            } else if (status == 1) {
                outs << BLACK << "\u25CF";
            } else if (status == 2) {
                outs << WHITE << "\u25CF";
            }
        }
};

#endif