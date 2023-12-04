$NetBSD: patch-apc__shm.c,v 1.2 2023/12/04 01:42:14 gdt Exp $

The code assumes key_t is printable with %d (int), but POSIX requires
only that key_t is an arithmetic type.  Dismiss floating point as
unreasonable and cast to intmax_t.

https://github.com/krakjoe/apcu/issues/500

--- apc_shm.c.orig	2023-12-04 01:27:07.199895899 +0000
+++ apc_shm.c
@@ -53,7 +53,7 @@ int apc_shm_create(int proj, size_t size
 
 	oflag = IPC_CREAT | SHM_R | SHM_A;
 	if ((shmid = shmget(key, size, oflag)) < 0) {
-		zend_error_noreturn(E_CORE_ERROR, "apc_shm_create: shmget(%d, %zd, %d) failed: %s. It is possible that the chosen SHM segment size is higher than the operation system allows. Linux has usually a default limit of 32MB per segment.", key, size, oflag, strerror(errno));
+		zend_error_noreturn(E_CORE_ERROR, "apc_shm_create: shmget(%jd, %zd, %d) failed: %s. It is possible that the chosen SHM segment size is higher than the operation system allows. Linux has usually a default limit of 32MB per segment.", (intmax_t) key, size, oflag, strerror(errno));
 	}
 
 	return shmid;
