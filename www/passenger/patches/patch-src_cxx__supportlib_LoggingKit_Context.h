$NetBSD: patch-src_cxx__supportlib_LoggingKit_Context.h,v 1.2 2018/04/04 12:47:44 fhajny Exp $

Avoid ambiguous reference on (at least) SunOS.

--- src/cxx_supportlib/LoggingKit/Context.h.orig	2013-10-27 00:00:00.000000000 +0000
+++ src/cxx_supportlib/LoggingKit/Context.h
@@ -78,7 +78,7 @@ private:
 	mutable boost::mutex gcSyncher;
 	oxt::thread *gcThread;
 	boost::condition_variable gcShuttingDownCond, gcHasShutDownCond;
-	queue< pair<ConfigRealization *, MonotonicTimeUsec> > oldConfigs;
+	std::queue< pair<ConfigRealization *, MonotonicTimeUsec> > oldConfigs;
 	bool shuttingDown;
 
 	struct TimestampedLog {
