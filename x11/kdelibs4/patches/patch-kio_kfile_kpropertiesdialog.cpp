$NetBSD: patch-kio_kfile_kpropertiesdialog.cpp,v 1.1 2020/03/24 20:34:31 joerg Exp $

--- kio/kfile/kpropertiesdialog.cpp.orig	2020-03-23 21:17:50.440194279 +0000
+++ kio/kfile/kpropertiesdialog.cpp
@@ -3306,7 +3306,7 @@ void KDesktopPropsPlugin::slotAdvanced()
 
     if (preferredTerminal == "konsole")
     {
-        terminalCloseBool = (d->m_terminalOptionStr.contains( "--noclose" ) > 0);
+        terminalCloseBool = (d->m_terminalOptionStr.contains( "--noclose" ) != 0);
         w.terminalCloseCheck->setChecked(terminalCloseBool);
         d->m_terminalOptionStr.remove( "--noclose");
     }
