
class Explosion : public Sprite
{
    public:
    Explosion(int x, int y, int w, int h) : Sprite(x, y, w, h) {xSpeedMax = 10; count = 0;}
    int count;
    void draw();
};

void Explosion::draw()
{
    switch ((count / 5) % 4)
    {
        case 0:
        draw_surface(rect.x, rect.y, explosion1, screen);
        break;
        case 1:
        draw_surface(rect.x, rect.y, explosion2, screen);
        break;
        case 2:
        draw_surface(rect.x, rect.y, explosion3, screen);
        break;
        case 3:
        draw_surface(rect.x, rect.y, explosion4, screen);
    }
    count++;
}

bool explosion_dead(Explosion a)
{
    return (a.count > 20);
}

void create_explosion(float x, float y, list<Explosion> *L)
{
    Explosion newExpl(0, 0, 16, 16);
    newExpl.rect.x = x;
    newExpl.rect.y = y;
    L->push_back(newExpl);
}
