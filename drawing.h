
void draw_inventory(Player player)
{
    SDL_Surface * text;
    stringstream ss;
    draw_rect(SCREEN_WIDTH - 256, 0, 256, SCREEN_HEIGHT, 125, 125, 125, screen);
    draw_rect(SCREEN_WIDTH - 254, 2, 252, SCREEN_HEIGHT - 4, 192, 192, 192, screen);
    draw_surface(SCREEN_WIDTH - 128 + camera.x, 0 + camera.y, inventoryImage, screen);
    draw_surface(16 + SCREEN_WIDTH - 256 + camera.x, 16 + camera.y, text, screen);
    draw_rect(SCREEN_WIDTH - 256 + 16, 16, 224, 24, 0, 0, 125, screen);
    draw_rect(SCREEN_WIDTH - 256 + 18, 18, 220 * (player.power / 100.0), 20, 100, 100, 255, screen);
    ss.str(string());
    ss << "Power: " << player.power << "%";
    TTF_SetFontStyle(font, TTF_STYLE_BOLD);
    text = TTF_RenderText_Solid(font, ss.str().c_str(), SDL_LtBlue);
    draw_surface(18 + SCREEN_WIDTH - 256 + camera.x, 16 + camera.y, text, screen);
    SDL_FreeSurface(text);
    text = TTF_RenderText_Solid(font, ss.str().c_str(), SDL_Black);
    //text = TTF_RenderText_Solid(font, "Hello", SDL_LtBlue);
    draw_surface(17 + SCREEN_WIDTH - 256 + camera.x, 15 + camera.y, text, screen);
    TTF_SetFontStyle(font, TTF_STYLE_NORMAL);
    ss.str(string());
    ss << "Inventory: ";
    SDL_FreeSurface(text);
    text = TTF_RenderText_Solid(font2, ss.str().c_str(), SDL_Black);
    //text = TTF_RenderText_Solid(font, "Hello", SDL_LtBlue);
    draw_surface(16 + SCREEN_WIDTH - 256 + camera.x, 44 + camera.y, text, screen);
    switch (player.currentGun)
    {
        case 0:
        draw_rect(SCREEN_WIDTH - 243, 61, 70, 70, 55, 255, 55, screen);
        break;
        case 1:
        draw_rect(SCREEN_WIDTH - 163, 61, 70, 70, 55, 255, 55, screen);
        break;
        case 2:
        draw_rect(SCREEN_WIDTH - 83, 61, 70, 70, 55, 255, 55, screen);
        break;
    }
    draw_rect(SCREEN_WIDTH - 240, 64, 64, 64, 125, 125, 125, screen);
    draw_rect(SCREEN_WIDTH - 160, 64, 64, 64, 125, 125, 125, screen);
    draw_rect(SCREEN_WIDTH - 80, 64, 64, 64, 125, 125, 125, screen);
    //Bullets
    draw_rect(SCREEN_WIDTH - 240, 144, 64, 64, 125, 125, 125, screen);
    draw_rect(SCREEN_WIDTH - 160, 144, 64, 64, 125, 125, 125, screen);
    draw_rect(SCREEN_WIDTH - 80, 144, 64, 64, 125, 125, 125, screen);
    draw_rect(SCREEN_WIDTH - 240, 224, 64, 64, 125, 125, 125, screen);
    draw_rect(SCREEN_WIDTH - 160, 224, 64, 64, 125, 125, 125, screen);
    draw_rect(SCREEN_WIDTH - 80, 224, 64, 64, 125, 125, 125, screen);
    SDL_FreeSurface(text);
}
