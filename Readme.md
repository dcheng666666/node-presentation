# Node.js presentation

## file description

| file | description|
| --                      | -- |
| v8-shell.cc             | JavaScript Shell application using V8 |
| v8-shell-extend.cc      | Extended JavaScript Shell application using V8 |
| libuv-async-read-file.c | libuv async read file example|

## build steps

1. Install build tools

    ```bash
    xcode-select --install
    ```

2. Install V8 headers and library

    ```bash
    brew install v8
    ```

3. Install libuv headers and library

    ```bash
    brew install --HEAD libuv
    ```

4. Fetch source code

    ```bash
    Git clone git@github.com:dcheng666666/node-presentation.git
    ```

5. Build source code and run

    ```bash
    make
    ./out/v8-shell
    ```