# Pascal Sandbox
#### Image name: `ghcr.io/empty21/sandbox/pascal`

This sandbox is used to compile and run Pascal code.

## Usage

### Compile
```bash
podman run \
--rm \
-v $path_to_workspace_folder:/ws \
ghcr.io/empty21/sandbox/pascal \
fpc -omain main.pas
```

### Run
```bash
podman run \
--rm \
-v $path_to_workspace_folder:/ws \
--cpus $cpu_limit \
--memory $memory_limit \
ghcr.io/empty21/sandbox/pascal \
/usr/bin/time -f 'time:%e|memory:%M' \
-o $relative_path_to_execute_log_file \
timeout $time_limit_in_seconds \
sh -c './main < $relative_path_to_input_file > $relative_path_to_output_file'
```

### Variables
- `$path_to_workspace_folder`: Path to the folder that contains the source code, input file, output file, and runtime log file.
- `$cpu_limit`: CPU core limit. For example, `1`.
- `$memory_limit`: Memory limit. For example, `256m`.
- `$time_limit_in_seconds`: Time limit in seconds. For example, `2`.
- `$relative_path_to_execute_log_file`: Relative path to the runtime log file. For example, `tests/0.log`.
- `$relative_path_to_input_file`: Relative path to the input file. For example, `tests/0.in`.
- `$relative_path_to_output_file`: Relative path to the output file. For example, `tests/0.out`.
