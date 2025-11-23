# $NetBSD: modules.mk,v 1.2 2025/11/23 13:38:20 ryoon Exp $
#
# This Makefile fragment is intended to be included by packages that install
# GTK4 modules.  It takes care of rebuilding the corresponding databases at
# (de)installation time.
#
# The following variables can be defined:
#    GTK4_IMMODULES - Set to YES if the package installs immodules.
#

.if !defined(GTK4_MODULES_MK)
GTK4_MODULES_MK=	# defined

.if defined(_BUILDING_GTK4)
BUILDLINK_PREFIX.gtk4=	${PREFIX}
GTK4_IMMODULES=		YES
.endif

.if defined(GTK4_IMMODULES) && !empty(GTK4_IMMODULES:M[Yy][Ee][Ss])
FILES_SUBST+=		GTK4_IMMODULES_DB=${GTK4_IMMODULES_DB:Q}
GTK4_IMMODULES_DB=	${BUILDLINK_PREFIX.gtk4}/lib/gtk-4.0/4.0.0/immodules.cache
INSTALL_TEMPLATES+=	../../x11/gtk4/files/immodules.tmpl
DEINSTALL_TEMPLATES+=	../../x11/gtk4/files/immodules.tmpl
.endif

PRINT_PLIST_AWK+=	/^libdata\/gtk-4.0/ { next; }

.if !defined(_BUILDING_GTK4)
.  include "../../x11/gtk4/buildlink3.mk"
.endif

.endif			# GTK4_MODULES_MK
