# $NetBSD: modules.mk,v 1.1.1.1 2011/03/18 17:06:10 drochner Exp $
#
# This Makefile fragment is intended to be included by packages that install
# GTK3 modules.  It takes care of rebuilding the corresponding databases at
# (de)installation time.
#
# The following variables can be defined:
#    GTK3_IMMODULES - Set to YES if the package installs immodules.
#

.if !defined(GTK3_MODULES_MK)
GTK3_MODULES_MK=	# defined

GTK_QUERY_IMMODULES=	${BUILDLINK_PREFIX.gtk3}/bin/gtk-query-immodules-3.0

.if defined(_BUILDING_GTK3)
BUILDLINK_PREFIX.gtk3=	${PREFIX}
GTK3_IMMODULES=		YES
.endif

.if defined(GTK3_IMMODULES) && !empty(GTK3_IMMODULES:M[Yy][Ee][Ss])
FILES_SUBST+=		GTK_IMMODULES_DB=${GTK_IMMODULES_DB:Q}
FILES_SUBST+=		GTK_QUERY_IMMODULES=${GTK_QUERY_IMMODULES:Q}
GTK_IMMODULES_DB=	${BUILDLINK_PREFIX.gtk3}/libdata/gtk-3.0/gtk.immodules
INSTALL_TEMPLATES+=	../../x11/gtk3/files/immodules.tmpl
DEINSTALL_TEMPLATES+=	../../x11/gtk3/files/immodules.tmpl
.endif

PRINT_PLIST_AWK+=	/^libdata\/gtk-3.0/ { next; }

.if !defined(_BUILDING_GTK3)
.  include "../../x11/gtk3/buildlink3.mk"
.endif

.endif			# GTK3_MODULES_MK
