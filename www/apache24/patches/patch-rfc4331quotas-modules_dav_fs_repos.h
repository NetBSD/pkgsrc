$NetBSD: patch-rfc4331quotas-modules_dav_fs_repos.h,v 1.1 2023/04/21 13:52:33 manu Exp $

RFC4331 quotas from upstream trunk
http://svn.apache.org/viewvc?view=revision&revision=1907974
http://svn.apache.org/viewvc?view=revision&revision=1907984
http://svn.apache.org/viewvc?view=revision&revision=1907989
http://svn.apache.org/viewvc?view=revision&revision=1908143
http://svn.apache.org/viewvc?view=revision&revision=1908144

--- modules/dav/fs/repos.h	(revision 1907973)
+++ modules/dav/fs/repos.h	(revision 1907974)
@@ -29,8 +29,14 @@
 #define DAV_FS_STATE_DIR                ".DAV"
 #define DAV_FS_STATE_FILE_FOR_DIR       ".state_for_dir"
 #define DAV_FS_LOCK_NULL_FILE           ".locknull"
+#define DAV_FS_TMP_PREFIX               ".davfs.tmp" /* prefix for tmp files */
 
+#define DAV_FS_QUOTA_UNSET       0
+#define DAV_FS_QUOTA_OFF        -1
+#define DAV_FS_QUOTA_NONE       -2
 
+#define DAV_FS_BYTES_ERROR      -1
+
 /* ensure that our state subdirectory is present */
 void dav_fs_ensure_state_dir(apr_pool_t *p, const char *dirname);
 
@@ -40,6 +46,13 @@
 /* return the full pathname for a resource */
 const char *dav_fs_pathname(const dav_resource *resource);
 
+/* same as dav_fs_pathname() with directories' trailing slash */
+const char *dav_fs_fname(const dav_resource *resource);
+
+/* return the size for a resource, -1 if unknown */
+apr_off_t dav_fs_size(const dav_resource *resource);
+
+
 /* return the directory and filename for a resource */
 dav_error * dav_fs_dir_file_name(const dav_resource *resource,
                                  const char **dirpath,
@@ -67,6 +80,12 @@
 /* where is the lock database located? */
 const char *dav_get_lockdb_path(const request_rec *r);
 
+dav_error *dav_fs_get_quota(const request_rec *r, const char *path,
+                            apr_off_t *quota_bytes);
+apr_off_t dav_fs_get_used_bytes(request_rec *r, const char *path);
+apr_off_t dav_fs_get_available_bytes(request_rec *r,
+                                     const char *path, int *fs_low);
+
 const dav_hooks_locks *dav_fs_get_lock_hooks(request_rec *r);
 const dav_hooks_propdb *dav_fs_get_propdb_hooks(request_rec *r);
 
@@ -76,6 +95,12 @@
                          const dav_hooks_liveprop **hooks);
 void dav_fs_insert_all_liveprops(request_rec *r, const dav_resource *resource,
                                  dav_prop_insert what, apr_text_header *phdr);
+int dav_fs_quota_precondition(request_rec *r,
+                              dav_resource *src, const dav_resource *dst,
+                              const apr_xml_doc *doc, dav_error **err);
+int dav_fs_method_precondition(request_rec *r,
+                               dav_resource *src, const dav_resource *dst,
+                               const apr_xml_doc *doc, dav_error **err);
 
 void dav_fs_register(apr_pool_t *p);
 
Index: modules/dav/main/mod_dav.h
===================================================================
