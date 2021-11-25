#include <stdio.h>
#include <stdlib.h>
#include <uv.h>

void timer_cb(uv_timer_t *timer, int status)
{
    printf("Time is up");
}

static uv_fs_t openReq;
static uv_fs_t readReq;
static uv_fs_t closeReq;
static uv_buf_t uvBuf;
static char strBuf[65];
static char dataBuf[64];

static void onRead(uv_fs_t *req);

static uv_loop_t *loop;

static void readData(void)
{
    memset(strBuf, 0, sizeof(strBuf));
    memcpy(strBuf, dataBuf, sizeof(dataBuf));
    fprintf(stdout, "file content: \n%s\n", strBuf);
    memset(dataBuf, 0, sizeof(dataBuf));
    uv_fs_read(loop, &readReq, openReq.result, &uvBuf, 1, -1, onRead);
}

static void onRead(uv_fs_t *req)
{
    printf("file read start\n");
    uv_fs_req_cleanup(req);
    if (req->result < 0)
    {
        fprintf(stderr, "error: %s\n", uv_strerror(req->result));
    }
    else if (req->result == 0)
    {
        printf("file read finish\n");
        uv_fs_req_cleanup(req);
    }
    else
    {
        readData();
    }
}

static void onOpen(uv_fs_t *req)
{
    printf("file open\n");
    if (req->result < 0)
    {
        printf("error");
        fprintf(stderr, "error: %s\n", uv_strerror(req->result));
    }
    else
    {
        uvBuf = uv_buf_init(dataBuf, sizeof(dataBuf));
        uv_fs_read(loop, &readReq, req->result, &uvBuf, 1, -1, onRead);
    }
    uv_fs_req_cleanup(req);
}

int main()
{
    loop = malloc(sizeof(uv_loop_t));
    uv_loop_init(loop);

    uv_timer_t timer;
    uv_timer_init(loop, &timer);
    uv_timer_start(&timer, (uv_timer_cb)&timer_cb, 1000, 0);

    uv_fs_open(loop, &openReq, "test.js", O_RDONLY, 0, onOpen);

    uv_run(loop, UV_RUN_DEFAULT);

    uv_loop_close(loop);
    free(loop);

    return 0;
}