# Pascal Sandbox
#### Image name: `quay.io/stupd/sandbox/pascal`

This sandbox is used to compile and run Pascal code.

## Dockerfile
```Dockerfile
FROM alpine
WORKDIR /sandbox
RUN apk add --no-cache gcc g++ musl-dev

ENV FPC_VERSION="3.2.2" \
    FPC_ARCH="x86_64-linux"

RUN apk add --no-cache binutils && \
    cd /tmp && \
    wget "https://downloads.sourceforge.net/project/freepascal/Linux/${FPC_VERSION}/fpc-${FPC_VERSION}.${FPC_ARCH}.tar" -O fpc.tar && \
    tar xf "fpc.tar" && \
    cd "fpc-${FPC_VERSION}.${FPC_ARCH}" && \
    rm demo* doc* && \
    \
    mkdir /lib64 && \
    ln -s /lib/ld-musl-x86_64.so.1 /lib64/ld-linux-x86-64.so.2 && \
    \
    echo -e '/usr\nN\nN\nN\n' | sh ./install.sh && \
    find "/usr/lib/fpc/${FPC_VERSION}/units/${FPC_ARCH}/" -type d -mindepth 1 -maxdepth 1 \
        -not -name 'fcl-base' \
        -not -name 'rtl' \
        -not -name 'rtl-console' \
        -not -name 'rtl-objpas' \
        -exec rm -r {} \; && \
    rm -r "/lib64" "/tmp/"*
```

## Usage

### Compile
```bash
docker run \
--rm \
-v $path_to_workspace_folder:/sandbox \
quay.io/stupd/sandbox/pascal \
fpc -omain main.pas
```

### Run
```bash
docker run \
--rm \
-v $path_to_workspace_folder:/sandbox \
--cpus=$cpu_limit \
--memory=$memory_limit \
quay.io/stupd/sandbox/pascal \
time -f 'time:%e|memory:%M' -o $relative_path_to_execute_stat_file \
timeout $time_limit_in_seconds \
sh -c './main < $relative_path_to_input_file > $relative_path_to_output_file 2> $relative_path_to_error_file'
```

### Variables
- `$path_to_workspace_folder`: Path to the folder that contains the source code, input file, output file, and runtime log file.
- `$cpu_limit`: CPU core limit. For example, `1`.
- `$memory_limit`: Memory limit. For example, `256m`.
- `$time_limit_in_seconds`: Time limit in seconds. For example, `2`.
- `$relative_path_to_execute_stat_file`: Relative path to the runtime log file. For example, `tests/0.stat`.
- `$relative_path_to_input_file`: Relative path to the input file. For example, `tests/0.in`.
- `$relative_path_to_output_file`: Relative path to the output file. For example, `tests/0.out`.
- `$relative_path_to_error_file`: Relative path to the output file. For example, `tests/0.err`.

### Example main.pas
```pascal
program main;
begin
	WriteLn('OK');
end.
```