# C++ Sandbox
#### Image name: `quay.io/stupd/sandbox/cpp`

This sandbox is used to compile and run C++ code.

## Dockerfile
```Dockerfile
FROM alpine
WORKDIR /sandbox
RUN apk add --no-cache musl-dev gcc g++
```

## Usage

### Compile
```bash
docker run \
--rm \
-v $path_to_workspace_folder:/sandbox \
quay.io/stupd/sandbox/cpp \
g++ -o main main.cpp
```

### Run
```bash
docker run \
--rm \
-v $path_to_workspace_folder:/sandbox \
--cpus=$cpu_limit \
--memory=$memory_limit \
quay.io/stupd/sandbox/cpp \
time -f 'time:%e|memory:%M' -o $relative_path_to_execute_log_file \
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

### Example main.cpp
```c++
#include <iostream>
using namespace std;

int main() {
    cout << "OK";
    return 0;
}
```