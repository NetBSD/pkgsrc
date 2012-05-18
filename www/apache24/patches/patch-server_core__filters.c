$NetBSD: patch-server_core__filters.c,v 1.1 2012/05/18 20:56:29 ryoon Exp $

Fix PR pkg/46458
Upstream bug report: https://issues.apache.org/bugzilla/show_bug.cgi?id=53253

--- server/core_filters.c.orig	2012-02-04 10:04:59.000000000 +0000
+++ server/core_filters.c
@@ -640,18 +640,13 @@ static apr_status_t send_brigade_nonbloc
             if ((apr_file_flags_get(fd) & APR_SENDFILE_ENABLED) &&
                 (bucket->length >= AP_MIN_SENDFILE_BYTES)) {
                 if (nvec > 0) {
-                    (void)apr_socket_opt_set(s, APR_TCP_NOPUSH, 1);
                     rv = writev_nonblocking(s, vec, nvec, bb, bytes_written, c);
                     nvec = 0;
                     if (rv != APR_SUCCESS) {
-                        (void)apr_socket_opt_set(s, APR_TCP_NOPUSH, 0);
                         return rv;
                     }
                 }
                 rv = sendfile_nonblocking(s, bucket, bytes_written, c);
-                if (nvec > 0) {
-                    (void)apr_socket_opt_set(s, APR_TCP_NOPUSH, 0);
-                }
                 if (rv != APR_SUCCESS) {
                     return rv;
                 }
