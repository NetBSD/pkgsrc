$NetBSD: patch-src_3rdparty_webkit_Source_WebCore_platform_network_qt_QNetworkReplyHandler.cpp,v 1.1 2013/05/09 14:07:08 joerg Exp $

--- src/3rdparty/webkit/Source/WebCore/platform/network/qt/QNetworkReplyHandler.cpp.orig	2013-05-03 13:04:45.000000000 +0000
+++ src/3rdparty/webkit/Source/WebCore/platform/network/qt/QNetworkReplyHandler.cpp
@@ -235,7 +235,7 @@ QNetworkReply* QNetworkReplyWrapper::rel
     resetConnections();
     QNetworkReply* reply = m_reply;
     m_reply = 0;
-    m_sniffer = 0;
+    m_sniffer = nullptr;
 
     reply->setParent(0);
     return reply;
@@ -300,7 +300,7 @@ void QNetworkReplyWrapper::receiveSniffe
     Q_ASSERT(m_sniffer);
 
     m_sniffedMIMEType = m_sniffer->mimeType();
-    m_sniffer = 0;
+    m_sniffer = nullptr;
 
     emitMetaDataChanged();
 }
@@ -417,7 +417,7 @@ QNetworkReply* QNetworkReplyHandler::rel
         return 0;
 
     QNetworkReply* reply = m_replyWrapper->release();
-    m_replyWrapper = 0;
+    m_replyWrapper = nullptr;
     return reply;
 }
 
@@ -440,12 +440,12 @@ void QNetworkReplyHandler::finish()
 
     ResourceHandleClient* client = m_resourceHandle->client();
     if (!client) {
-        m_replyWrapper = 0;
+        m_replyWrapper = nullptr;
         return;
     }
 
     if (m_replyWrapper->wasRedirected()) {
-        m_replyWrapper = 0;
+        m_replyWrapper = nullptr;
         m_queue.push(&QNetworkReplyHandler::start);
         return;
     }
@@ -465,7 +465,7 @@ void QNetworkReplyHandler::finish()
         }
     }
 
-    m_replyWrapper = 0;
+    m_replyWrapper = nullptr;
 }
 
 void QNetworkReplyHandler::sendResponseIfNeeded()
@@ -539,7 +539,7 @@ void QNetworkReplyHandler::redirect(Reso
                             newUrl.toString(),
                             QCoreApplication::translate("QWebPage", "Redirection limit reached"));
         client->didFail(m_resourceHandle, error);
-        m_replyWrapper = 0;
+        m_replyWrapper = nullptr;
         return;
     }
 
@@ -666,7 +666,7 @@ void QNetworkReplyHandler::start()
     if (!reply)
         return;
 
-    m_replyWrapper = new QNetworkReplyWrapper(&m_queue, reply, m_resourceHandle->shouldContentSniff() && d->m_context->mimeSniffingEnabled(), this);
+    m_replyWrapper = adoptPtr(new QNetworkReplyWrapper(&m_queue, reply, m_resourceHandle->shouldContentSniff() && d->m_context->mimeSniffingEnabled(), this));
 
     if (m_loadType == SynchronousLoad) {
         m_replyWrapper->synchronousLoad();
