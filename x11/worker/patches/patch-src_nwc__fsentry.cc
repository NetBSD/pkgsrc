$NetBSD: patch-src_nwc__fsentry.cc,v 1.1 2026/11/16 18:09:15 vins Exp $

Honor NetBSD's stat.h

--- src/nwc_fsentry.cc.orig	2026-11-16 18:03:53.515599777 +0000
+++ src/nwc_fsentry.cc
@@ -47,7 +47,7 @@ namespace NWC
     
       if ( worker_lstat( _fullname.c_str(), &stbuf ) == 0 ) {
         _statbuf.size = stbuf.st_size;
-#if _POSIX_C_SOURCE >= 200809L
+#if _POSIX_C_SOURCE >= 200809L || defined(_NETBSD_SOURCE)
         _statbuf.lastaccess = stbuf.st_atim;
         _statbuf.lastmod = stbuf.st_mtim;
         _statbuf.lastchange = stbuf.st_ctim;
@@ -78,7 +78,7 @@ namespace NWC
 
         if ( worker_stat( _fullname.c_str(), &stbuf ) == 0 ) {
           _dest_statbuf.size = stbuf.st_size;
-#if _POSIX_C_SOURCE >= 200809L
+#if _POSIX_C_SOURCE >= 200809L || defined(_NETBSD_SOURCE)
           _dest_statbuf.lastaccess = stbuf.st_atim;
           _dest_statbuf.lastmod = stbuf.st_mtim;
           _dest_statbuf.lastchange = stbuf.st_ctim;
