## Overview

This project is a simple C HTTP server that serves a basic HTML page. It utilizes the `HttpServer` library to handle HTTP requests and responses.

## Features

- Basic HTTP server functionality.
- Serves an HTML file.

## Project Structure

### Prerequisites

- C/C++ Compiler and Debugger (GCC, Clang)
- Make utility
- Standard development tools

## Build & Run

To build the project, navigate to the project directory and run:

```sh
make -f Makefile.linux all  # For Linux
make -f Makefile.windows all  # For Windows
make -f Makefile.wine all  # For Wine (Linux cross compile for Windows)
make -f Makefile.web all  # For Webassembly (Emscripten or wasmtime)
```

To clean the build artifacts and rebuild:

```sh
make -f Makefile.linux clean  # For Linux
make -f Makefile.windows clean  # For Windows
make -f Makefile.wine clean  # For Wine (Linux cross compile for Windows)
make -f Makefile.web clean  # For Webassembly (Emscripten or wasmtime)

make -f Makefile.linux do  # For Linux
make -f Makefile.windows do  # For Windows
make -f Makefile.wine do  # For Wine (Linux cross compile for Windows)
make -f Makefile.web do  # For Webassembly (Emscripten or wasmtime)

```

To run the server:

```sh
make -f Makefile.linux exe  # For Linux
make -f Makefile.windows exe  # For Windows
make -f Makefile.wine exe  # For Wine (Linux cross compile for Windows)
make -f Makefile.web exe  # For Webassembly (Emscripten or wasmtime)
```

# Build Steps

1. Navigate to the project directory.
2. Run `make -f Makefile.(os) all` to build the project, where `(os)` is the target operating system (`linux`, `windows`, `wine`, `web`).
3. To clean the build artifacts and rebuild, run `make -f Makefile.(os) clean && make -f Makefile.(os) do`.
4. To execute the server, run `make -f Makefile.(os) exe`.