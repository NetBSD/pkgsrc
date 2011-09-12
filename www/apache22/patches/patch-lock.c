$NetBSD: patch-lock.c,v 1.1 2011/09/12 17:18:46 sborrill Exp $

Atomically create files when using DAV to stop files being deleted on error

From:
https://issues.apache.org/bugzilla/show_bug.cgi?id=39815

--- modules/dav/fs/lock.c.orig	2007-11-29 21:21:10.000000000 +0100
+++ modules/dav/fs/lock.c	2009-07-10 13:42:43.000000000 +0200
@@ -398,46 +398,48 @@
 **    to look up lock information for this file.
 **
 **    (inode/dev not supported or file is lock-null):
 **       apr_datum_t->dvalue = full path
 **
 **    (inode/dev supported and file exists ):
 **       apr_datum_t->dvalue = inode, dev
 */
 static apr_datum_t dav_fs_build_key(apr_pool_t *p,
                                     const dav_resource *resource)
 {
     const char *file = dav_fs_pathname(resource);
+#if 0
     apr_datum_t key;
     apr_finfo_t finfo;
     apr_status_t rv;
 
     /* ### use lstat() ?? */
     /*
      * XXX: What for platforms with no IDENT (dev/inode)?
      */
     rv = apr_stat(&finfo, file, APR_FINFO_IDENT, p);
     if ((rv == APR_SUCCESS || rv == APR_INCOMPLETE)
         && ((finfo.valid & APR_FINFO_IDENT) == APR_FINFO_IDENT))
     {
         /* ### can we use a buffer for this? */
         key.dsize = 1 + sizeof(finfo.inode) + sizeof(finfo.device);
         key.dptr = apr_palloc(p, key.dsize);
         *key.dptr = DAV_TYPE_INODE;
         memcpy(key.dptr + 1, &finfo.inode, sizeof(finfo.inode));
         memcpy(key.dptr + 1 + sizeof(finfo.inode), &finfo.device,
                sizeof(finfo.device));
 
         return key;
     }
+#endif
 
     return dav_fs_build_fname_key(p, file);
 }
 
 /*
 ** dav_fs_lock_expired:  return 1 (true) if the given timeout is in the past
 **    or present (the lock has expired), or 0 (false) if in the future
 **    (the lock has not yet expired).
 */
 static int dav_fs_lock_expired(time_t expires)
 {
     return expires != DAV_TIMEOUT_INFINITE && time(NULL) >= expires;
