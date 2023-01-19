#include "register_types.h"

#include "core/config/engine.h"
#include "tracy_profiler.h"

void initialize_godot_tracy_module(ModuleInitializationLevel p_level) {
	ClassDB::register_class<TracyProfiler>();

	TracyProfiler::init_singleton();
	Engine::get_singleton()->add_singleton(Engine::Singleton("TracyProfiler", TracyProfiler::get_singleton()));
}

void uninitialize_godot_tracy_module(ModuleInitializationLevel p_level) {
	TracyProfiler::finalize_singleton();
}
