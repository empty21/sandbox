FROM ghcr.io/empty21/sandbox/c AS build
WORKDIR /usr/src
COPY src/ .
RUN mkdir out
RUN gcc -o out/compare compare.c

FROM alpine AS runtime
WORKDIR /ws
COPY --from=build /usr/src/out/ /usr/local/bin
