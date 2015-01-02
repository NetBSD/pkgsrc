$NetBSD: patch-mozilla_toolkit_components_alerts_nsAlertsService.cpp,v 1.1 2015/01/02 04:26:21 ryoon Exp $

--- mozilla/toolkit/components/alerts/nsAlertsService.cpp.orig	2014-12-03 06:23:24.000000000 +0000
+++ mozilla/toolkit/components/alerts/nsAlertsService.cpp
@@ -100,10 +100,12 @@ NS_IMETHODIMP nsAlertsService::ShowAlert
   nsCOMPtr<nsIAlertsService> sysAlerts(do_GetService(NS_SYSTEMALERTSERVICE_CONTRACTID));
   nsresult rv;
   if (sysAlerts) {
-    return sysAlerts->ShowAlertNotification(aImageUrl, aAlertTitle, aAlertText, aAlertTextClickable,
-                                            aAlertCookie, aAlertListener, aAlertName,
-                                            aBidi, aLang, aData,
-                                            IPC::Principal(aPrincipal));
+    rv = sysAlerts->ShowAlertNotification(aImageUrl, aAlertTitle, aAlertText, aAlertTextClickable,
+                                          aAlertCookie, aAlertListener, aAlertName,
+                                          aBidi, aLang, aData,
+                                          IPC::Principal(aPrincipal));
+    if (NS_SUCCEEDED(rv))
+      return NS_OK;
   }
 
   if (!ShouldShowAlert()) {
