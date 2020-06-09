#ifndef _struct_h_
#define _struct_h_

typedef struct {
    int mat;
    int disk;
    int hist;
    int it;
} marks;

typedef struct {
    enum OFF_SET_LIN {
        YES_LIN = 'Y',
        NO_LIN = 'N'
    } OFF_SET_LIN;
    enum OFF_SET_PHY {
        YES_PHY = 'Y',
        NO_PHY = 'N'
    } OFF_SET_PHY;
    enum OFF_SET_ENG {
        YES_ENG = 'Y',
        NO_ENG = 'N'
    } OFF_SET_ENG;
    enum OFF_SET_LAB {
        YES_LAB = 'Y',
        NO_LAB = 'N'
    } OFF_SET_LAB;
} offset;

typedef struct {
        int primary_key;
        char name[15];
        char initials[2];
        char group[15];
        enum SEX {
                SEX_F = 'F',
                SEX_M = 'M'
        } SEX;
        marks m;
        offset of;
} student;

#endif 
