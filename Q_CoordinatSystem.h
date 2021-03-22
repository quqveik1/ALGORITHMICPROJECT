#pragma once

//#include "Q_Vector.h"
#include "TXLib.h"
#include "Q_Vector.h"
//#include "Config.h"
//#include "Q_Ball.h"

double humanRound (double delta);


struct Rect
{
    Vector pos;
    Vector size;

    double left  () const { return this->pos.x; }
    double top   () const { return this->pos.y; }
    double right () const { return this->size.x + this->pos.x; }
    double bottom() const { return this->size.y + this->pos.y; }
};


class coordinatSys
{

    public: Vector startPosPix_;
    public: Vector finishPosPix_;
    public: Vector coorSize_;
	public: Vector scalePix_;
    public: Vector nullCoor_;

    private: Rect   sysBorderPix_ = {startPosPix_, scalePix_};

    private: Vector intepretK_ = {1, 1}; //= scalePix / coorSize;

    public: coordinatSys ();
    public: coordinatSys (Vector startPosPix, Vector finishPosPix, Vector nullCoor);



	//public: Vector drawCircle (Ball ball);
    public: Vector drawCircle (Vector vector, double r = 10);
    public: void drawLine (Vector startLPos, Vector finishLPos, COLORREF color = 1);
    public: Vector interpret (Vector vector);
    public: void drawAxis (Vector nDelta);
};


coordinatSys::coordinatSys (Vector startPosPix, Vector finishPosPix, Vector nullCoor) :
    startPosPix_ (startPosPix),
    finishPosPix_ (finishPosPix),
    nullCoor_ (nullCoor)
{
}

coordinatSys::coordinatSys () :
    startPosPix_ ({0, 0}),
    finishPosPix_ ({(double) txGetExtentX (), (double) txGetExtentY ()}),
    scalePix_ ({(double) txGetExtentX (), (double) txGetExtentY ()}),
    coorSize_ ({(double) txGetExtentX (), (double) txGetExtentY ()}),
    nullCoor_ ({(double) txGetExtentX ()/2, (double) txGetExtentY ()/2})
{
    intepretK_.x = 1;
    intepretK_.y = -1;
}

/*
Vector coordinatSys::drawCircle (Ball ball)
{
    //Vector intepretK = {}; //= scalePix / coorSize;

    //intepretK.x = scalePix.x / coorSize.x;
    //intepretK.y = scalePix.y / coorSize.y;

	Vector pixPos = interpret (ball.pos);

    double rScale = (intepretK_.x + intepretK_.y) / 2;

    //$s
    txSetFillColor (ball.color);

    //if (pixPos.x > sysBorderPix_.left () && pixPos.y > sysBorderPix_.top () && pixPos.x < sysBorderPix_.right () && pixPos.y < sysBorderPix_.bottom ())
    if (pixPos.x < (startPosPix_.x + scalePix_.x) && pixPos.x > startPosPix_.x)
    {
        if (pixPos.y < (startPosPix_.y + scalePix_.y) && pixPos.y > startPosPix_.y)
        {
            txCircle (pixPos.x, pixPos.y, ball.r * rScale);
        }
    }
    //_getch ();

    return pixPos;

}
*/

void coordinatSys::drawLine (Vector startLPos, Vector finishLPos, COLORREF color)
{
    Vector startLPixPos = interpret (startLPos);

    Vector finishLPixPos = interpret (finishLPos);

    $s

    txSetFillColor (color);

    txLine (startLPos.x, startLPos.y, finishLPos.x, finishLPos.y);

}

