$NetBSD: patch-src_acpustatus.cc,v 1.1 2019/12/10 19:22:36 plunky Exp $

fix CPU Status applet

--- src/acpustatus.cc.orig	2017-07-30 08:53:35.524267864 +0000
+++ src/acpustatus.cc
@@ -305,20 +305,15 @@ void CPUStatus::updateToolTip() {
         }
         setToolTip(ustring(fmt));
     }
-#elif defined HAVE_GETLOADAVG2
-    char load[sizeof("999.99 999.99 999.99")];
+#elif defined HAVE_GETLOADAVG
+    char fmt[255];
     double loadavg[3];
     if (getloadavg(loadavg, 3) < 0)
         return;
-    snprintf(load, sizeof(load), "%3.2g %3.2g %3.2g",
-            loadavg[0], loadavg[1], loadavg[2]);
-    {
-        char id[10];
-        snprintf(id, sizeof[id], " %d ", cpuid);
-        char *loadmsg = cstrJoin(_("CPU"), id ,_("Load: "), load, NULL);
-        setToolTip(ustring(loadmsg));
-        delete [] loadmsg;
-    }
+    snprintf(fmt, sizeof(fmt), "%s %s %s: %3.2g %3.2g %3.2g",
+	    _("CPU"), cpuid,
+            _("Load"), loadavg[0], loadavg[1], loadavg[2]);
+    setToolTip(ustring(fmt));
 #endif
 }
 
@@ -634,6 +629,7 @@ void CPUStatus::getStatus() {
 #else
     typedef long cp_time_t;
 #endif
+#ifndef HAVE_SYSCTLBYNAME
 #if defined KERN_CPTIME
     static int mib[] = { CTL_KERN, KERN_CPTIME };
 #elif defined KERN_CP_TIME
@@ -641,6 +637,7 @@ void CPUStatus::getStatus() {
 #else
     static int mib[] = { 0, 0 };
 #endif
+#endif
 
     cp_time_t cp_time[CPUSTATES];
     size_t len = sizeof( cp_time );
@@ -713,7 +710,7 @@ void CPUStatus::GetCPUStatus(YSMListener
         CPUStatus::getCPUStatusCombined(aParent, fCPUStatus);
     }
 #elif defined(HAVE_SYSCTL_CP_TIME)
-    CPUStatus::getCPUStatusCombined(aParent, fCPUStatus);
+    CPUStatus::getCPUStatusCombined(smActionListener, aParent, fCPUStatus);
 #endif
 }
 void CPUStatus::getCPUStatusCombined(YSMListener *smActionListener, YWindow *aParent, CPUStatus **&fCPUStatus) {
