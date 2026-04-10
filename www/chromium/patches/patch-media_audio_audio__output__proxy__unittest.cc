$NetBSD: patch-media_audio_audio__output__proxy__unittest.cc,v 1.17 2026/04/10 17:31:56 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- media/audio/audio_output_proxy_unittest.cc.orig	2026-04-06 16:25:54.000000000 +0000
+++ media/audio/audio_output_proxy_unittest.cc
@@ -445,7 +445,11 @@ class AudioOutputProxyTest : public test
     // |stream| is closed at this point. Start() should reopen it again.
     EXPECT_CALL(manager(), MakeAudioOutputStream(_, _, _))
         .Times(2)
+#if BUILDFLAG(IS_BSD)
+        .WillRepeatedly(Return(static_cast<AudioOutputStream*>(NULL)));
+#else
         .WillRepeatedly(Return(reinterpret_cast<AudioOutputStream*>(NULL)));
+#endif
 
     EXPECT_CALL(callback_, OnError(_)).Times(2);
 
