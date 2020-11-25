# Build

* cmake -S . -B build
* cd build
* make _(check)_

## Build options
* -DCMAKE_BUILD_TYPE=debug -> for debug
* -DCMAKE_EXPORT_COMPILE_COMMANDS -> generate compile_commands.json (for lsp)
* example : cmake -S . -B build -DCMAKE_BUILD_TYPE=debug
