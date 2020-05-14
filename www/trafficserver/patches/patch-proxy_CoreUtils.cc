$NetBSD: patch-proxy_CoreUtils.cc,v 1.1 2020/05/14 18:59:48 joerg Exp $

--- proxy/CoreUtils.cc.orig	2020-05-14 00:03:49.823485692 +0000
+++ proxy/CoreUtils.cc
@@ -98,7 +98,7 @@ int framepointer    = 0;
 int program_counter = 0;
 #endif // linux check
 
-#if defined(darwin) || defined(freebsd) || defined(solaris) || defined(openbsd) // FIXME: solaris x86
+#if defined(darwin) || defined(freebsd) || defined(solaris) || defined(openbsd) || defined(__NetBSD__)// FIXME: solaris x86
 // TODO: Cleanup multiple includes
 #include <stdio.h>
 #include <stdlib.h>
@@ -738,7 +738,7 @@ CoreUtils::process_EThread(EThread *eth_
     EThread *loaded_eth = (EThread *)buf;
 
     printf("----------- EThread @ 0x%p ----------\n", eth_test);
-#if !defined(kfreebsd) && (defined(freebsd) || defined(darwin) || defined(openbsd))
+#if !defined(kfreebsd) && (defined(freebsd) || defined(darwin) || defined(openbsd) || defined(__NetBSD__))
     printf("   thread_id: %p\n", loaded_eth->tid);
 #else
     printf("   thread_id: %i\n", (int)loaded_eth->tid);
