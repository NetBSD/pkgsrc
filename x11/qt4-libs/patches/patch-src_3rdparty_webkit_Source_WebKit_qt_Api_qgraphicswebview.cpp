$NetBSD: patch-src_3rdparty_webkit_Source_WebKit_qt_Api_qgraphicswebview.cpp,v 1.1 2013/05/09 14:07:08 joerg Exp $

--- src/3rdparty/webkit/Source/WebKit/qt/Api/qgraphicswebview.cpp.orig	2013-05-03 13:55:03.000000000 +0000
+++ src/3rdparty/webkit/Source/WebKit/qt/Api/qgraphicswebview.cpp
@@ -471,7 +471,7 @@ void QGraphicsWebViewPrivate::detachCurr
         return;
 
     page->d->view.clear();
-    page->d->client = 0;
+    page->d->client = nullptr;
 
     // if the page was created by us, we own it and need to
     // destroy it as well.
@@ -504,7 +504,7 @@ void QGraphicsWebView::setPage(QWebPage*
     if (!d->page)
         return;
 
-    d->page->d->client = new PageClientQGraphicsWidget(this, page); // set the page client
+    d->page->d->client = adoptPtr(new PageClientQGraphicsWidget(this, page)); // set the page client
 
     if (d->overlay())
         d->overlay()->prepareGraphicsItemGeometryChange();
