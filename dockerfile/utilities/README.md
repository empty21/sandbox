# Judging Utilities
#### Image name: `ghcr.io/empty21/sandbox/utils`

This docker image contains the following utilities:
- [file-comparison](#file-comparison)

## Usage
### File comparison
```shell
docker run \
--rm \
-v $path_to_workspace_folder:/ws \
ghcr.io/empty21/sandbox/utils \
compare {file_name_1} {file_name_2}
```

If 2 files are the same, the output will be '1' else '0'.
If cannot open file, the output will be empty with non-zero exit code.

