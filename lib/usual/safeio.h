/*
 * Copyright (c) 2007-2009 Marko Kreen, Skype Technologies OÜ
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

/** @file
 *
 * EINTR-safe I/O functions.
 */
#ifndef _USUAL_SAFEIO_H_
#define _USUAL_SAFEIO_H_

#include <usual/socket.h>

void safe_init_uring(void);
ssize_t safe_uring_read(int fd, void *buf, size_t len)                        _MUSTCHECK;
ssize_t safe_uring_write(int fd, const void *buf, size_t len)                 _MUSTCHECK;
ssize_t safe_uring_recv(int fd, void*buf, size_t len, int flags);             _MUSTCHECK
ssize_t safe_uring_send(int fd, const void*buf, size_t len, int flags);       _MUSTCHECK
ssize_t safe_uring_recvmsg(int fd, struct msghdr *msg, int flags)             _MUSTCHECK;
ssize_t safe_uring_sendmsg(int fd, const struct msghdr *msg, int flags)       _MUSTCHECK;

/** read */
ssize_t safe_read(int fd, void *buf, size_t len)                _MUSTCHECK;
/** write */
ssize_t safe_write(int fd, const void *buf, size_t len)         _MUSTCHECK;
/** recv */
ssize_t safe_recv(int fd, void *buf, size_t len, int flags)     _MUSTCHECK;
/** send */
ssize_t safe_send(int fd, const void *buf, size_t len, int flags) _MUSTCHECK;
/** close */
int safe_close(int fd);
/** recvmsg */
ssize_t safe_recvmsg(int fd, struct msghdr *msg, int flags)     _MUSTCHECK;
/** sendmsg */
ssize_t safe_sendmsg(int fd, const struct msghdr *msg, int flags) _MUSTCHECK;
/** connect */
int safe_connect(int fd, const struct sockaddr *sa, socklen_t sa_len)   _MUSTCHECK;
/** accept */
int safe_accept(int fd, struct sockaddr *sa, socklen_t *sa_len) _MUSTCHECK;

#endif
