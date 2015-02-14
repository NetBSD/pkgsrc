$NetBSD: patch-netwerk_protocol_http_Http2Session.cpp,v 1.3 2015/02/14 07:59:24 martin Exp $

https://bugzilla.mozilla.org/show_bug.cgi?id=1130822
Fix obivous alignment issues (causing crashes on some architectures).

--- netwerk/protocol/http/Http2Session.cpp.orig	2015-01-23 07:00:06.000000000 +0100
+++ netwerk/protocol/http/Http2Session.cpp	2015-02-13 08:50:19.000000000 +0100
@@ -30,7 +30,6 @@
 #include "nsISSLStatusProvider.h"
 #include "nsISupportsPriority.h"
 #include "prprf.h"
-#include "prnetdb.h"
 #include "sslt.h"
 
 #ifdef DEBUG
@@ -1289,7 +1288,7 @@
     return rv;
 
   uint32_t newPriorityDependency =
-    PR_ntohl(*reinterpret_cast<uint32_t *>(self->mInputFrameBuffer.get() + kFrameHeaderBytes));
+    NS_decodeN32(self->mInputFrameBuffer.get() + kFrameHeaderBytes);
   bool exclusive = !!(newPriorityDependency & 0x80000000);
   newPriorityDependency &= 0x7fffffff;
   uint8_t newPriorityWeight = *(self->mInputFrameBuffer.get() + kFrameHeaderBytes + 4);
@@ -1320,7 +1319,7 @@
   }
 
   self->mDownstreamRstReason =
-    PR_ntohl(*reinterpret_cast<uint32_t *>(self->mInputFrameBuffer.get() + kFrameHeaderBytes));
+    NS_decodeN32(self->mInputFrameBuffer.get() + kFrameHeaderBytes);
 
   LOG3(("Http2Session::RecvRstStream %p RST_STREAM Reason Code %u ID %x\n",
         self, self->mDownstreamRstReason, self->mInputFrameID));
@@ -1381,8 +1380,8 @@
     uint8_t *setting = reinterpret_cast<uint8_t *>
       (self->mInputFrameBuffer.get()) + kFrameHeaderBytes + index * 6;
 
-    uint16_t id = PR_ntohs(*reinterpret_cast<uint16_t *>(setting));
-    uint32_t value = PR_ntohl(*reinterpret_cast<uint32_t *>(setting + 2));
+    uint16_t id = NS_decodeN16(setting);
+    uint32_t value = NS_decodeN32(setting + 2);
     LOG3(("Settings ID %u, Value %u", id, value));
 
     switch (id)
@@ -1467,7 +1466,7 @@
     }
     promiseLen = 4;
     promisedID =
-      PR_ntohl(*reinterpret_cast<uint32_t *>(self->mInputFrameBuffer.get() + kFrameHeaderBytes + paddingControlBytes));
+      NS_decodeN32(self->mInputFrameBuffer.get() + kFrameHeaderBytes + paddingControlBytes);
     promisedID &= 0x7fffffff;
   }
 
@@ -1702,11 +1701,11 @@
 
   self->mShouldGoAway = true;
   self->mGoAwayID =
-    PR_ntohl(*reinterpret_cast<uint32_t *>(self->mInputFrameBuffer.get() + kFrameHeaderBytes));
+    NS_decodeN32(self->mInputFrameBuffer.get() + kFrameHeaderBytes);
   self->mGoAwayID &= 0x7fffffff;
   self->mCleanShutdown = true;
   uint32_t statusCode =
-    PR_ntohl(*reinterpret_cast<uint32_t *>(self->mInputFrameBuffer.get() + kFrameHeaderBytes + 4));
+    NS_decodeN32(self->mInputFrameBuffer.get() + kFrameHeaderBytes + 4);
 
   // Find streams greater than the last-good ID and mark them for deletion
   // in the mGoAwayStreamsToRestart queue with the GoAwayEnumerator. The
@@ -1772,7 +1771,7 @@
   }
 
   uint32_t delta =
-    PR_ntohl(*reinterpret_cast<uint32_t *>(self->mInputFrameBuffer.get() + kFrameHeaderBytes));
+    NS_decodeN32(self->mInputFrameBuffer.get() + kFrameHeaderBytes);
   delta &= 0x7fffffff;
 
   LOG3(("Http2Session::RecvWindowUpdate %p len=%d Stream 0x%X.\n",
@@ -2416,7 +2415,7 @@
 
     // 3 bytes of length, 1 type byte, 1 flag byte, 1 unused bit, 31 bits of ID
     uint8_t totallyWastedByte = mInputFrameBuffer.get()[0];
-    mInputFrameDataSize = PR_ntohs(*reinterpret_cast<uint16_t *>(mInputFrameBuffer.get() + 1));
+    mInputFrameDataSize = NS_decodeN16(mInputFrameBuffer.get() + 1);
     if (totallyWastedByte || (mInputFrameDataSize > kMaxFrameData)) {
       LOG3(("Got frame too large 0x%02X%04X", totallyWastedByte, mInputFrameDataSize));
       RETURN_SESSION_ERROR(this, PROTOCOL_ERROR);
@@ -2424,7 +2423,7 @@
     mInputFrameType = *reinterpret_cast<uint8_t *>(mInputFrameBuffer.get() + kFrameLengthBytes);
     mInputFrameFlags = *reinterpret_cast<uint8_t *>(mInputFrameBuffer.get() + kFrameLengthBytes + kFrameTypeBytes);
     mInputFrameID =
-      PR_ntohl(*reinterpret_cast<uint32_t *>(mInputFrameBuffer.get() + kFrameLengthBytes + kFrameTypeBytes + kFrameFlagBytes));
+      NS_decodeN32(mInputFrameBuffer.get() + kFrameLengthBytes + kFrameTypeBytes + kFrameFlagBytes);
     mInputFrameID &= 0x7fffffff;
     mInputFrameDataRead = 0;
 
