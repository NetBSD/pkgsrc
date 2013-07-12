$NetBSD: patch-mozilla_netwerk_protocol_websocket_WebSocketChannel.cpp,v 1.1 2013/07/12 12:24:11 ryoon Exp $

--- mozilla/netwerk/protocol/websocket/WebSocketChannel.cpp.orig	2013-06-20 04:35:18.000000000 +0000
+++ mozilla/netwerk/protocol/websocket/WebSocketChannel.cpp
@@ -1632,7 +1632,8 @@ WebSocketChannel::PrimeNewOutgoingMessag
     // and there isn't an internal error, use that.
     if (NS_SUCCEEDED(mStopOnClose)) {
       if (mScriptCloseCode) {
-        *((uint16_t *)payload) = PR_htons(mScriptCloseCode);
+        uint16_t temp = PR_htons(mScriptCloseCode);
+        memcpy(payload, &temp, 2);
         mOutHeader[1] += 2;
         mHdrOutToSend = 8;
         if (!mScriptCloseReason.IsEmpty()) {
@@ -1651,7 +1652,8 @@ WebSocketChannel::PrimeNewOutgoingMessag
         mHdrOutToSend = 6;
       }
     } else {
-      *((uint16_t *)payload) = PR_htons(ResultToCloseCode(mStopOnClose));
+      uint16_t temp = PR_htons(ResultToCloseCode(mStopOnClose));
+      memcpy(payload, &temp, 2);
       mOutHeader[1] += 2;
       mHdrOutToSend = 8;
     }
@@ -1739,7 +1741,8 @@ WebSocketChannel::PrimeNewOutgoingMessag
     mask = * reinterpret_cast<uint32_t *>(buffer);
     NS_Free(buffer);
   } while (!mask);
-  *(((uint32_t *)payload) - 1) = PR_htonl(mask);
+  uint32_t temp = PR_htonl(mask);
+  memcpy(payload - 4, &temp, 4);
 
   LOG(("WebSocketChannel::PrimeNewOutgoingMessage() using mask %08x\n", mask));
 
