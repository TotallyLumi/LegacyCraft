#pragma once

class Random;

class Mth
{
private:
    static const int BIG_ENOUGH_INT;

    static const float BIG_ENOUGH_FLOAT;
    static const float sinScale;

    static float *_sin;
public:
    static const float RAD_TO_GRAD;
    static const float DEGRAD;
    static const float RADDEG;

    static void init();

    static float sin( float i );
    static float cos( float i );
    static float sqrt( float x );
    static float sqrt( double x );
    static float abs( float v );
    static float clamp( float value, float min, float max );
    static float wrapDegress( float input );

    static int floor( float v );
    static int floor( double v );
    static __int64 lfloor( double v );
    static int fastFloor( double x );
    static int absFloor( double v );
    static int abs( int v );
    static int ceil( float v );
    static int clamp( int value, int min, int max );
    static int intFloorDiv( int a, int b );
    static int nextInt( Random *random, int minInclusive, int maxInclusive );

    static double absMax( double a, double b );
    static double wrapDegrees( double input );

    static bool almostEquals( double double1, double double2, double precision );
};