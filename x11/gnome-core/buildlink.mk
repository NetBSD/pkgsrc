# $NetBSD: buildlink.mk,v 1.1 2001/10/06 14:47:35 rh Exp $
#
# This Makefile fragment is included by packages that use gnome-core.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.gnome-core to the dependency pattern
#     for the version of gnome-core desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(GNOME_CORE_BUILDLINK_MK)
GNOME_CORE_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.gnome-core?=	gnome-core>=0.2
DEPENDS+=			${BUILDLINK_DEPENDS.gnome-core}:../../x11/gnome-core

EVAL_PREFIX+=			BUILDLINK_PREFIX.gnome-core=gnome-core
BUILDLINK_PREFIX.gnome-core_DEFAULTS=	${X11PREFIX}
BUILDLINK_FILES.gnome-core=	include/gnome-core/*
BUILDLINK_FILES.gnome-core+=	lib/libgnome-core.*

.include "../../devel/bonobo/buildlink.mk"
.include "../../devel/gal/buildlink.mk"
.include "../../print/gnome-print/buildlink.mk"
.include "../../www/glibwww/buildlink.mk"
.include "../../www/libghttp/buildlink.mk"
.include "../../x11/controlcenter/buildlink.mk"

BUILDLINK_TARGETS.gnome-core=	gnome-core-buildlink
BUILDLINK_TARGETS.gnome-core+=	gnome-core-buildlink-config-wrapper
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.gnome-core}

BUILDLINK_CONFIG.applets=	${BUILDLINK_PREFIX.gnome-core}/lib/appletsConf.sh
BUILDLINK_CONFIG.docklets=	${BUILDLINK_PREFIX.gnome-core}/lib/dockletsConf.sh
BUILDLINK_CONFIG_WRAPPER.applets=	${BUILDLINK_DIR}/lib/appletsConf.sh
BUILDLINK_CONFIG_WRAPPER.docklets=	${BUILDLINK_DIR}/lib/dockletsConf.sh

.if defined(USE_CONFIG_WRAPPER)
APPLETS_CONFIG?=		${BUILDLINK_CONFIG_WRAPPER.applets}
DOCKLETS_CONFIG?=		${BUILDLINK_CONFIG_WRAPPER.docklets}
CONFIGURE_ENV+=			APPLETS_CONFIG="${APPLETS_CONFIG}"
CONFIGURE_ENV+=			DOCKLETS_CONFIG="${DOCKLETS_CONFIG}"
MAKE_ENV+=			APPLETS_CONFIG="${APPLETS_CONFIG}"
MAKE_ENV+=			DOCKLETS_CONFIG="${DOCKLETS_CONFIG}"
.endif

pre-configure: ${BUILDLINK_TARGETS.gnome-core}
gnome-core-buildlink: _BUILDLINK_USE
gnome-core-buildlink-config-wrapper: _BUILDLINK_CONFIG_WRAPPER_USE

.endif	# GNOME_CORE_BUILDLINK_MK

appletsConf.sh dockletsConf.sh
