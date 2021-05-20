#include "Audio.h"

Audio::Audio()
{
    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0)
    {
        exit(13);
    }
}

int Audio::play_music(std::string file)
{
    // if it is not playing and not paused
    if((Mix_PlayingMusic() != 0) && (Mix_PlayingMusic() != 1))
    {
        return 0;
    }
    if(table_of_music.find(file) != table_of_music.end())
    {
        Mix_PlayMusic(table_of_music.at(file), -1);
        return 1;
    }
    else
    {
        Mix_Music *music = Mix_LoadMUS(file.c_str());
        if(music == nullptr)
        {
            return 0;
        }
        Mix_PlayMusic(music, -1);
        table_of_music.insert(std::pair(file, music));
    }

}
