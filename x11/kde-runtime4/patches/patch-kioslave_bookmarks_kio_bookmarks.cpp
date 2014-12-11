$NetBSD: patch-kioslave_bookmarks_kio_bookmarks.cpp,v 1.1 2014/12/11 20:00:15 markd Exp $

Sanitize path
http://quickgit.kde.org/?p=kde-runtime.git&a=commit&h=d68703900edc8416fbcd2550cd336cbbb76decb9

--- kioslave/bookmarks/kio_bookmarks.cpp.orig	2014-10-30 23:50:20.000000000 +0000
+++ kioslave/bookmarks/kio_bookmarks.cpp
@@ -22,6 +22,7 @@
 #include <stdlib.h>
 
 #include <qregexp.h>
+#include <qtextdocument.h>
 
 #include <kapplication.h>
 #include <kcmdlineargs.h>
@@ -197,7 +198,7 @@ void BookmarksProtocol::get( const KUrl&
     echoImage(regexp.cap(1), regexp.cap(2), url.queryItem("size"));
   } else {
     echoHead();
-    echo("<p class=\"message\">" + i18n("Wrong request: %1",path) + "</p>");
+    echo("<p class=\"message\">" + i18n("Bad request: %1", Qt::escape(Qt::escape(url.prettyUrl()))) + "</p>");
   }
   finished();
 }
