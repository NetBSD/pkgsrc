$NetBSD: patch-mozilla_toolkit_system_gnome_nsSystemAlertsService.h,v 1.1 2015/01/02 04:26:21 ryoon Exp $

--- mozilla/toolkit/system/gnome/nsSystemAlertsService.h.orig	2015-01-01 17:45:06.000000000 +0000
+++ mozilla/toolkit/system/gnome/nsSystemAlertsService.h
@@ -0,0 +1,27 @@
+/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
+/* This Source Code Form is subject to the terms of the Mozilla Public
+ * License, v. 2.0. If a copy of the MPL was not distributed with this
+ * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
+
+#ifndef nsSystemAlertsService_h__
+#define nsSystemAlertsService_h__
+
+#include "nsIAlertsService.h"
+#include "nsCOMPtr.h"
+
+class nsSystemAlertsService : public nsIAlertsService
+{
+public:
+  NS_DECL_NSIALERTSSERVICE
+  NS_DECL_ISUPPORTS
+
+  nsSystemAlertsService();
+
+  nsresult Init();
+
+protected:
+  virtual ~nsSystemAlertsService();
+
+};
+
+#endif /* nsSystemAlertsService_h__ */
