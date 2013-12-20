

class Bullet : public Sprite
{
    public:
    Bullet(int x, int y, int w, int h, int sze, bool exp, bool f) : Sprite(x, y, w, h)
    {
        xSpeedMax = 20;
        ySpeedMax = 20;
        count = 0;
        size = sze;
        explode = exp;
        fall = f;
    }
    void gravity();
    bool explode, fall;
    int count, size;
    void draw();
};


void Bullet::draw()
{
    switch (size)
    {
        case 1:
        draw_surface(rect.x, rect.y, bullet1Image, screen);
        break;
        case 2:
        draw_surface(rect.x, rect.y, bullet2Image, screen);
        break;
        case 3:
        draw_surface(rect.x, rect.y, bullet3Image, screen);
        break;
    }
    count++;
}

void Bullet::gravity()
{
    if (fall)
    {
        accelerate(0, .5);
    }
}

bool bullet_dead(Bullet a)
{
    return (a.count > 300);
}

void create_bullet(float x, float y, int mx, int my, float speed, int size, bool exp, bool fall, list<Bullet> *L)
{
    Bullet newBullet(0, 0, 4, 4, size, exp, fall);
    newBullet.rect.x = x;
    newBullet.rect.y = y;
    float vecX = mx - x;
    float vecY = my - y;
    newBullet.xSpeed = speed * vecX / (sqrt(vecX * vecX + vecY * vecY));
    newBullet.ySpeed = speed * vecY / (sqrt(vecX * vecX + vecY * vecY));
    L->push_back(newBullet);
}
