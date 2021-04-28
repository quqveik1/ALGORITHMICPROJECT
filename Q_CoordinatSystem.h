#pragma once

//#include "Q_Vector.h"
#include "TXLib.h"
#include "Q_Vector.h"
#include "math.h"
//#include "Config.h"
//#include "Q_Ball.h"

double humanRound (double delta);
Vector makePerpendikularLine(const Vector &mainVector);
void drawArrows (const Vector &mainVector, const Vector &startArrowPoint);

struct coordinatSysConfig 
{
    int font = 20;
};


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

    public:
        Vector startPosPix_;
        Vector finishPosPix_;
        Vector coorSize_;
	    Vector scalePix_;
        Vector nullCoor_;
        coordinatSysConfig config_;

    private: Rect   sysBorderPix_ = {startPosPix_, scalePix_};

    public: Vector intepretK_ = {1, 1}; //= scalePix / coorSize;

    public: coordinatSys ();
    public: coordinatSys (Vector startPosPix, Vector finishPosPix, Vector nullCoor);
            Vector drawFunc (const char *func);



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

/*
Vector coordinatSys::drawFunc (const char *func)
{
    int l = strlen (func);
    double y = 0;
    int temp = 0;

    for (int x = 0; x < (finishPosPix_ - nullCoor_).x; x++)
    {

        for (int i = 0; i < l; i++)
        {
            if (func[i] == 'x')
            {
                if (func[i + 1] == '^')
                {
                    sscanf ((char *)func[i + 2], "%lf", temp);
                    y += pow (x, temp);
                }
                if (func[i + 1] == '*')
                {
                    sscanf ((char *)func[i + 2], "%lf", temp);
                }
            }
        }
    }
}
*/
 

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
    txSetFillColor (RGB (240, 240, 240));
    txRectangle (startPosPix_.x, startPosPix_.y, finishPosPix_.x, finishPosPix_.y);

    txSetColor (RGB (120, 120, 120), 3);
    txSetFillColor (RGB (120, 120, 120));
    txLine (nullCoor_.x, finishPosPix_.y, nullCoor_.x, startPosPix_.y);
    drawArrows ({nullCoor_.x - nullCoor_.x, startPosPix_.y - finishPosPix_.y}, {nullCoor_.x, startPosPix_.y});

    txLine (startPosPix_.x, nullCoor_.y, finishPosPix_.x, nullCoor_.y);
    drawArrows ({finishPosPix_.x - startPosPix_.x, -nullCoor_.y + nullCoor_.y}, {finishPosPix_.x, nullCoor_.y});
    txSetColor (RGB (200, 200, 200), 1);



    /*
    Vector roundDelta = {(humanRound ($((($ (finishPosPix_.x) - $ (startPosPix_.x)) * $ (intepretK_.x)) / $ (nDelta.x)))),
                         (humanRound ($((($ (finishPosPix_.y) - $ (startPosPix_.y)) * $ (intepretK_.y)) / $ (nDelta.y))))
                        };
                        */

    Vector roundDelta = {(humanRound (((( (finishPosPix_.x) -  (startPosPix_.x))) /  (nDelta.x)))),
                         (humanRound (((( (finishPosPix_.y) -  (startPosPix_.y))) /  (nDelta.y))))
                        };

    char text[20] = {};


    txSelectFont ("Arial", config_.font);

    Vector num = {};
    for (int x = 0; x < nDelta.x * 10; x++)
    {
        sprintf (text, "%lg", num.x);
        if (nullCoor_.x + (num.x * intepretK_.x) < finishPosPix_.x && startPosPix_.x < nullCoor_.x + (num.x * intepretK_.x))
        {
            txLine (nullCoor_.x + (num.x * intepretK_.x), finishPosPix_.y, nullCoor_.x + (num.x * intepretK_.x), startPosPix_.y);
            txTextOut (nullCoor_.x + (num.x * intepretK_.x), nullCoor_.y, text);
        }
        if (nullCoor_.x - (num.x * intepretK_.x) < finishPosPix_.x && startPosPix_.x < nullCoor_.x - (num.x * intepretK_.x))
        {
            txLine (nullCoor_.x - (num.x * intepretK_.x), finishPosPix_.y, nullCoor_.x - (num.x * intepretK_.x), startPosPix_.y);
            txTextOut (nullCoor_.x - (num.x * intepretK_.x), nullCoor_.y, text);
        }
        num.x += roundDelta.x;
    }

    for (int y = 0; y < nDelta.y * 10; y++)
    {
        sprintf (text, "%lg", num.y);
        if (nullCoor_.y + (num.y * intepretK_.y) < finishPosPix_.y && startPosPix_.y < nullCoor_.y + (num.y * intepretK_.y))
        {
            txTextOut (nullCoor_.x, nullCoor_.y + (num.y * intepretK_.y), text);
            txLine (startPosPix_.x,  nullCoor_.y + (num.y * intepretK_.y), finishPosPix_.x, nullCoor_.y + (num.y * intepretK_.y));
        }

        if (nullCoor_.y - (num.y * intepretK_.y) < finishPosPix_.y && startPosPix_.y < nullCoor_.y - (num.y * intepretK_.y))
        {
            txTextOut (nullCoor_.x, nullCoor_.y - (num.y * intepretK_.y), text);
            txLine (startPosPix_.x,  nullCoor_.y - (num.y * intepretK_.y), finishPosPix_.x, nullCoor_.y - (num.y * intepretK_.y));
        }

        num.y += roundDelta.y;
    }

}

void drawArrows (const Vector &mainVector, const Vector &finishPoint)
{
    Vector perpendicular1 = makePerpendikularLine (mainVector);
    Vector perpendicular2 = perpendicular1 * -1;

    Vector arrow1 = perpendicular1 * 0.01 - mainVector * 0.02;
    Vector arrow2 = perpendicular2 * 0.01 - mainVector * 0.02;

    Vector arrow1finishPoint = ((arrow1) + finishPoint);
    Vector arrow2finishPoint = ((arrow2) + finishPoint);

    txLine (finishPoint.x, finishPoint.y, arrow1finishPoint.x, arrow1finishPoint.y);
    txLine (finishPoint.x, finishPoint.y, arrow2finishPoint.x, arrow2finishPoint.y);
}

Vector makePerpendikularLine(const Vector &mainVector)
{
    Vector perpendikularLine = {};
    perpendikularLine.x =   mainVector.y;
    perpendikularLine.y = -(mainVector.x);

    return perpendikularLine;
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
