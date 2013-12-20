
class Block : public Sprite
{
    public:
    Block(int x, int y, int w, int h) : Sprite(x, y, w, h) {}
    void draw();
    bool col1, col2;
};

void Block::draw()
{
    //if (col2)
       // draw_surface(rect.x, rect.y, playerImage, screen);
    //else
        draw_surface(rect.x, rect.y, blockImage, screen);
    //if (col1)
        //draw_surface(rect.x, rect.y, bullet1Image, screen);


    col1 = col2 = false;
}
