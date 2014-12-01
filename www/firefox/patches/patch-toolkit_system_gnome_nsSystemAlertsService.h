$NetBSD: patch-toolkit_system_gnome_nsSystemAlertsService.h,v 1.1 2014/12/01 18:11:14 ryoon Exp $

--- toolkit/system/gnome/nsSystemAlertsService.h.orig	2014-11-30 06:26:27.000000000 +0000
+++ toolkit/system/gnome/nsSystemAlertsService.h
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
