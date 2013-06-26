$NetBSD: patch-netwerk__protocol__websocket__WebSocketChannel.cpp,v 1.2 2013/06/26 11:32:12 ryoon Exp $

# HG changeset patch
# User Martin Husemann <martin@netbsd.org>
# Date 1370038996 -7200
# Node ID 4539a7706881edaedc2189cc0d2d9c7b7abedf1d
# Parent  d16914942a9c502dde37dce2a1deb09050218ba8
Bug 871555: Use memcpy and properly aligned temporary variables instead of pointer casts with unclear alignment r=mcmanus

diff netwerk/protocol/websocket/WebSocketChannel.cpp netwerk/protocol/websocket/WebSocketChannel.cpp
--- netwerk/protocol/websocket/WebSocketChannel.cpp.orig	2013-06-17 22:13:23.000000000 +0000
+++ netwerk/protocol/websocket/WebSocketChannel.cpp
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
 
