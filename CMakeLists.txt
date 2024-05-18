add_library(windows-message-lookup windows-message-lookup.c)

# Default to UNICODE build
# Comment this out if you're using the Windows ANSI functions (unlikely)
add_compile_definitions(UNICODE)
