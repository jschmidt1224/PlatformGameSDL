
class Player : public Sprite
{
    public:
    Player(int x, int y, int w, int h) : Sprite(x, y, w, h)
    {
        ammo = 60;
        power = 100;
        currentGun = 0;
        guns[0].size = 3;
        guns[0].speed = 20;
        guns[0].reload = 0;
        guns[1].size = 2;
        guns[1].speed = 15;
        guns[1].reload = 0;
        guns[2].size = 1;
        guns[2].speed = 10;
        guns[2].reload = 0;
    }
    int ammo, currentGun, power;
    Gun guns[3];
    void draw();
    void gravity();
    void shoot(int x, int y, list<Bullet>* L);
    void block_collision(list<Block>& L);
    void next_gun();
    float move_to_collision(list<Block>& L);
    float move_to_collisionx(list<Block>& L);
    void move(Uint8 *keys);
};


void Player::draw()
{
    camera.x = (rect.x + 2) - (SCREEN_WIDTH - 256) / 2;
    camera.y = (rect.y + 2) - SCREEN_HEIGHT / 2;

    if (camera.x < 0) camera.x = 0;
    if (camera.y < 0) camera.y = 0;
    if (camera.x > LEVEL_WIDTH - SCREEN_WIDTH + 256) camera.x = LEVEL_WIDTH - SCREEN_WIDTH + 256;
    if (camera.y > LEVEL_HEIGHT - SCREEN_HEIGHT) camera.y = LEVEL_HEIGHT - SCREEN_HEIGHT;

    draw_surface(rect.x, rect.y, playerImage, screen);
}

void Player::move(Uint8 *keys)
{
    if (keys[SDLK_UP] || keys[SDLK_w])
    {
        //accelerate(0, -1);
    }
    if (keys[SDLK_DOWN] || keys[SDLK_s])
    {
        //accelerate(0, 1);
    }
    if (keys[SDLK_LEFT] || keys[SDLK_a])
    {
        accelerate(-1, 0);
    }
    if (keys[SDLK_RIGHT] || keys[SDLK_d])
    {
        accelerate(1, 0);
    }
    if (!keys[SDLK_LEFT] && !keys[SDLK_RIGHT])
    {
        decelerate(true, false);
    }
}

void Player::gravity()
{
    accelerate(0, .5);
}

void Player::block_collision(list<Block>& L)
{
    list<Block>::iterator it;
    list<Block> L2;
    bool colx, coly;
    float xtemp, ytemp;
    for (it = L.begin(); it != L.end(); it++)
    {
        if (check_collision(it->rect))
        {
            L2.push_back(*it);
            it->col2 = true;
        }
    }
    colx = coly = false;
    xtemp = rect.x;
    for (it = L2.begin(); it != L2.end(); it++)
    {
        if (check_collision(it->rect, xPrev - rect.x - .5 * sign(xSpeed), 0))
        {
            coly = true;
        }
        if (check_collision(it->rect, 0, yPrev - rect.y - .5))
        {
            colx = true;
        }
    }
    if (L2.size() > 0)
    {
        if (!colx && !coly)
        {
            rect.y = move_to_collision(L2);
            ySpeed = 0;
        }
        if (colx && !coly)
        {
            rect.x = move_to_collisionx(L2); //move_to_collision(L2, false);
            xSpeed = 0;
            ySpeed /= 2;
        }
        if (!colx && coly)
        {
            rect.y = move_to_collision(L2);
            ySpeed = 0;
        }
        if (colx && coly)
        {
            rect.y = move_to_collision(L2);
            ySpeed = 0;
            rect.x = move_to_collisionx(L2);
            xSpeed = 0;
         }
    }
}

float Player::move_to_collision(list<Block>& L)
{
    list<Block>::iterator it;
        float pos = yPrev;
        for (int i = 1; i <= 10; i++)
        {
            for (it = L.begin(); it != L.end(); it++)
            {
                if (check_collision(it->rect, xPrev - rect.x - sign(xSpeed) * .5, pos - rect.y))
                {
                    if (yPrev <= it->rect.y)
                        return it->rect.y - rect.h;
                    else
                        return it->rect.y + it->rect.h;
                }
            }
            pos = yPrev + i * ySpeed / 10;
        }
        return yPrev;
}

float Player::move_to_collisionx(list<Block>& L)
{
    list<Block>::iterator it;
        float pos = xPrev;
        for (int i = 1; i <= 10; i++)
        {
            for (it = L.begin(); it != L.end(); it++)
            {
                if (check_collision(it->rect, pos - rect.x, yPrev - rect.y - sign(ySpeed) * .5))
                {
                    if (xPrev < it->rect.x)
                        return it->rect.x - rect.w;
                    else
                        return it->rect.x + it->rect.w;
                }
            }
            pos = xPrev + i * xSpeed / 10;
        }
        return xPrev;
}

void Player::shoot(int x, int y, list<Bullet>* L)
{
    if (ammo > 0)
    {
        create_bullet(rect.x, rect.y, x + camera.x, y + camera.y, (power / 100.0) * guns[currentGun].speed, guns[currentGun].size, rand() % 5, !(rand() % 5), L);
        ammo;
    }
}

void Player::next_gun()
{
    if (currentGun < 2)
        currentGun++;
    else
        currentGun = 0;

}

