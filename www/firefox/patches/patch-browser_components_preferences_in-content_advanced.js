$NetBSD: patch-browser_components_preferences_in-content_advanced.js,v 1.1 2017/08/10 14:46:15 ryoon Exp $

--- browser/components/preferences/in-content/advanced.js.orig	2017-07-31 16:20:48.000000000 +0000
+++ browser/components/preferences/in-content/advanced.js
@@ -46,9 +46,7 @@ var gAdvancedPane = {
       this.initSubmitCrashes();
     }
     this.initTelemetry();
-    if (AppConstants.MOZ_TELEMETRY_REPORTING) {
-      this.initSubmitHealthReport();
-    }
+    this.initSubmitHealthReport();
     this.updateOnScreenKeyboardVisibility();
     this.updateCacheSizeInputField();
     this.updateActualCacheSize();
@@ -78,10 +76,8 @@ var gAdvancedPane = {
                      gAdvancedPane.updateHardwareAcceleration);
     setEventListener("advancedPrefs", "select",
                      gAdvancedPane.tabSelectionChanged);
-    if (AppConstants.MOZ_TELEMETRY_REPORTING) {
-      setEventListener("submitHealthReportBox", "command",
-                       gAdvancedPane.updateSubmitHealthReport);
-    }
+    setEventListener("submitHealthReportBox", "command",
+                     gAdvancedPane.updateSubmitHealthReport);
 
     setEventListener("connectionSettings", "command",
                      gAdvancedPane.showConnections);
@@ -293,8 +289,10 @@ var gAdvancedPane = {
    * In all cases, set up the Learn More link sanely.
    */
   initTelemetry() {
-    if (AppConstants.MOZ_TELEMETRY_REPORTING) {
-      this._setupLearnMoreLink("toolkit.telemetry.infoURL", "telemetryLearnMore");
+    this._setupLearnMoreLink("toolkit.telemetry.infoURL", "telemetryLearnMore");
+    // If we're not sending any Telemetry, disable the telemetry upload checkbox as well.
+    if (!AppConstants.MOZ_TELEMETRY_REPORTING) {
+      document.getElementById("submitTelemetryBox").setAttribute("disabled", "true");
     }
   },
 
@@ -303,46 +301,45 @@ var gAdvancedPane = {
    * @param {Boolean} aEnabled False disables the controls, true enables them.
    */
   setTelemetrySectionEnabled(aEnabled) {
-    if (AppConstants.MOZ_TELEMETRY_REPORTING) {
-      // If FHR is disabled, additional data sharing should be disabled as well.
-      let disabled = !aEnabled;
-      document.getElementById("submitTelemetryBox").disabled = disabled;
-      if (disabled) {
-        // If we disable FHR, untick the telemetry checkbox.
-        Services.prefs.setBoolPref("toolkit.telemetry.enabled", false);
-      }
-      document.getElementById("telemetryDataDesc").disabled = disabled;
+    // If FHR is disabled, additional data sharing should be disabled as well.
+    let disabled = !aEnabled;
+    document.getElementById("submitTelemetryBox").disabled = disabled;
+    if (disabled) {
+      // If we disable FHR, untick the telemetry checkbox.
+      Services.prefs.setBoolPref("toolkit.telemetry.enabled", false);
     }
+    document.getElementById("telemetryDataDesc").disabled = disabled;
   },
 
   /**
    * Initialize the health report service reference and checkbox.
    */
   initSubmitHealthReport() {
-    if (AppConstants.MOZ_TELEMETRY_REPORTING) {
-      this._setupLearnMoreLink("datareporting.healthreport.infoURL", "FHRLearnMore");
-
-      let checkbox = document.getElementById("submitHealthReportBox");
+    this._setupLearnMoreLink("datareporting.healthreport.infoURL", "FHRLearnMore");
 
-      if (Services.prefs.prefIsLocked(PREF_UPLOAD_ENABLED)) {
-        checkbox.setAttribute("disabled", "true");
-        return;
-      }
+    let checkbox = document.getElementById("submitHealthReportBox");
 
-      checkbox.checked = Services.prefs.getBoolPref(PREF_UPLOAD_ENABLED);
-      this.setTelemetrySectionEnabled(checkbox.checked);
+    // Telemetry is only sending data if MOZ_TELEMETRY_REPORTING is defined.
+    // We still want to display the preferences panel if that's not the case, but
+    // we want it to be disabled and unchecked.
+    if (Services.prefs.prefIsLocked(PREF_UPLOAD_ENABLED) ||
+        !AppConstants.MOZ_TELEMETRY_REPORTING) {
+      checkbox.setAttribute("disabled", "true");
+      return;
     }
+
+    checkbox.checked = Services.prefs.getBoolPref(PREF_UPLOAD_ENABLED) &&
+                       AppConstants.MOZ_TELEMETRY_REPORTING;
+    this.setTelemetrySectionEnabled(checkbox.checked);
   },
 
   /**
    * Update the health report preference with state from checkbox.
    */
   updateSubmitHealthReport() {
-    if (AppConstants.MOZ_TELEMETRY_REPORTING) {
-      let checkbox = document.getElementById("submitHealthReportBox");
-      Services.prefs.setBoolPref(PREF_UPLOAD_ENABLED, checkbox.checked);
-      this.setTelemetrySectionEnabled(checkbox.checked);
-    }
+    let checkbox = document.getElementById("submitHealthReportBox");
+    Services.prefs.setBoolPref(PREF_UPLOAD_ENABLED, checkbox.checked);
+    this.setTelemetrySectionEnabled(checkbox.checked);
   },
 
   updateOnScreenKeyboardVisibility() {
