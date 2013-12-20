
class Sprite
{
    public:
    Rectangle rect;
    int check_collision(Rectangle, int, int);
    Sprite(int, int, int, int);
    void accelerate(float, float);
    void decelerate(bool ,bool);
    void step();
    void limit_speed();
    float xPrev, yPrev;
    float xSpeed, ySpeed, xSpeedMax, ySpeedMax;
    int lastDir;
};

int Sprite::check_collision(Rectangle rect2, int x = 0, int y = 0)
{
    float aT, bT, aB, bB, aR, bR, aL, bL;
    aT = rect.y + y;
    bT = rect2.y;
    aB = aT + rect.h;
    bB = bT + rect2.h;
    aL = rect.x + x;
    bL = rect2.x;
    aR = aL + rect.w;
    bR = bL + rect2.w;
    int ret;
    if(aB <= bT)
    {
        return 0;
    }
    else if(aT >= bB)
    {
        return 0;
    }
    else if(aR <= bL)
    {
        return 0;
    }
    else if( aL >= bR)
    {
        return 0;
    }
    if (aL < bR)
        ret+= 1;
    if (aB > bT)
        ret += 10;
    if (aR > bL)
        ret += 100;
    if (aT < bB)
        ret += 1000;

    return ret;
}

Sprite::Sprite(int x, int y, int w, int h)
{
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;
    xPrev = x; yPrev = y;
    xSpeed = 0; ySpeed = 0;
    xSpeedMax = 6; ySpeedMax = 16;
    lastDir = 0;
}


void Sprite::accelerate(float x, float y)
{
    xSpeed += x;
    ySpeed += y;
}

void Sprite::decelerate(bool x, bool y)
{
    if (x)
    {
        if (xSpeed > 0)
        {
            lastDir = 0;
            if (xSpeed > 0.5)
                xSpeed -= .5;
            else
                xSpeed = 0;
        }
        if (xSpeed < 0)
        {
            lastDir = 0;
            if (xSpeed < -0.5)
                xSpeed += .5;
            else
                xSpeed = 0;
        }
    }
    if (y)
    {
        if (ySpeed > 0)
        {
            lastDir = 0;
            if (ySpeed > 0.5)
                ySpeed -= .5;
            else
                ySpeed = 0;
        }
        if (ySpeed < 0)
        {
            lastDir = 0;
            if (ySpeed < -0.5)
                ySpeed += .5;
            else
                ySpeed = 0;
        }
    }
}

void Sprite::step()
{
    limit_speed();
    xPrev = rect.x;
    yPrev = rect.y;
    rect.x += xSpeed;
    rect.y += ySpeed;
}

void Sprite::limit_speed()
{
    if (xSpeed > xSpeedMax)
    {
        xSpeed = xSpeedMax;
    }
    if (xSpeed < - xSpeedMax)
    {
        xSpeed = - xSpeedMax;
    }
    if (ySpeed > ySpeedMax)
    {
        ySpeed = ySpeedMax;
    }
    if (ySpeed < - ySpeedMax)
    {
        ySpeed = - ySpeedMax;
    }
}






