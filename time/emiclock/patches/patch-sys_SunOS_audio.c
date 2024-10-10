$NetBSD: patch-sys_SunOS_audio.c,v 1.1 2024/10/10 17:21:09 nia Exp $

Remove harmful workarounds for ancient Solaris.

--- sys/SunOS/audio.c.orig	2024-10-10 17:17:57.716810224 +0000
+++ sys/SunOS/audio.c
@@ -176,13 +176,8 @@ SoundCacheBuffer	*cacheBufferPtr;
 	SoundTimeBytes = (cacheBufferPtr->soundBParam.play.precision / 8) *
 				cacheBufferPtr->soundBParam.play.channels *
 				cacheBufferPtr->soundBParam.play.sample_rate;
-#ifdef solaris
-	sigset(SIGALRM, S_PlayInterval);
-	gettimeofday(&SoundStart);
-#else
 	signal(SIGALRM, S_PlayInterval);
 	gettimeofday(&SoundStart, NULL);
-#endif
 	S_PlayInterval();
 	return SOUND_NO_ERROR;
 }
@@ -226,11 +221,7 @@ S_PlayInterval()
 			SoundBufPtr += nbytes;
 			timer = ((double)SoundPlayed / (double)SoundTimeBytes)
 								* 1000000;
-#ifdef solaris
-			gettimeofday(&now);
-#else
 			gettimeofday(&now, NULL);
-#endif
 			timer -= (now.tv_sec - SoundStart.tv_sec) * 1000000
 					+ now.tv_usec - SoundStart.tv_usec;
 			if (timer <= 0)
