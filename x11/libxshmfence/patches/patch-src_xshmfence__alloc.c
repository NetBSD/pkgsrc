$NetBSD: patch-src_xshmfence__alloc.c,v 1.1 2015/09/24 23:34:16 tnn Exp $

--- src/xshmfence_alloc.c.orig	2014-10-09 12:09:03.000000000 +0000
+++ src/xshmfence_alloc.c
@@ -110,6 +110,9 @@ xshmfence_map_shm(int fd)
 		close (fd);
 		return 0;
 	}
+#ifdef HAVE_SEMAPHORE
+	xshmfence_open_semaphore(addr);
+#endif
 	return addr;
 }
 
@@ -121,5 +124,8 @@ xshmfence_map_shm(int fd)
 void
 xshmfence_unmap_shm(struct xshmfence *f)
 {
+#ifdef HAVE_SEMAPHORE
+	xshmfence_close_semaphore(f);
+#endif
         munmap(f, sizeof (struct xshmfence));
 }
