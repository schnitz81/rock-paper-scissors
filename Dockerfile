FROM alpine
RUN apk update && apk add gcc libc-dev
COPY rock-paper-scissors.c /
RUN gcc -v -o /rock-paper-scissors /rock-paper-scissors.c
ENTRYPOINT ["/rock-paper-scissors"]
