$NetBSD: patch-src_3rdparty_chromium_google__apis_gcm_engine_heartbeat__manager.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/google_apis/gcm/engine/heartbeat_manager.cc.orig	2020-07-08 21:40:44.000000000 +0000
+++ src/3rdparty/chromium/google_apis/gcm/engine/heartbeat_manager.cc
@@ -31,7 +31,7 @@ const int kMinClientHeartbeatIntervalMs 
 // Minimum time spent sleeping before we force a new heartbeat.
 const int kMinSuspendTimeMs = 1000 * 10; // 10 seconds.
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
 // The period at which to check if the heartbeat time has passed. Used to
 // protect against platforms where the timer is delayed by the system being
 // suspended.  Only needed on linux because the other OSes provide a standard
@@ -191,7 +191,7 @@ void HeartbeatManager::RestartTimer() {
       base::BindRepeating(&HeartbeatManager::OnHeartbeatTriggered,
                           weak_ptr_factory_.GetWeakPtr()));
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   // Windows, Mac, Android, iOS, and Chrome OS all provide a way to be notified
   // when the system is suspending or resuming.  The only one that does not is
   // Linux so we need to poll to check for missed heartbeats.
@@ -216,7 +216,7 @@ void HeartbeatManager::CheckForMissedHea
     return;
   }
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   // Otherwise check again later.
   io_task_runner_->PostDelayedTask(
       FROM_HERE,
