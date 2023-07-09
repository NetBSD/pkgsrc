$NetBSD: patch-modules_memcached.c,v 1.1 2023/07/09 09:50:47 nia Exp $

Confusingly this header seems to both not exist and not be required.

--- modules/memcached.c.orig	2017-10-21 06:57:48.000000000 +0000
+++ modules/memcached.c
@@ -47,8 +47,6 @@
 #include <libmemcached/memcached_pool.h>
 #endif
 
-#include <crypt.h>
-
 int USE_MD5_SUM_KEYS = 1;
 
 int mc_cfg_servers_set(const char *directive, const char **argv, void *setdata);
