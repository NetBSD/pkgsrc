$NetBSD: patch-proxy_ICP.cc,v 1.1 2020/05/14 18:59:48 joerg Exp $

--- proxy/ICP.cc.orig	2020-05-14 00:04:34.069526757 +0000
+++ proxy/ICP.cc
@@ -1615,7 +1615,7 @@ ICPRequestCont::BuildICPMsg(ICPopcode_t 
   mhdr->msg_name    = (caddr_t) nullptr;
   mhdr->msg_namelen = 0;
 // TODO: The following is just awkward
-#if !defined(linux) && !defined(freebsd) && !defined(darwin) && !defined(solaris) && !defined(openbsd)
+#if !defined(linux) && !defined(freebsd) && !defined(darwin) && !defined(solaris) && !defined(openbsd) && !defined(__NetBSD__)
   mhdr->msg_accrights    = (caddr_t)0;
   mhdr->msg_accrightslen = 0;
 #elif !defined(solaris)
