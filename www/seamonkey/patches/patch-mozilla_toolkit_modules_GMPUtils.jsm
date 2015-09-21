$NetBSD: patch-mozilla_toolkit_modules_GMPUtils.jsm,v 1.1 2015/09/21 05:03:45 ryoon Exp $

--- mozilla/toolkit/modules/GMPUtils.jsm.orig	2015-09-02 09:27:31.000000000 +0000
+++ mozilla/toolkit/modules/GMPUtils.jsm
@@ -74,6 +74,7 @@ this.GMPPrefs = {
   KEY_EME_ENABLED:              "media.eme.enabled",
   KEY_PLUGIN_ENABLED:           "media.{0}.enabled",
   KEY_PLUGIN_LAST_UPDATE:       "media.{0}.lastUpdate",
+  KEY_PLUGIN_PATH:              "media.{0}.path",
   KEY_PLUGIN_VERSION:           "media.{0}.version",
   KEY_PLUGIN_AUTOUPDATE:        "media.{0}.autoupdate",
   KEY_PLUGIN_FORCEVISIBLE:      "media.{0}.forcevisible",
