$NetBSD: patch-dom_plugins_base_nsNPAPIPlugin.cpp,v 1.1 2014/05/29 15:38:19 pho Exp $

Don't assume cocoa toolkit just because OS_ARCH is Darwin.

--- dom/plugins/base/nsNPAPIPlugin.cpp.orig	2014-05-06 22:55:25.000000000 +0000
+++ dom/plugins/base/nsNPAPIPlugin.cpp
@@ -302,7 +302,7 @@ nsNPAPIPlugin::RunPluginOOP(const nsPlug
   prefFile.Cut(0, slashPos + 1);
   ToLowerCase(prefFile);
 
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
 #if defined(__i386__)
   nsAutoCString prefGroupKey("dom.ipc.plugins.enabled.i386.");
 #elif defined(__x86_64__)
@@ -364,7 +364,7 @@ nsNPAPIPlugin::RunPluginOOP(const nsPlug
 
   if (!prefSet) {
     oopPluginsEnabled =
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
 #if defined(__i386__)
     Preferences::GetBool("dom.ipc.plugins.enabled.i386", false);
 #elif defined(__x86_64__)
@@ -417,7 +417,7 @@ nsNPAPIPlugin::CreatePlugin(nsPluginTag 
     return NS_ERROR_FAILURE;
   }
 
-#if defined(XP_MACOSX) || defined(MOZ_WIDGET_ANDROID)
+#if defined(MOZ_WIDGET_COCOA) || defined(MOZ_WIDGET_ANDROID)
   if (!pluginLib->HasRequiredFunctions()) {
     NS_WARNING("Not all necessary functions exposed by plugin, it will not load.");
     return NS_ERROR_FAILURE;
@@ -443,7 +443,7 @@ nsNPAPIPlugin::CreatePlugin(nsPluginTag 
   if (rv != NS_OK || pluginCallError != NPERR_NO_ERROR) {
     return NS_ERROR_FAILURE;
   }
-#elif defined(XP_MACOSX)
+#elif defined(MOZ_WIDGET_COCOA)
   // NP_Initialize must be called before NP_GetEntryPoints on Mac OS X.
   // We need to match WebKit's behavior.
   rv = pluginLib->NP_Initialize(&sBrowserFuncs, &pluginCallError);
@@ -1892,7 +1892,7 @@ _getvalue(NPP npp, NPNVariable variable,
   PluginDestructionGuard guard(npp);
 
   switch(variable) {
-#if defined(XP_UNIX) && !defined(XP_MACOSX)
+#if defined(XP_UNIX) && !defined(MOZ_WIDGET_COCOA)
   case NPNVxDisplay : {
 #if defined(MOZ_X11)
     if (npp) {
@@ -2027,7 +2027,7 @@ _getvalue(NPP npp, NPNVariable variable,
   }
 
   case NPNVSupportsWindowless: {
-#if defined(XP_WIN) || defined(XP_MACOSX) || \
+#if defined(XP_WIN) || defined(MOZ_WIDGET_COCOA) || \
     (defined(MOZ_X11) && (defined(MOZ_WIDGET_GTK) || defined(MOZ_WIDGET_QT)))
     *(NPBool*)result = true;
 #else
@@ -2089,7 +2089,7 @@ _getvalue(NPP npp, NPNVariable variable,
     return *(char**)result ? NPERR_NO_ERROR : NPERR_GENERIC_ERROR;
   }
 
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
   case NPNVpluginDrawingModel: {
     if (npp) {
       nsNPAPIPluginInstance *inst = (nsNPAPIPluginInstance*)npp->ndata;
@@ -2376,7 +2376,7 @@ _setvalue(NPP npp, NPPVariable variable,
     // actual pointer value is checked rather than its content
     // when passing booleans
     case NPPVpluginWindowBool: {
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
       // This setting doesn't apply to OS X (only to Windows and Unix/Linux).
       // See https://developer.mozilla.org/En/NPN_SetValue#section_5.  Return
       // NPERR_NO_ERROR here to conform to other browsers' behavior on OS X
@@ -2420,7 +2420,7 @@ _setvalue(NPP npp, NPPVariable variable,
     }
 #endif
 
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
     case NPPVpluginEventModel: {
       if (inst) {
         inst->SetEventModel((NPEventModel)NS_PTR_TO_INT32(result));
