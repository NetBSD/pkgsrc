# $NetBSD: buildlink.mk,v 1.1 2001/06/16 19:23:20 jlam Exp $
#
# This Makefile fragment is included by packages that use gtk.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define GTK_REQD to the version of gtk desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(GTK_BUILDLINK_MK)
GTK_BUILDLINK_MK=	# defined

GTK_REQD?=		1.2.8
DEPENDS+=		gtk+>=${GTK_REQD}:../../x11/gtk

BUILDLINK_PREFIX.gtk=	${X11PREFIX}
BUILDLINK_FILES.gtk=	include/gtk-*/*/*
BUILDLINK_FILES.gtk+=	lib/libgdk.*
BUILDLINK_FILES.gtk+=	lib/libgtk.*

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../devel/glib/buildlink.mk"

BUILDLINK_TARGETS.gtk=	gtk-buildlink
BUILDLINK_TARGETS.gtk+=	gtk-buildlink-config-wrapper
BUILDLINK_TARGETS+=	${BUILDLINK_TARGETS.gtk}

BUILDLINK_CONFIG.gtk=		${X11PREFIX}/bin/gtk-config
BUILDLINK_CONFIG_WRAPPER.gtk=	${BUILDLINK_DIR}/bin/gtk-config

.if defined(USE_CONFIG_WRAPPER) && defined(GNU_CONFIGURE)
CONFIGURE_ENV+=		GTK_CONFIG="${BUILDLINK_CONFIG_WRAPPER.gtk}"
.endif

pre-configure: ${BUILDLINK_TARGETS.gtk}
gtk-buildlink: _BUILDLINK_USE
gtk-buildlink-config-wrapper: _BUILDLINK_CONFIG_WRAPPER_USE

.include "../../mk/bsd.buildlink.mk"

.endif	# GTK_BUILDLINK_MK
