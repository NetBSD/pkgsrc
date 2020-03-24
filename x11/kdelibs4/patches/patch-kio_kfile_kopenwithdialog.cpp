$NetBSD: patch-kio_kfile_kopenwithdialog.cpp,v 1.1 2020/03/24 20:34:31 joerg Exp $

--- kio/kfile/kopenwithdialog.cpp.orig	2020-03-23 21:21:08.509600415 +0000
+++ kio/kfile/kopenwithdialog.cpp
@@ -713,7 +713,7 @@ void KOpenWithDialog::slotHighlighted(co
         // ### indicate that default value was restored
         d->terminal->setChecked(d->curService->terminal());
         QString terminalOptions = d->curService->terminalOptions();
-        d->nocloseonexit->setChecked((terminalOptions.contains(QLatin1String("--noclose")) > 0));
+        d->nocloseonexit->setChecked((terminalOptions.contains(QLatin1String("--noclose")) != 0));
         d->m_terminaldirty = false; // slotTerminalToggled changed it
     }
 }
