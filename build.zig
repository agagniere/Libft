const std = @import("std");

pub fn build(b: *std.Build) void {
    const target = b.standardTargetOptions(.{});
    const optimize = b.standardOptimizeOption(.{});

    const lib = b.addStaticLibrary(.{
        .name = "ft",
        .target = target,
        .optimize = optimize,
    });
    lib.addCSourceFiles(.{ .root = b.path("src/ft_array"), .files = &.{ "fta_alloc.c", "fta_append.c", "fta_clear.c", "fta_clearf.c", "fta_iter.c", "fta_iteri.c", "fta_new.c", "fta_overwrite.c", "fta_popback.c", "fta_popindex.c", "fta_release.c", "fta_replace.c", "fta_reserve.c", "fta_resize.c", "fta_string.c", "fta_swap.c", "fta_trim.c" } });
    lib.addCSourceFiles(.{ .root = b.path("src/ft_string_legacy"), .files = &.{ "ft_strcat.c", "ft_strchr.c", "ft_strclr.c", "ft_strcmp.c", "ft_strcpy.c", "ft_strdel.c", "ft_strdup.c", "ft_strequ.c", "ft_striter.c", "ft_striteri.c", "ft_strjoin.c", "ft_strlcat.c", "ft_strlen.c", "ft_strmap.c", "ft_strmapi.c", "ft_strncat.c", "ft_strncmp.c", "ft_strncpy.c", "ft_strnequ.c", "ft_strnew.c", "ft_strnstr.c", "ft_strrchr.c", "ft_strrev.c", "ft_strsplit.c", "ft_strstr.c", "ft_strsub.c", "ft_strtrim.c", "wide_char.c" } });
    lib.addCSourceFiles(.{ .root = b.path("src/ft_deque"), .files = &.{ "ft_deque.c", "ft_stack.c", "ft_stack_pushswap.c", "ftq_getters.c", "ftq_is_sorted.c", "ftq_iter.c", "ftq_pop.c", "ftq_private.c", "ftq_private_getters.c", "ftq_private_utils.c", "ftq_push.c", "ftq_string.c" } });
    lib.addCSourceFiles(.{ .root = b.path("src/ft_printf"), .files = &.{ "db_printf.c", "ft_convert.c", "ft_convert_characters.c", "ft_convert_extra.c", "ft_convert_integers.c", "ft_printf.c", "ft_string_vprintf.c", "ft_vasprintf.c", "ft_vprintf.c", "string_append_format.c" } });
    lib.addCSourceFiles(.{ .root = b.path("src"), .files = &.{ "ft_atoi.c", "ft_bzero.c", "ft_ctype.c", "ft_dict.c", "ft_hashes.c", "ft_heap.c", "ft_itoa.c", "ft_itoa_base.c", "ft_list/ftl_add.c", "ft_list/ftl_del.c", "ft_list/ftl_new.c", "ft_list/ftl_pop.c", "ft_malloc.c", "ft_memalloc.c", "ft_memccpy.c", "ft_memchr.c", "ft_memcmp.c", "ft_memcpy.c", "ft_memdel.c", "ft_memdup.c", "ft_memmove.c", "ft_memset.c", "ft_memswp.c", "ft_modf.c", "ft_print_memory.c", "ft_putchar.c", "ft_putchar_fd.c", "ft_putendl.c", "ft_putendl_fd.c", "ft_putnbr.c", "ft_putnbr_fd.c", "ft_putstr.c", "ft_putstr_fd.c", "ft_raii.c", "ft_realloc.c", "ft_string.c", "ft_tree/ftt_clear.c", "ft_tree/ftt_debug.c", "ft_tree/ftt_push.c", "ft_variadic.c", "get_next_line.c", "is_refresh.c" } });
    lib.addIncludePath(b.path("include"));
    lib.installHeadersDirectory(b.path("include"), "libft", .{});
    b.installArtifact(lib);
}
