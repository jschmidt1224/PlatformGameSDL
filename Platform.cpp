#include "PlatformHeader.h"
#include "myrect.h"
#include "weapons.h"
#include "sprite.h"
#include "bullet.h"
#include "block.h"
#include "player.h"
#include "explosion.h"
#include "drawing.h"

int main(int argc, char* args[])
{
    bool loop = true;
    srand(time(0));
    SDL_Event event;
    int ticks;
    int mouseX, mouseY;
    init();
    SDL_Surface *text = NULL;
    stringstream ss;
    Block newBlock(0, 0, 16, 16);
    Block drawBlock(0, 0, 16, 16);
    list<Block> blockList;
    list<Block>::iterator it_Block;
    list<Bullet> bulletList;
    list<Bullet>::iterator it_Bullet;
    list<Explosion> explosionList;
    list<Explosion>::iterator it_Explosion;

    for (int i = 0; i < LEVEL_WIDTH / 16; i++)
    {
        newBlock.rect.y = SCREEN_HEIGHT - 16;
        newBlock.rect.x = i * 16;
        blockList.push_back(newBlock);
        if (i % 3 == 0)
        {
            newBlock.rect.y = SCREEN_HEIGHT - 32;
            newBlock.rect.x = i * 16;
            blockList.push_back(newBlock);
        }
        if (i % 3 == 0)
        {
            newBlock.rect.y = SCREEN_HEIGHT - 48;
            newBlock.rect.x = i * 16;
            blockList.push_back(newBlock);
            newBlock.rect.y = SCREEN_HEIGHT - 64;
            newBlock.rect.x = i * 16;
            blockList.push_back(newBlock);
            newBlock.rect.y = SCREEN_HEIGHT - 80;
            newBlock.rect.x = i * 16;
            blockList.push_back(newBlock);
            newBlock.rect.y = SCREEN_HEIGHT - 96;
            newBlock.rect.x = i * 16;
            blockList.push_back(newBlock);
            newBlock.rect.y = SCREEN_HEIGHT - 112;
            newBlock.rect.x = i * 16;
            blockList.push_back(newBlock);
            newBlock.rect.y = SCREEN_HEIGHT - 128;
            newBlock.rect.x = i * 16;
            blockList.push_back(newBlock);
            newBlock.rect.y = SCREEN_HEIGHT - 144;
            newBlock.rect.x = i * 16;
            blockList.push_back(newBlock);
            newBlock.rect.y = SCREEN_HEIGHT - 160;
            newBlock.rect.x = i * 16;
            blockList.push_back(newBlock);
            newBlock.rect.y = SCREEN_HEIGHT - 176;
            newBlock.rect.x = i * 16;
            blockList.push_back(newBlock);
            newBlock.rect.y = SCREEN_HEIGHT - 192;
            newBlock.rect.x = i * 16;
            blockList.push_back(newBlock);
            newBlock.rect.y = SCREEN_HEIGHT - 208;
            newBlock.rect.x = i * 16;
            blockList.push_back(newBlock);
            newBlock.rect.y = SCREEN_HEIGHT - 224;
            newBlock.rect.x = i * 16;
            blockList.push_back(newBlock);
            newBlock.rect.y = SCREEN_HEIGHT - 240;
            newBlock.rect.x = i * 16;
            blockList.push_back(newBlock);
            newBlock.rect.y = SCREEN_HEIGHT - 256;
            newBlock.rect.x = i * 16;
            blockList.push_back(newBlock);
            newBlock.rect.y = SCREEN_HEIGHT - 272;
            newBlock.rect.x = i * 16;
            blockList.push_back(newBlock);
            newBlock.rect.y = SCREEN_HEIGHT - 288;
            newBlock.rect.x = i * 16;
            blockList.push_back(newBlock);
            newBlock.rect.y = SCREEN_HEIGHT - 304;
            newBlock.rect.x = i * 16;
            blockList.push_back(newBlock);
        }

    }
    if (true) //load surfaces
    {
        playerImage = load_image("playerImage.bmp");
        bullet1Image = load_image("bullet1.bmp");
        bullet2Image = load_image("bullet2.bmp");
        bullet3Image = load_image("bullet3.bmp");
        explosion1 = load_image("explosion/01.bmp", true, 255, 255, 255);
        explosion2 = load_image("explosion/02.bmp", true, 255, 255, 255);
        explosion3 = load_image("explosion/03.bmp", true, 255, 255, 255);
        explosion4 = load_image("explosion/04.bmp", true, 255, 255, 255);
        blockImage = load_image("blockImage.bmp");
        inventoryImage = load_image("inventoryImage.bmp");
    }
    Player player(32, SCREEN_HEIGHT - 32, 16, 16);
    while (loop)
    {
        ticks = SDL_GetTicks();
        //Handle Events
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                loop = false;
            }
            if (event.type == SDL_KEYDOWN)
            {
                if (event.key.keysym.sym == SDLK_w)
                {
                    bool jumped = false;
                    for (it_Block = blockList.begin(); it_Block != blockList.end(); it_Block++)
                    {
                        if (player.check_collision(it_Block->rect, 0, 1))
                        {
                            player.ySpeed = -8;
                            jumped = true;
                        }
                    }
                    if (!jumped)
                    {
                        for (it_Block = blockList.begin(); it_Block != blockList.end(); it_Block++)
                        {
                            if (player.check_collision(it_Block->rect, 1, 0))
                            {
                                player.ySpeed = -8;
                                player.xSpeed = -8;
                                jumped = true;
                            }
                        }
                    }
                    if (!jumped)
                    {
                        for (it_Block = blockList.begin(); it_Block != blockList.end(); it_Block++)
                        {
                            if (player.check_collision(it_Block->rect, -1, 0))
                            {
                                player.ySpeed = -8;
                                player.xSpeed = 8;
                                jumped = true;
                            }
                        }
                    }
                }
                if (event.key.keysym.sym == SDLK_SPACE)
                {
                    player.shoot(mouseX, mouseY, &bulletList);
                }
            }
            if (event.type == SDL_MOUSEBUTTONDOWN)
            {
                if (event.button.button == SDL_BUTTON_RIGHT)
                {
                    player.next_gun();
                }
                if (event.button.button == SDL_BUTTON_WHEELDOWN)
                {
                    if (player.power >= 6)
                        player.power -= 5;
                    else
                        player.power = 1;
                }
                if (event.button.button == SDL_BUTTON_WHEELUP)
                {
                    if (player.power == 1)
                        player.power = 5;
                    else if (player.power <= 95)
                        player.power += 5;
                    else
                        player.power = 100;
                }
            }
        }
        //Game Logic
        Uint8 *keyStates = SDL_GetKeyState(NULL);
        SDL_GetMouseState(&mouseX, &mouseY);

        player.move(keyStates);
        player.gravity();
        player.step();
        player.block_collision(blockList);

        for (it_Bullet = bulletList.begin(); it_Bullet != bulletList.end(); it_Bullet++)
        {
            it_Bullet->step();
            it_Bullet->gravity();
            for (it_Block = blockList.begin(); it_Block != blockList.end(); it_Block++)
            {
                if (it_Bullet->check_collision(it_Block->rect))
                {
                    if (it_Bullet->explode)
                    {
                        create_explosion(it_Bullet->rect.x - 8, it_Bullet->rect.y - 8, &explosionList);
                        it_Block = blockList.erase(it_Block);
                    }
                    it_Bullet = bulletList.erase(it_Bullet);
                }
            }
        }
        //Clear screen
        SDL_FillRect(screen, &screen->clip_rect, SDL_MapRGB(screen->format, 255, 255, 255));
        //Draw to screen
        player.draw();
        bulletList.remove_if(bullet_dead);
        explosionList.remove_if(explosion_dead);
        for (it_Block = blockList.begin(); it_Block != blockList.end(); it_Block++)
        {
            it_Block->draw();
        }
        for (it_Bullet = bulletList.begin(); it_Bullet != bulletList.end(); it_Bullet++)
        {
            it_Bullet->draw();
        }
        for (it_Explosion = explosionList.begin(); it_Explosion != explosionList.end(); it_Explosion++)
        {
            it_Explosion->draw();
        }
        //Draw inventory and status bars
        draw_inventory(player);

        //Show screen
        SDL_Flip(screen);

        if (SDL_GetTicks() - ticks < 1000 / FPS)
        {
            SDL_Delay((1000 / FPS) - (SDL_GetTicks() - ticks));
        }
    }
    if (true) //free surfaces
    {
        SDL_FreeSurface(playerImage);
        SDL_FreeSurface(bullet1Image);
        SDL_FreeSurface(bullet2Image);
        SDL_FreeSurface(bullet3Image);
        SDL_FreeSurface(explosion1);
        SDL_FreeSurface(explosion2);
        SDL_FreeSurface(explosion3);
        SDL_FreeSurface(explosion4);
        SDL_FreeSurface(blockImage);
        SDL_FreeSurface(inventoryImage);
        SDL_FreeSurface(text);
        TTF_CloseFont(font);
    }

    //quit SDL
    TTF_Quit();
    SDL_Quit();
    return 0;
}

