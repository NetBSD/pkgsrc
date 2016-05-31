$NetBSD: patch-src_os_unix_ngx__files.c,v 1.1 2016/05/31 19:44:47 joerg Exp $

--- src/os/unix/ngx_files.c.orig	2016-01-26 14:39:33.000000000 +0000
+++ src/os/unix/ngx_files.c
@@ -292,6 +292,12 @@ ngx_write_chain_to_file(ngx_file_t *file
         /* create the iovec and coalesce the neighbouring bufs */
 
         while (cl && vec.nelts < IOV_MAX) {
+
+            if (ngx_buf_special(cl->buf)) {
+                cl = cl->next;
+                continue;
+            }
+
             if (prev == cl->buf->pos) {
                 iov->iov_len += cl->buf->last - cl->buf->pos;
 
