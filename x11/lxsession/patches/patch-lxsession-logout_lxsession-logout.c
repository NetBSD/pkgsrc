$NetBSD: patch-lxsession-logout_lxsession-logout.c,v 1.1 2017/07/06 09:18:41 jperkin Exp $

SunOS flock compat.

--- lxsession-logout/lxsession-logout.c.orig	2014-11-29 14:43:14.000000000 +0000
+++ lxsession-logout/lxsession-logout.c
@@ -485,7 +485,16 @@ int main(int argc, char * argv[])
     int fd = open(lockfile, O_RDONLY|O_CREAT, 00600);
     if (fd >= 0)
     {
+#ifdef __sun
+	struct flock lock;
+	lock.l_start = 0;
+	lock.l_len = 0;
+	lock.l_whence = SEEK_SET;
+	lock.l_type = F_WRLCK;
+	if (fcntl(fd, F_SETLK, &lock))
+#else
         if (flock(fd, LOCK_EX | LOCK_NB))
+#endif
         {
             exit(EXIT_FAILURE);
         }
