$NetBSD: patch-kwin_utils.cpp,v 1.1 2013/06/22 22:39:10 jperkin Exp $

Conditionalise getdomainname().

--- kwin/utils.cpp.orig	2013-05-03 04:36:45.662117614 +0000
+++ kwin/utils.cpp
@@ -422,12 +422,14 @@ bool isLocalMachine(const QByteArray& ho
             if (host == hostnamebuf)
                 return true;
         } else { // e.g. LibreOffice likes to give FQDN, even if gethostname() doesn't include domain
+#ifdef HAVE_GETDOMAINNAME
             QByteArray h = hostnamebuf;
             if( getdomainname( hostnamebuf, sizeof hostnamebuf ) >= 0 ) {
                 hostnamebuf[sizeof(hostnamebuf)-1] = 0;
                 if( host == h + '.' + QByteArray( hostnamebuf ))
                     return true;
             }
+#endif
         }
     }
     return false;
