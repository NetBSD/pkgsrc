$NetBSD: patch-os_utils.c,v 1.1.2.2 2012/12/18 17:43:02 tron Exp $

--- os/utils.c.orig	2009-10-12 02:52:40.000000000 +0000
+++ os/utils.c
@@ -315,7 +315,7 @@ LockServer(void)
     FatalError("Could not create lock file in %s\n", tmp);
   (void) sprintf(pid_str, "%10ld\n", (long)getpid());
   (void) write(lfd, pid_str, 11);
-  (void) chmod(tmp, 0444);
+  (void) fchmod(lfd, 0444);
   (void) close(lfd);
 
   /*
@@ -336,7 +336,7 @@ LockServer(void)
       /*
        * Read the pid from the existing file
        */
-      lfd = open(LockFile, O_RDONLY);
+      lfd = open(LockFile, O_RDONLY|O_NOFOLLOW);
       if (lfd < 0) {
         unlink(tmp);
         FatalError("Can't read lock file %s\n", LockFile);
