# $NetBSD: buildlink.mk,v 1.1 2002/01/09 14:46:51 drochner Exp $
#
# This Makefile fragment is included by packages that use gtk.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.gtkextra to the dependency pattern
#     for the version of gtk+extra desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(GTKEXTRA_BUILDLINK_MK)
GTKEXTRA_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.gtkextra?=	gtk+extra>=0.99.17
DEPENDS+=		${BUILDLINK_DEPENDS.gtkextra}:../../x11/gtk+extra

EVAL_PREFIX+=		BUILDLINK_PREFIX.gtkextra=gtk+extra
BUILDLINK_PREFIX.gtkextra_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.gtkextra=	include/gtkextra/*
BUILDLINK_FILES.gtkextra+=	lib/libgtkextra.*

#REPLACE_BUILDLINK_SED+=	\
#	-e "s|-I${BUILDLINK_DIR}/\(include/gtk-[^/]*/\)|-I${BUILDLINK_PREFIX.gtk}/\1|g"
#BUILDLINK_CONFIG_WRAPPER_SED+=	\
#	-e "s|-I${BUILDLINK_PREFIX.gtk}/\(include/gtk-[^/]*/\)|-I${BUILDLINK_DIR}/\1|g"

.include "../../x11/gtk/buildlink.mk"

BUILDLINK_TARGETS.gtkextra=	gtkextra-buildlink
BUILDLINK_TARGETS.gtkextra+=	gtkextra-buildlink-config-wrapper
BUILDLINK_TARGETS+=	${BUILDLINK_TARGETS.gtkextra}

BUILDLINK_CONFIG.gtkextra=	${BUILDLINK_PREFIX.gtkextra}/bin/gtkextra-config
BUILDLINK_CONFIG_WRAPPER.gtkextra=	${BUILDLINK_DIR}/bin/gtkextra-config
#REPLACE_BUILDLINK_SED+=	\
#	-e "s|${BUILDLINK_CONFIG_WRAPPER.gtkextra}|${BUILDLINK_CONFIG.gtkextra}|g"

.if defined(USE_CONFIG_WRAPPER)
GTKEXTRA_CONFIG?=	${BUILDLINK_CONFIG_WRAPPER.gtkextra}
CONFIGURE_ENV+=		GTK_EXTRA_CONFIG="${GTKEXTRA_CONFIG}"
#MAKE_ENV+=		GTK_EXTRA_CONFIG="${GTKEXTRA_CONFIG}"
.endif

pre-configure: ${BUILDLINK_TARGETS.gtkextra}
gtkextra-buildlink: _BUILDLINK_USE
gtkextra-buildlink-config-wrapper: _BUILDLINK_CONFIG_WRAPPER_USE

.endif	# GTKEXTRA_BUILDLINK_MK
