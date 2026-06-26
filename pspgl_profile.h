#ifndef PSPGL_PROFILE_H
#define PSPGL_PROFILE_H

struct pspgl_profile_stats {
	unsigned long long texture_bind_calls;
	unsigned long long texture_bind_changes;
	unsigned long long texture_bind_redundant;
	unsigned long long texture_objects_created;
	unsigned long long texture_cache_flush_requests;
	unsigned long long texture_cache_flush_commands;
	unsigned long long texture_cache_sync_requests;
	unsigned long long texture_cache_sync_commands;
	unsigned long long texture_image_uploads;
	unsigned long long texture_compressed_image_uploads;
	unsigned long long texture_sub_image_uploads;
	unsigned long long texture_copy_image_uploads;
	unsigned long long texture_color_table_uploads;
	unsigned long long texture_mipmap_updates;
	unsigned long long texture_memory_modifications;
	unsigned long long texture_upload_bytes;

	unsigned long long draw_calls;
	unsigned long long draw_arrays_calls;
	unsigned long long draw_elements_calls;
	unsigned long long draw_range_elements_calls;
	unsigned long long draw_zero_count_skips;
	unsigned long long vertices_submitted;
	unsigned long long indices_submitted;
	unsigned long long array_locked_fast_paths;
	unsigned long long array_convert_paths;
	unsigned long long native_vertex_array_copies;
	unsigned long long converted_vertex_array_copies;
	unsigned long long native_vertex_array_vertices;
	unsigned long long converted_vertex_array_vertices;
	unsigned long long index_buffer_direct_paths;
	unsigned long long index_convert_paths;
	unsigned long long vertex_buffer_temp_allocations;
	unsigned long long index_buffer_temp_allocations;
	unsigned long long client_memory_draw_paths;
	unsigned long long buffer_object_draw_paths;

	unsigned long long render_setup_calls;
	unsigned long long render_prim_calls;
	unsigned long long ge_register_groups_considered;
	unsigned long long ge_register_groups_nonempty;
	unsigned long long ge_register_bit_iterations;
	unsigned long long ge_dirty_registers;
	unsigned long long ge_registers_emitted;
	unsigned long long ge_dirty_registers_not_emitted;
	unsigned long long ge_uncached_register_writes;
	unsigned long long matrix_uploads;
	unsigned long long matrix_words;

	unsigned long long buffer_pin_requests;
	unsigned long long buffer_pin_new;
	unsigned long long buffer_pin_repeated;
	unsigned long long buffer_unpins;
	unsigned long long buffer_dlist_syncs;
	unsigned long long buffer_dlist_sync_waits;
	unsigned long long buffer_vidmem_wants;

	unsigned long long command_words;
	unsigned long long command_list_submissions;
	unsigned long long command_list_rollovers;
	unsigned long long command_list_high_water_words;
	unsigned long long command_list_capacity_words;
	unsigned long long command_list_insert_space_calls;
	unsigned long long command_list_insert_space_words;
	unsigned long long command_list_insert_space_rollovers;
	unsigned long long explicit_flushes;
	unsigned long long finishes;
	unsigned long long await_completion_calls;
	unsigned long long queue_waits;
};

void pspgl_profile_reset(void);
void pspgl_profile_snapshot(struct pspgl_profile_stats *out);

#endif
