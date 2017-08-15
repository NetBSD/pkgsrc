$NetBSD: patch-build-utils_lgi-check.sh,v 1.2 2017/08/15 10:57:35 triaxx Exp $

Use pkgsrc lua interpreter instead of builtin one.

--- build-utils/lgi-check.sh.orig	2017-07-15 13:53:13.000000000 +0000
+++ build-utils/lgi-check.sh
@@ -22,16 +22,16 @@ die()
 }
 
 # Check if we have lgi
-lua -e 'require("lgi")' || die
+@LUA_INTERPRETER@ -e 'require("lgi")' || die
 
 # Check the version number.
 # Keep this in sync with lib/gears/surface.lua and .travis.yml (LGIVER)!
-lua -e '_, _, major_minor, patch = string.find(require("lgi.version"), "^(%d%.%d)%.(%d)");
+@LUA_INTERPRETER@ -e '_, _, major_minor, patch = string.find(require("lgi.version"), "^(%d%.%d)%.(%d)");
 	if tonumber(major_minor) < 0.8 or (tonumber(major_minor) == 0.8 and tonumber(patch) < 0) then
 		error(string.format("lgi is too old, need at least version %s, got %s.",
 		                    "0.8.0", require("lgi.version"))) end' || die
 
 # Check for the needed gi files
-lua -e 'l = require("lgi") assert(l.cairo, l.Pango, l.PangoCairo, l.GLib, l.Gio)' || die
+@LUA_INTERPRETER@ -e 'l = require("lgi") assert(l.cairo, l.Pango, l.PangoCairo, l.GLib, l.Gio)' || die
 
 # vim: filetype=sh:expandtab:shiftwidth=4:tabstop=8:softtabstop=4:textwidth=80
