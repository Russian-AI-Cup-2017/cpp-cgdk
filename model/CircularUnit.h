#pragma once

#ifndef _CIRCULAR_UNIT_H_
#define _CIRCULAR_UNIT_H_

#include "Unit.h"

namespace model {
    class CircularUnit : public Unit {
    private:
        double radius;
    protected:
        CircularUnit(long long id, double x, double y, double radius);
    public:
        double getRadius() const;

        virtual ~CircularUnit();
    };
}

#endif