Vector coordinatSys::drawCircle (Vector vector, double r)
{
    //Vector intepretK = {}; //= scalePix / coorSize;

    //intepretK.x = scalePix.x / coorSize.x;
    //intepretK.y = scalePix.y / coorSize.y;

    Vector pixPos = interpret(vector);

    double rScale = r;//(intepretK_.x + intepretK_.y) / 2;

    //if (pixPos.x > sysBorderPix_.left() && pixPos.y > sysBorderPix_.top() && pixPos.x < sysBorderPix_.right() && pixPos.y < sysBorderPix_.bottom())
    if (pixPos < finishPosPix_)
    {
        if (pixPos > startPosPix_)
        {
            txCircle (pixPos.x, pixPos.y, r * rScale);
        }
    }

    return pixPos;

}

void coordinatSys::drawAxis (Vector nDelta)
{
    txLine (nullCoor_.x, finishPosPix_.y, nullCoor_.x, startPosPix_.y);
    txLine (startPosPix_.x, nullCoor_.y, finishPosPix_.x, nullCoor_.y);


    /*
    Vector roundDelta = {(humanRound ($((($ (finishPosPix_.x) - $ (startPosPix_.x)) * $ (intepretK_.x)) / $ (nDelta.x)))),
                         (humanRound ($((($ (finishPosPix_.y) - $ (startPosPix_.y)) * $ (intepretK_.y)) / $ (nDelta.y))))
                        };
                        */

    Vector roundDelta = {(humanRound (((( (finishPosPix_.x) -  (startPosPix_.x)) *  (intepretK_.x)) /  (nDelta.x)))),
                         (humanRound (((( (finishPosPix_.y) -  (startPosPix_.y)) *  (intepretK_.y)) /  (nDelta.y))))
                        };

    char text[20] = {};


    txSelectFont ("Arial", 14);

    Vector num = {};
    for (int x = 0; x < nDelta.x * 10; x++)
    {
        sprintf (text, "%lg", num.x);
        if (nullCoor_.x + (num.x * intepretK_.x) < finishPosPix_.x && startPosPix_.x < nullCoor_.x + (num.x * intepretK_.x))
            txTextOut (nullCoor_.x + (num.x * intepretK_.x), nullCoor_.y, text);
        num.x += roundDelta.x;
    }

    for (int y = 0; y < nDelta.y * 10; y++)
    {
        sprintf (text, "%lg", num.y);
        if (nullCoor_.y + (num.y * intepretK_.y) < finishPosPix_.y && startPosPix_.y < nullCoor_.y + (num.y * intepretK_.y))
            txTextOut (nullCoor_.x, nullCoor_.y + (num.y * intepretK_.y), text);
        num.y += roundDelta.y;
    }

}


double humanRound (double delta)
{
    /*
    * 0.1 -> 0.1
    * 0.12 -> 0.1
    * 0.2  -> .
    * 0.23 -> 0.25
    * 0.25 -> 0.25
    * 0.28 -> 0.25
    * 0.3  -> 0.25
    * 0.35 - >0.5
    * 0.4  0.5
    * 0.5  0.5
    * 0.6  0.5
    * 0.7  1
    * 0.8  1
    * 0.9  1
    * 3.14 exp:1
    *
    */

    //printf ("\n::%d::\n", delta);
    delta = fabs (delta);
    double exp = log10 (delta);
    double mantissa = delta / (pow (10, ceil (exp)));

    //double mantissa = frexp (delta, &order);

    //printf ("Delta: %lf\tExp: %lf \tMantissa: %lf\n", delta, exp, mantissa);

    if (mantissa < 0.15) mantissa = 0.1;
    if (0.15 <= mantissa && mantissa < 0.23) mantissa = 0.2;
    if (0.23 <= mantissa && mantissa < 0.35) mantissa = 0.25;
    if (0.35 <= mantissa && mantissa < 0.65) mantissa = 0.5;
    if (0.65 <= mantissa && mantissa <= 1)   mantissa = 1;

    //printf ("delta: %lf, fDelta: %lf\n", delta, mantissa * pow (10, ceil(exp)));


    return mantissa * pow (10, ceil(exp));
}


Vector coordinatSys::interpret (Vector vector)
{
    return nullCoor_ + (intepretK_ * vector);
}
