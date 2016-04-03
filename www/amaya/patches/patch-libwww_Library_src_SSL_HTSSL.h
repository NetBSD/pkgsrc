$NetBSD: patch-libwww_Library_src_SSL_HTSSL.h,v 1.1 2016/04/03 12:44:13 joerg Exp $

--- libwww/Library/src/SSL/HTSSL.h.orig	2016-04-02 21:54:45.665075537 +0000
+++ libwww/Library/src/SSL/HTSSL.h
@@ -46,7 +46,6 @@ highest available protocol (TLSv1 in thi
 */
  
 typedef enum _HTSSL_PROTOCOL {
-	      HTSSL_V2 = 0, 
 	      HTSSL_V3,
 	      HTSSL_V23, /* Brian Hawley: the SSLv23 method tries 
 		            SSLv3/TLSv1 but can fall back to SSLV2 */
