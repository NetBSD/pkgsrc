$NetBSD: patch-rfc4331quotas-modules_dav_fs_repos.c,v 1.1 2023/04/21 13:52:33 manu Exp $

RFC4331 quotas from upstream trunk
http://svn.apache.org/viewvc?view=revision&revision=1907974
http://svn.apache.org/viewvc?view=revision&revision=1907984
http://svn.apache.org/viewvc?view=revision&revision=1907989
http://svn.apache.org/viewvc?view=revision&revision=1908143
http://svn.apache.org/viewvc?view=revision&revision=1908144

--- modules/dav/fs/repos.c	(revision 1907973)
+++ modules/dav/fs/repos.c	(revision 1907974)
@@ -140,11 +140,6 @@
 */
 #define DAV_PROPID_FS_executable        1
 
-/*
- * prefix for temporary files
- */
-#define DAV_FS_TMP_PREFIX ".davfs.tmp"
-
 static const dav_liveprop_spec dav_fs_props[] =
 {
     /* standard DAV properties */
@@ -173,6 +168,20 @@
         0
     },
 
+    /* RFC 4331 quotas */
+    {
+        DAV_FS_URI_DAV,
+        "quota-available-bytes",
+        DAV_PROPID_quota_available_bytes,
+        0,
+    },
+    {
+        DAV_FS_URI_DAV,
+        "quota-used-bytes",
+        DAV_PROPID_quota_used_bytes,
+        0,
+    },
+
     /* our custom properties */
     {
         DAV_FS_URI_MYPROPS,
@@ -234,6 +243,24 @@
     return resource->info->pathname;
 }
 
+const char *dav_fs_fname(const dav_resource *resource)
+{
+    return resource->info->finfo.fname;
+}
+
+apr_off_t dav_fs_size(const dav_resource *resource)
+{
+    apr_off_t size;
+
+    if ((resource->info->finfo.valid & APR_FINFO_SIZE))
+        size = resource->info->finfo.size;
+    else
+        size = DAV_FS_BYTES_ERROR;
+
+    return size;
+}
+
+
 dav_error * dav_fs_dir_file_name(
     const dav_resource *resource,
     const char **dirpath_p,
@@ -1927,6 +1954,7 @@
     apr_pool_t *p = resource->info->pool;
     const dav_liveprop_spec *info;
     long global_ns;
+    apr_off_t bytes;
 
     /* an HTTP-date can be 29 chars plus a null term */
     /* a 64-bit size can be 20 chars plus a null term */
@@ -1992,6 +2020,26 @@
             value = "F";
         break;
 
+    case DAV_PROPID_quota_available_bytes:
+        bytes = dav_fs_get_available_bytes(dav_fs_get_request_rec(resource),
+                                           dav_fs_fname(resource), NULL);
+        if (bytes == DAV_FS_BYTES_ERROR)
+            return DAV_PROP_INSERT_NOTDEF;
+
+        apr_snprintf(buf, sizeof(buf), "%" APR_OFF_T_FMT, bytes);
+        value = buf;
+        break;
+
+    case DAV_PROPID_quota_used_bytes:
+        bytes = dav_fs_get_used_bytes(dav_fs_get_request_rec(resource),
+                                           dav_fs_fname(resource));
+        if (bytes == DAV_FS_BYTES_ERROR)
+            return DAV_PROP_INSERT_NOTDEF;
+
+        apr_snprintf(buf, sizeof(buf), "%" APR_OFF_T_FMT, bytes);
+        value = buf;
+        break;
+
     default:
         /* ### what the heck was this property? */
         return DAV_PROP_INSERT_NOTDEF;
@@ -2256,9 +2304,36 @@
                               what, phdr);
 #endif
 
+    /*
+     * RFC 4331 section 2 says quota live properties should not
+     * be returned by <DAV:allprop> PROPFIND, hence we skip
+     " DAV_PROPID_quota_available_bytes and DAV_PROPID_quota_used_bytes.
+     */
+
     /* ### we know the others aren't defined as liveprops */
 }
 
+int dav_fs_method_precondition(request_rec *r,
+                               dav_resource *src, const dav_resource *dst,
+                               const apr_xml_doc *doc, dav_error **err)
+{
+    int ret = DECLINED;
+
+    switch (r->method_number) {
+    case M_COPY: /* FALLTHROUGH */
+    case M_MOVE: /* FALLTHROUGH */
+    case M_MKCOL: /* FALLTHROUGH */
+    case M_PROPPATCH: /* FALLTHROUGH */
+    case M_PUT:
+        ret = dav_fs_quota_precondition(r, src, dst, doc, err);
+        break;
+    default:
+        break;
+    }
+
+    return ret;
+}
+
 void dav_fs_register(apr_pool_t *p)
 {
     /* register the namespace URIs */
Index: modules/dav/fs/repos.h
===================================================================
