# $NetBSD: buildlink.mk,v 1.12 2002/04/10 22:46:53 jlam Exp $
#
# This Makefile fragment is included by packages that use gtk.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.gtk to the dependency pattern
#     for the version of gtk desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(GTK_BUILDLINK_MK)
GTK_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.gtk?=	gtk+>=1.2.8
DEPENDS+=		${BUILDLINK_DEPENDS.gtk}:../../x11/gtk

EVAL_PREFIX+=		BUILDLINK_PREFIX.gtk=gtk
BUILDLINK_PREFIX.gtk_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.gtk=	include/gdk/*
BUILDLINK_FILES.gtk+=	include/gtk/*
BUILDLINK_FILES.gtk+=	include/gtk-*/*/*
BUILDLINK_FILES.gtk+=	lib/libgdk.*
BUILDLINK_FILES.gtk+=	lib/libgtk.*

REPLACE_BUILDLINK_SED+=	\
	-e "s|-I${BUILDLINK_DIR}/\(include/gtk-[^ 	/]*\)|-I${BUILDLINK_PREFIX.gtk}/\1|g"
BUILDLINK_CONFIG_WRAPPER_SED+=	\
	-e "s|-I${BUILDLINK_PREFIX.gtk}/\(include/gtk-[^ 	/]*\)|-I${BUILDLINK_DIR}/\1|g"

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../devel/glib/buildlink.mk"

BUILDLINK_TARGETS.gtk=	gtk-buildlink
BUILDLINK_TARGETS.gtk+=	gtk-buildlink-config-wrapper
BUILDLINK_TARGETS+=	${BUILDLINK_TARGETS.gtk}

BUILDLINK_CONFIG.gtk=		${BUILDLINK_PREFIX.gtk}/bin/gtk-config
BUILDLINK_CONFIG_WRAPPER.gtk=	${BUILDLINK_DIR}/bin/gtk-config
REPLACE_BUILDLINK_SED+=	\
	-e "s|${BUILDLINK_CONFIG_WRAPPER.gtk}|${BUILDLINK_CONFIG.gtk}|g"

.if defined(USE_CONFIG_WRAPPER)
GTK_CONFIG?=		${BUILDLINK_CONFIG_WRAPPER.gtk}
CONFIGURE_ENV+=		GTK_CONFIG="${GTK_CONFIG}"
MAKE_ENV+=		GTK_CONFIG="${GTK_CONFIG}"
.endif

pre-configure: ${BUILDLINK_TARGETS.gtk}
gtk-buildlink: _BUILDLINK_USE
gtk-buildlink-config-wrapper: _BUILDLINK_CONFIG_WRAPPER_USE

.endif	# GTK_BUILDLINK_MK
