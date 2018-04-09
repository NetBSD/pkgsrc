$NetBSD: patch-Source_WebKit_Platform_IPC_unix_ConnectionUnix.cpp,v 1.1 2018/04/09 08:33:48 wiz Exp $

On NetBSD we see ""Error sending IPC message: Message too long" due to
the use of sendmsg with a large message body (EMSGSIZE).

WebKit already uses shared memory to communicate the message body when
the message is too large, so force it to always use this method to avoid
encountering EMSGSIZE.

--- Source/WebKit/Platform/IPC/unix/ConnectionUnix.cpp.orig	2017-08-09 09:13:52.000000000 +0000
+++ Source/WebKit/Platform/IPC/unix/ConnectionUnix.cpp
@@ -380,8 +380,12 @@ bool Connection::sendOutgoingMessage(std
         return false;
     }
 
+#if 0
     size_t messageSizeWithBodyInline = sizeof(MessageInfo) + (outputMessage.attachments().size() * sizeof(AttachmentInfo)) + outputMessage.bodySize();
     if (messageSizeWithBodyInline > messageMaxSize && outputMessage.bodySize()) {
+#else
+    {
+#endif
         RefPtr<WebKit::SharedMemory> oolMessageBody = WebKit::SharedMemory::allocate(encoder->bufferSize());
         if (!oolMessageBody)
             return false;
