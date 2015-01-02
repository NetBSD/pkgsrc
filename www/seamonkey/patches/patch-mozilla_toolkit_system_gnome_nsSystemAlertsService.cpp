$NetBSD: patch-mozilla_toolkit_system_gnome_nsSystemAlertsService.cpp,v 1.1 2015/01/02 04:26:21 ryoon Exp $

--- mozilla/toolkit/system/gnome/nsSystemAlertsService.cpp.orig	2015-01-01 17:45:06.000000000 +0000
+++ mozilla/toolkit/system/gnome/nsSystemAlertsService.cpp
@@ -0,0 +1,54 @@
+/* -*- Mode: C++; tab-width: 2; indent-tabs-mode:nil; c-basic-offset: 2 -*- */
+/* This Source Code Form is subject to the terms of the Mozilla Public
+ * License, v. 2.0. If a copy of the MPL was not distributed with this
+ * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
+
+#include "nsXULAppAPI.h"
+#include "nsSystemAlertsService.h"
+#include "nsAlertsIconListener.h"
+#include "nsAutoPtr.h"
+
+NS_IMPL_ADDREF(nsSystemAlertsService)
+NS_IMPL_RELEASE(nsSystemAlertsService)
+
+NS_INTERFACE_MAP_BEGIN(nsSystemAlertsService)
+   NS_INTERFACE_MAP_ENTRY_AMBIGUOUS(nsISupports, nsIAlertsService)
+   NS_INTERFACE_MAP_ENTRY(nsIAlertsService)
+NS_INTERFACE_MAP_END_THREADSAFE
+
+nsSystemAlertsService::nsSystemAlertsService()
+{
+}
+
+nsSystemAlertsService::~nsSystemAlertsService()
+{}
+
+nsresult
+nsSystemAlertsService::Init()
+{
+  return NS_OK;
+}
+
+NS_IMETHODIMP nsSystemAlertsService::ShowAlertNotification(const nsAString & aImageUrl, const nsAString & aAlertTitle, 
+                                                           const nsAString & aAlertText, bool aAlertTextClickable,
+                                                           const nsAString & aAlertCookie,
+                                                           nsIObserver * aAlertListener,
+                                                           const nsAString & aAlertName,
+                                                           const nsAString & aBidi,
+                                                           const nsAString & aLang,
+                                                           const nsAString & aData,
+                                                           nsIPrincipal * aPrincipal)
+{
+  nsRefPtr<nsAlertsIconListener> alertListener = new nsAlertsIconListener();
+  if (!alertListener)
+    return NS_ERROR_OUT_OF_MEMORY;
+
+  return alertListener->InitAlertAsync(aImageUrl, aAlertTitle, aAlertText, aAlertTextClickable,
+                                       aAlertCookie, aAlertListener);
+}
+
+NS_IMETHODIMP nsSystemAlertsService::CloseAlert(const nsAString& aAlertName,
+                                                nsIPrincipal* aPrincipal)
+{
+  return NS_ERROR_NOT_IMPLEMENTED;
+}
