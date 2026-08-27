$NetBSD: patch-dom_media_mediacapabilities_MediaCapabilitiesValidation.cpp,v 1.1 2026/08/27 01:23:16 gutteridge Exp $

--- dom/media/mediacapabilities/MediaCapabilitiesValidation.cpp.orig	2026-07-13 13:09:12.000000000 +0000
+++ dom/media/mediacapabilities/MediaCapabilitiesValidation.cpp
@@ -263,7 +263,7 @@ ValidationResult IsValidVideoConfiguration(const Video
 
   // Step 1: If framerate is not finite or is not greater than 0,
   // return false and abort these steps.
-  if (!isfinite(aConfig.mFramerate) || !(aConfig.mFramerate > 0)) {
+  if (!std::isfinite(aConfig.mFramerate) || !(aConfig.mFramerate > 0)) {
     ValidationResult err = Err(ValidationError::FramerateInvalid);
     LOG(("[Invalid VideoConfiguration (Framerate, {}) #1] Rejecting '{}'\n",
          EnumValueToString(err.unwrapErr()),
