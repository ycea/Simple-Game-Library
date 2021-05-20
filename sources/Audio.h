#ifndef AUDIO_H_INCLUDED
#define AUDIO_H_INCLUDED
#include <cstdint>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <unordered_map>
#include <string>


class Audio
{
private:
    typedef std::unordered_map<std::string, Mix_Chunk*> map_of_sound_eff;
    map_of_sound_eff table_of_sound_eff;
    typedef std::unordered_map<std::string, Mix_Music*> map_of_music;
    map_of_music table_of_music;

public:
    Audio();
    int make_sound(std::string file);
    int play_music(std::string file);
};

#endif // AUDIO_H_INCLUDED
