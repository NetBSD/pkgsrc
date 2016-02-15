$NetBSD: patch-src_svn_mod__authz__svn__crowd.c,v 1.1 2016/02/15 16:34:32 jperkin Exp $

Support Subversion 1.8.

--- src/svn/mod_authz_svn_crowd.c.orig	2013-09-25 06:41:53.000000000 +0000
+++ src/svn/mod_authz_svn_crowd.c
@@ -50,6 +50,7 @@
 
 #include <svn_pools.h>
 #include <svn_dirent_uri.h>
+#include <svn_version.h>
 
 const char *
 svn_fspath__canonicalize(const char *fspath,
@@ -73,6 +74,7 @@ typedef struct authz_svn_config_rec {
   const char *base_path;
   const char *access_file;
   const char *repo_relative_access_file;
+  const char *groups_file; // rwb
   const char *force_username_case;
 } authz_svn_config_rec;
 
@@ -105,6 +107,12 @@ struct svn_config_t
   /* Temporary value used for expanded default values in svn_config_get.
      (Using a stringbuf so that frequent resetting is efficient.) */
   svn_stringbuf_t *tmp_value;
+
+#if SVN_VER_MINOR >= 7
+  /* Specifies whether section names are populated case sensitively. */
+  svn_boolean_t section_names_case_sensitive;
+#endif
+
 };
 
 typedef struct
@@ -113,7 +121,7 @@ typedef struct
   const char *name;
 
   /* The section name, converted into a hash key. */
-  const char *hash_key;
+  // const char *hash_key;
 
   /* Table of cfg_option_t's. */
   apr_hash_t *options;
