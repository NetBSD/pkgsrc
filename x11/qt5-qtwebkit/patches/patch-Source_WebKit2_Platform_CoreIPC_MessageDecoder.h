$NetBSD: patch-Source_WebKit2_Platform_CoreIPC_MessageDecoder.h,v 1.1 2014/12/30 17:23:48 adam Exp $

--- Source/WebKit2/Platform/CoreIPC/MessageDecoder.h.orig	2014-04-22 06:56:09.000000000 +0000
+++ Source/WebKit2/Platform/CoreIPC/MessageDecoder.h
@@ -46,7 +46,7 @@ public:
     bool isSyncMessage() const;
     bool shouldDispatchMessageWhenWaitingForSyncReply() const;
 
-#if PLATFORM(MAC) && __MAC_OS_X_VERSION_MIN_REQUIRED >= 1090
+#if defined(Q_OS_MAC) && __MAC_OS_X_VERSION_MIN_REQUIRED >= 1090
     void setImportanceAssertion(PassOwnPtr<ImportanceAssertion>);
 #endif
 
@@ -57,7 +57,7 @@ private:
     StringReference m_messageReceiverName;
     StringReference m_messageName;
 
-#if PLATFORM(MAC) && __MAC_OS_X_VERSION_MIN_REQUIRED >= 1090
+#if defined(Q_OS_MAC) && __MAC_OS_X_VERSION_MIN_REQUIRED >= 1090
     OwnPtr<ImportanceAssertion> m_importanceAssertion;
 #endif
 };
