# Python Sandbox
#### Image name: `quay.io/stupd/sandbox/python`

This sandbox is used to run Python code.

## Dockerfile
```Dockerfile
FROM alpine
WORKDIR /sandbox
ENV PYTHONUNBUFFERED=1
RUN apk add --no-cache python3 && \
        if [ ! -e /usr/bin/python ]; then ln -sf python3 /usr/bin/python ; fi && \
        python3 -m ensurepip && \
        rm -r /usr/lib/python*/ensurepip && \
        pip3 install --no-cache --upgrade pip setuptools wheel && \
        if [ ! -e /usr/bin/pip ]; then ln -s pip3 /usr/bin/pip ; fi
```

## Usage

### Run
```bash
docker run \
--rm \
-v $path_to_workspace_folder:/sandbox \
--cpus=$cpu_limit \
--memory=$memory_limit \
quay.io/stupd/sandbox/python \
time -f 'time:%e|memory:%M' -o $relative_path_to_execute_stat_file \
timeout $time_limit_in_seconds \
sh -c 'python main.py < $relative_path_to_input_file > $relative_path_to_output_file 2> $relative_path_to_error_file'
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

### Example main.py
```python
print("OK")
```