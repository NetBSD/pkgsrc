$NetBSD: patch-dom_media_webrtc_MediaEngine.h,v 1.1 2017/04/27 01:49:47 ryoon Exp $

--- dom/media/webrtc/MediaEngine.h.orig	2017-04-11 04:15:22.000000000 +0000
+++ dom/media/webrtc/MediaEngine.h
@@ -226,7 +226,7 @@ public:
     ~AllocationHandle() {}
   public:
     AllocationHandle(const dom::MediaTrackConstraints& aConstraints,
-                     const ipc::PrincipalInfo& aPrincipalInfo,
+                     const mozilla::ipc::PrincipalInfo& aPrincipalInfo,
                      const MediaEnginePrefs& aPrefs,
                      const nsString& aDeviceId)
 
@@ -236,7 +236,7 @@ public:
       mDeviceId(aDeviceId) {}
   public:
     NormalizedConstraints mConstraints;
-    ipc::PrincipalInfo mPrincipalInfo;
+    mozilla::ipc::PrincipalInfo mPrincipalInfo;
     MediaEnginePrefs mPrefs;
     nsString mDeviceId;
   };
@@ -327,7 +327,7 @@ public:
   virtual nsresult Allocate(const dom::MediaTrackConstraints &aConstraints,
                             const MediaEnginePrefs &aPrefs,
                             const nsString& aDeviceId,
-                            const ipc::PrincipalInfo& aPrincipalInfo,
+                            const mozilla::ipc::PrincipalInfo& aPrincipalInfo,
                             AllocationHandle** aOutHandle,
                             const char** aOutBadConstraint)
   {
