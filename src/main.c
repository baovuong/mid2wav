#include <stdio.h>
#include <fluidsynth.h>

int main(int argc, char* argv[]) {
    
    // declaration
    fluid_settings_t* settings;
    fluid_synth_t* synth;
    fluid_player_t* player;
    fluid_audio_driver_t* adriver;
    
    // definition
    settings = new_fluid_settings();
    fluid_settings_setint(settings, "synth.polyphony", 128);
    fluid_settings_setstr(settings, "audio.driver", "file");
    
    synth = new_fluid_synth(settings);
    
    player = new_fluid_player(synth);
    
    adriver = new_fluid_audio_driver(settings, synth);
    
    // cleanup
    delete_fluid_audio_driver(adriver);
    delete_fluid_player(player);
    delete_fluid_synth(synth);
    delete_fluid_settings(settings);
    
    return 0;
}