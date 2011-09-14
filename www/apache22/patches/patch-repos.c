$NetBSD: patch-repos.c,v 1.1.2.2 2011/09/14 18:03:18 tron Exp $

Atomically create files when using DAV to stop files being deleted on error

From:
https://issues.apache.org/bugzilla/show_bug.cgi?id=39815

--- modules/dav/fs/repos.c.orig	2008-08-16 00:12:47.000000000 +0200
+++ modules/dav/fs/repos.c	2009-07-10 19:01:24.000000000 +0200
@@ -191,6 +191,7 @@
     apr_pool_t *p;
     apr_file_t *f;
     const char *pathname;       /* we may need to remove it at close time */
+    const char *temppath;
 };
 
 /* returns an appropriate HTTP status code given an APR status code for a
@@ -841,6 +842,14 @@
             && ctx2->pathname[len1] == '/');
 }
 
+static apr_status_t tmpfile_cleanup(void *data) {
+        dav_stream *ds = data;
+        if (ds->temppath) {
+                apr_file_remove(ds->temppath, ds->p);
+        }
+        return APR_SUCCESS;
+}
+
 static dav_error * dav_fs_open_stream(const dav_resource *resource,
                                       dav_stream_mode mode,
                                       dav_stream **stream)
@@ -849,6 +858,7 @@
     dav_stream *ds = apr_pcalloc(p, sizeof(*ds));
     apr_int32_t flags;
     apr_status_t rv;
+    char* fpath;
 
     switch (mode) {
     default:
@@ -865,7 +875,18 @@
 
     ds->p = p;
     ds->pathname = resource->info->pathname;
-    rv = apr_file_open(&ds->f, ds->pathname, flags, APR_OS_DEFAULT, ds->p);
+    ds->temppath = NULL;
+
+    if (mode == DAV_MODE_WRITE_TRUNC) {
+        fpath = apr_pstrcat(p, ds->pathname, ".tmp.XXXXXX", NULL);
+        rv = apr_file_mktemp(&ds->f, fpath, flags, ds->p);
+        ds->temppath = fpath;
+        apr_pool_cleanup_register(p, ds, tmpfile_cleanup, apr_pool_cleanup_null);
+    }
+    else {
+        rv = apr_file_open(&ds->f, ds->pathname, flags, APR_OS_DEFAULT, ds->p);
+    }
+
     if (rv != APR_SUCCESS) {
         return dav_new_error(p, MAP_IO2HTTP(rv), 0,
                              "An error occurred while opening a resource.");
@@ -879,16 +900,32 @@
 
 static dav_error * dav_fs_close_stream(dav_stream *stream, int commit)
 {
+    apr_status_t rv;
+
     apr_file_close(stream->f);
 
     if (!commit) {
-        if (apr_file_remove(stream->pathname, stream->p) != APR_SUCCESS) {
-            /* ### use a better description? */
-            return dav_new_error(stream->p, HTTP_INTERNAL_SERVER_ERROR, 0,
-                                 "There was a problem removing (rolling "
-                                 "back) the resource "
-                                 "when it was being closed.");
+        if (stream->temppath) {
+            apr_pool_cleanup_run(stream->p, stream, tmpfile_cleanup);
+        }
+        else {
+            if (apr_file_remove(stream->pathname, stream->p) != APR_SUCCESS) {
+                /* ### use a better description? */
+                return dav_new_error(stream->p, HTTP_INTERNAL_SERVER_ERROR, 0,
+                                     "There was a problem removing (rolling "
+                                     "back) the resource "
+                                     "when it was being closed.");
+            }
+        }
+    }
+    else if (stream->temppath) {
+        rv = apr_file_rename(stream->temppath, stream->pathname, stream->p);
+        if (rv) {
+            return dav_new_error(stream->p, HTTP_INTERNAL_SERVER_ERROR, rv,
+                                 "There was a problem writing the file "
+                                 "atomically after writes.");
         }
+        apr_pool_cleanup_kill(stream->p, stream, tmpfile_cleanup);
     }
 
     return NULL;
