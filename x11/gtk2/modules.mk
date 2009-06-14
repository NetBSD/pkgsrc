# $NetBSD: modules.mk,v 1.15 2009/06/14 22:58:11 joerg Exp $
#
# This Makefile fragment is intended to be included by packages that install
# GTK2 modules.  It takes care of rebuilding the corresponding databases at
# (de)installation time.
#
# The following variables can be defined:
#    GTK2_IMMODULES - Set to YES if the package installs immodules.
#    GTK2_LOADERS   - Set to YES if the package installs pixbuf loaders.
#

.if !defined(GTK2_MODULES_MK)
GTK2_MODULES_MK=	# defined

GTK_QUERY_IMMODULES=	${BUILDLINK_PREFIX.gtk2}/bin/gtk-query-immodules-2.0
GDK_PIXBUF_QUERY_LOADERS=	${BUILDLINK_PREFIX.gtk2}/bin/gdk-pixbuf-query-loaders

.if defined(_BUILDING_GTK2)
BUILDLINK_PREFIX.gtk2=	${PREFIX}
GTK2_IMMODULES=		YES
GTK2_LOADERS=		YES
.endif

.if defined(GTK2_IMMODULES) && !empty(GTK2_IMMODULES:M[Yy][Ee][Ss])
FILES_SUBST+=		GTK_IMMODULES_DB=${GTK_IMMODULES_DB:Q}
FILES_SUBST+=		GTK_QUERY_IMMODULES=${GTK_QUERY_IMMODULES:Q}
GTK_IMMODULES_DB=	${BUILDLINK_PREFIX.gtk2}/libdata/gtk-2.0/gtk.immodules
INSTALL_TEMPLATES+=	../../x11/gtk2/files/immodules.tmpl
DEINSTALL_TEMPLATES+=	../../x11/gtk2/files/immodules.tmpl
.endif

.if defined(GTK2_LOADERS) && !empty(GTK2_LOADERS:M[Yy][Ee][Ss])
FILES_SUBST+=		GDK_PIXBUF_LOADERS_DB=${GDK_PIXBUF_LOADERS_DB:Q}
FILES_SUBST+=		GDK_PIXBUF_QUERY_LOADERS=${GDK_PIXBUF_QUERY_LOADERS:Q}
GDK_PIXBUF_LOADERS_DB=	${BUILDLINK_PREFIX.gtk2}/libdata/gtk-2.0/gdk-pixbuf.loaders
INSTALL_TEMPLATES+=	../../x11/gtk2/files/loaders.tmpl
DEINSTALL_TEMPLATES+=	../../x11/gtk2/files/loaders.tmpl
.endif

PRINT_PLIST_AWK+=	/^libdata\/gtk-2.0/ { next; }

.if !defined(_BUILDING_GTK2)
.  include "../../x11/gtk2/buildlink3.mk"
.endif

.endif			# GTK2_MODULES_MK
