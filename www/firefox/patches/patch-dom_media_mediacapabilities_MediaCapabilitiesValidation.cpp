$NetBSD: patch-dom_media_mediacapabilities_MediaCapabilitiesValidation.cpp,v 1.1 2026/01/19 12:06:04 ryoon Exp $

--- dom/media/mediacapabilities/MediaCapabilitiesValidation.cpp.orig	2026-01-03 09:52:49.089840762 +0000
+++ dom/media/mediacapabilities/MediaCapabilitiesValidation.cpp
@@ -199,7 +199,7 @@ ValidationResult IsValidVideoConfiguration(const Video
 
   // Step 1: If framerate is not finite or is not greater than 0,
   // return false and abort these steps.
-  if (!isfinite(aConfig.mFramerate) || !(aConfig.mFramerate > 0)) {
+  if (!std::isfinite(aConfig.mFramerate) || !(aConfig.mFramerate > 0)) {
     ValidationResult err = Err(ValidationError::FramerateInvalid);
     LOG(("[Invalid VideoConfiguration (Framerate, %s) #1] Rejecting '%s'\n",
          EnumValueToString(err.unwrapErr()),
