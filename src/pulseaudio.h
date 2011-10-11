#ifndef PASYSTRAY_PULSEAUDIO_H
#define PASYSTRAY_PULSEAUDIO_H

#include <pulse/pulseaudio.h>

#include "menu_info.h"

void pulseaudio_init(menu_infos_t* mis);
void pulseaudio_prepare_context();
void pulseaudio_connect();
void pulseaudio_start();

void context_state_cb(pa_context* c, void* userdata);

void subscribed_cb(pa_context* c, int success, void* userdata);
void event_cb(pa_context* c, pa_subscription_event_type_t t, uint32_t idx, void* userdata);

void add_server_cb(pa_context* c, const pa_server_info* i, void* userdata);
void add_sink_cb(pa_context* c, const pa_sink_info* i, int is_last, void* userdata);
void remove_sink(menu_info_t* mi, uint32_t idx);
void add_source_cb(pa_context* c, const pa_source_info* i, int is_last, void* userdata);
void remove_source(menu_info_t* mi, uint32_t idx);
void add_sink_input_cb(pa_context* c, const pa_sink_input_info* i, int is_last, void* userdata);
void remove_sink_input(menu_info_t* mi, uint32_t idx);
void add_source_output_cb(pa_context* c, const pa_source_output_info* i, int is_last, void* userdata);
void remove_source_input(menu_info_t* mi, uint32_t idx);

void quit(const char* msg);

#endif /* PASYSTRAY_PULSEAUDIO_H */