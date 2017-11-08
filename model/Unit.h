#pragma once

#ifndef _UNIT_H_
#define _UNIT_H_

namespace model {
    class Unit {
    private:
        long long id;
        double x;
        double y;
    protected:
        Unit(long long id, double x, double y);
    public:
        long long getId() const;
        double getX() const;
        double getY() const;

        double getDistanceTo(double x, double y) const;
        double getDistanceTo(const Unit& unit) const;
        double getSquaredDistanceTo(double x, double y) const;
        double getSquaredDistanceTo(const Unit& unit) const;

        virtual ~Unit();
    };
}

#endif
