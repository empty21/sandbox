# Java Sandbox
#### Image name: `quay.io/stupd/sandbox/java`

This sandbox is used to compile and run Java code.  
Java version: openjdk-17

## Dockerfile
```Dockerfile
FROM alpine
WORKDIR /sandbox
RUN apk add --no-cache openjdk17
```

## Usage

### Compile
```bash
docker run \
--rm \
-v $path_to_workspace_folder:/sandbox \
quay.io/stupd/sandbox/java \
javac Execute.java
```

### Run
```bash
docker run \
--rm \
-v $path_to_workspace_folder:/sandbox \
--cpus=$cpu_limit \
--memory=$memory_limit \
quay.io/stupd/sandbox/java \
time -f 'time:%e|memory:%M' -o $relative_path_to_execute_stat_file \
timeout $time_limit_in_seconds \
sh -c 'java Execute < $relative_path_to_input_file > $relative_path_to_output_file 2> $relative_path_to_error_file'
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

### Example Execute.java
```java
public class Execute {
    public static void main(String[] args) {
        System.out.println("OK");
    }
}
```