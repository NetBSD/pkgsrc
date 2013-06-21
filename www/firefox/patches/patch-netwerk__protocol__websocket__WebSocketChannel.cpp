$NetBSD: patch-netwerk__protocol__websocket__WebSocketChannel.cpp,v 1.1 2013/06/21 23:11:42 ryoon Exp $

# HG changeset patch
# User Martin Husemann <martin@netbsd.org>
# Date 1370038996 -7200
# Node ID 4539a7706881edaedc2189cc0d2d9c7b7abedf1d
# Parent  d16914942a9c502dde37dce2a1deb09050218ba8
Bug 871555: Use memcpy and properly aligned temporary variables instead of pointer casts with unclear alignment r=mcmanus

diff netwerk/protocol/websocket/WebSocketChannel.cpp netwerk/protocol/websocket/WebSocketChannel.cpp
--- netwerk/protocol/websocket/WebSocketChannel.cpp
+++ netwerk/protocol/websocket/WebSocketChannel.cpp
@@ -1627,17 +1627,18 @@ WebSocketChannel::PrimeNewOutgoingMessag
     // payload is offset 6 including 4 for the mask
     payload = mOutHeader + 6;
 
     // The close reason code sits in the first 2 bytes of payload
     // If the channel user provided a code and reason during Close()
     // and there isn't an internal error, use that.
     if (NS_SUCCEEDED(mStopOnClose)) {
       if (mScriptCloseCode) {
-        *((uint16_t *)payload) = PR_htons(mScriptCloseCode);
+        uint16_t temp = PR_htons(mScriptCloseCode);
+        memcpy(payload, &temp, 2);
         mOutHeader[1] += 2;
         mHdrOutToSend = 8;
         if (!mScriptCloseReason.IsEmpty()) {
           NS_ABORT_IF_FALSE(mScriptCloseReason.Length() <= 123,
                             "Close Reason Too Long");
           mOutHeader[1] += mScriptCloseReason.Length();
           mHdrOutToSend += mScriptCloseReason.Length();
           memcpy (payload + 2,
@@ -1646,17 +1647,18 @@ WebSocketChannel::PrimeNewOutgoingMessag
         }
       } else {
         // No close code/reason, so payload length = 0.  We must still send mask
         // even though it's not used.  Keep payload offset so we write mask
         // below.
         mHdrOutToSend = 6;
       }
     } else {
-      *((uint16_t *)payload) = PR_htons(ResultToCloseCode(mStopOnClose));
+      uint16_t temp = PR_htons(ResultToCloseCode(mStopOnClose));
+      memcpy(payload, &temp, 2);
       mOutHeader[1] += 2;
       mHdrOutToSend = 8;
     }
 
     if (mServerClosed) {
       /* bidi close complete */
       mReleaseOnTransmit = 1;
     } else if (NS_FAILED(mStopOnClose)) {
@@ -1734,17 +1736,18 @@ WebSocketChannel::PrimeNewOutgoingMessag
       LOG(("WebSocketChannel::PrimeNewOutgoingMessage(): "
            "GenerateRandomBytes failure %x\n", rv));
       StopSession(rv);
       return;
     }
     mask = * reinterpret_cast<uint32_t *>(buffer);
     NS_Free(buffer);
   } while (!mask);
-  *(((uint32_t *)payload) - 1) = PR_htonl(mask);
+  uint32_t temp = PR_htonl(mask);
+  memcpy(payload - 4, &temp, 4);
 
   LOG(("WebSocketChannel::PrimeNewOutgoingMessage() using mask %08x\n", mask));
 
   // We don't mask the framing, but occasionally we stick a little payload
   // data in the buffer used for the framing. Close frames are the current
   // example. This data needs to be masked, but it is never more than a
   // handful of bytes and might rotate the mask, so we can just do it locally.
   // For real data frames we ship the bulk of the payload off to ApplyMask()

