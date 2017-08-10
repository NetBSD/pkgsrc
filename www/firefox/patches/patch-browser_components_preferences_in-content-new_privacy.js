$NetBSD: patch-browser_components_preferences_in-content-new_privacy.js,v 1.1 2017/08/10 14:46:15 ryoon Exp $

--- browser/components/preferences/in-content-new/privacy.js.orig	2017-07-31 16:20:48.000000000 +0000
+++ browser/components/preferences/in-content-new/privacy.js
@@ -321,11 +321,9 @@ var gPrivacyPane = {
       this.initSubmitCrashes();
     }
     this.initTelemetry();
-    if (AppConstants.MOZ_TELEMETRY_REPORTING) {
-      this.initSubmitHealthReport();
-      setEventListener("submitHealthReportBox", "command",
-                       gPrivacyPane.updateSubmitHealthReport);
-    }
+    this.initSubmitHealthReport();
+    setEventListener("submitHealthReportBox", "command",
+                     gPrivacyPane.updateSubmitHealthReport);
 
     // Append search keywords into the elements could open subdialogs.
     let bundlePrefs = document.getElementById("bundlePreferences");
@@ -1414,8 +1412,10 @@ var gPrivacyPane = {
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
 
@@ -1439,9 +1439,6 @@ var gPrivacyPane = {
    * @param {Boolean} aEnabled False disables the controls, true enables them.
    */
   setTelemetrySectionEnabled(aEnabled) {
-    if (!AppConstants.MOZ_TELEMETRY_REPORTING) {
-      return;
-    }
     // If FHR is disabled, additional data sharing should be disabled as well.
     let disabled = !aEnabled;
     document.getElementById("submitTelemetryBox").disabled = disabled;
@@ -1456,19 +1453,21 @@ var gPrivacyPane = {
    * Initialize the health report service reference and checkbox.
    */
   initSubmitHealthReport() {
-    if (!AppConstants.MOZ_TELEMETRY_REPORTING) {
-      return;
-    }
     this._setupLearnMoreLink("datareporting.healthreport.infoURL", "FHRLearnMore");
 
     let checkbox = document.getElementById("submitHealthReportBox");
 
-    if (Services.prefs.prefIsLocked(PREF_UPLOAD_ENABLED)) {
+    // Telemetry is only sending data if MOZ_TELEMETRY_REPORTING is defined.
+    // We still want to display the preferences panel if that's not the case, but
+    // we want it to be disabled and unchecked.
+    if (Services.prefs.prefIsLocked(PREF_UPLOAD_ENABLED) ||
+        !AppConstants.MOZ_TELEMETRY_REPORTING) {
       checkbox.setAttribute("disabled", "true");
       return;
     }
 
-    checkbox.checked = Services.prefs.getBoolPref(PREF_UPLOAD_ENABLED);
+    checkbox.checked = Services.prefs.getBoolPref(PREF_UPLOAD_ENABLED) &&
+                       AppConstants.MOZ_TELEMETRY_REPORTING;
     this.setTelemetrySectionEnabled(checkbox.checked);
   },
 
@@ -1476,9 +1475,6 @@ var gPrivacyPane = {
    * Update the health report preference with state from checkbox.
    */
   updateSubmitHealthReport() {
-    if (!AppConstants.MOZ_TELEMETRY_REPORTING) {
-      return;
-    }
     let checkbox = document.getElementById("submitHealthReportBox");
     Services.prefs.setBoolPref(PREF_UPLOAD_ENABLED, checkbox.checked);
     this.setTelemetrySectionEnabled(checkbox.checked);
