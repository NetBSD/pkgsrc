$NetBSD: patch-src_mod__alias.c,v 1.1 2021/11/03 15:06:51 schmonz Exp $

Apply upstream 584a69c4 to fix use-after-free.

<https://redmine.lighttpd.net/issues/3114>

--- src/mod_alias.c.orig	2021-10-28 22:58:31.000000000 +0000
+++ src/mod_alias.c
@@ -128,7 +128,7 @@ mod_alias_remap (request_st * const r, c
     if (0 == path_len || path_len < basedir_len) return HANDLER_GO_ON;
 
     const uint32_t uri_len = path_len - basedir_len;
-    const char * const uri_ptr = r->physical.path.ptr + basedir_len;
+    const char *uri_ptr = r->physical.path.ptr + basedir_len;
     data_string * const ds = (data_string *)
       (!r->conf.force_lowercase_filenames
         ? array_match_key_prefix_klen(aliases, uri_ptr, uri_len)
@@ -159,8 +159,10 @@ mod_alias_remap (request_st * const r, c
      * (though resulting r->physical.basedir would not be a dir))*/
     if (vlen != basedir_len + alias_len) {
         const uint32_t nlen = vlen + uri_len - alias_len;
-        if (path_len + buffer_string_space(&r->physical.path) < nlen)
+        if (path_len + buffer_string_space(&r->physical.path) < nlen) {
             buffer_string_prepare_append(&r->physical.path, nlen - path_len);
+            uri_ptr = r->physical.path.ptr + basedir_len;/*(refresh if alloc)*/
+        }
         memmove(r->physical.path.ptr + vlen,
                 uri_ptr + alias_len, uri_len - alias_len);
         buffer_truncate(&r->physical.path, nlen);
