# $NetBSD: buildlink.mk,v 1.5 2002/07/14 01:21:18 rh Exp $
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

BUILDLINK_DEPENDS.gnome-core?=	gnome-core>=1.4.0.4nb1
DEPENDS+=	${BUILDLINK_DEPENDS.gnome-core}:../../x11/gnome-core

EVAL_PREFIX+=			BUILDLINK_PREFIX.gnome-core=gnome-core
BUILDLINK_PREFIX.gnome-core_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.gnome-core=	include/applet-widget.h
BUILDLINK_FILES.gnome-core+=	include/gnome-panel.h
BUILDLINK_FILES.gnome-core+=	include/status-docklet.h
BUILDLINK_FILES.gnome-core+=	lib/libfish_applet.*
BUILDLINK_FILES.gnome-core+=	lib/libgen_util_applet.*
BUILDLINK_FILES.gnome-core+=	lib/libpanel_applet.*
BUILDLINK_FILES.gnome-core+=	lib/libpanel_status.*
BUILDLINK_FILES.gnome-core+=	share/idl/Terminal.idl
BUILDLINK_FILES.gnome-core+=	share/idl/gnome-panel.idl
BUILDLINK_FILES.gnome-core+=	share/idl/help-browser.idl

.include "../../graphics/gdk-pixbuf-gnome/buildlink.mk"
.include "../../www/libghttp/buildlink.mk"
.include "../../textproc/libxml/buildlink.mk"
.include "../../devel/libglade/buildlink.mk"
.include "../../www/gtkhtml/buildlink.mk"
.include "../../devel/gettext-lib/buildlink.mk"

BUILDLINK_TARGETS.gnome-core=	gnome-core-buildlink
BUILDLINK_TARGETS.gnome-core+=	docklets-buildlink-config-wrapper
BUILDLINK_TARGETS.gnome-core+=	applets-buildlink-config-wrapper
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.gnome-core}

BUILDLINK_CONFIG.docklets=		${BUILDLINK_PREFIX.gnome-core}/lib/dockletsConf.sh
BUILDLINK_CONFIG_WRAPPER.docklets=	${BUILDLINK_DIR}/lib/dockletsConf.sh

BUILDLINK_CONFIG.applets=		${BUILDLINK_PREFIX.gnome-core}/lib/appletsConf.sh
BUILDLINK_CONFIG_WRAPPER.applets=	${BUILDLINK_DIR}/lib/appletsConf.sh

.if defined(USE_CONFIG_WRAPPER)
DOCKLETS_CONFIG?=	${BUILDLINK_CONFIG_WRAPPER.gnome-core}
APPLETS_CONFIG?=	${BUILDLINK_CONFIG_WRAPPER.applets}
CONFIGURE_ENV+=		DOCKLETS_CONFIG="${DOCKLETS_CONFIG}"
CONFIGURE_ENV+=		APPLETS_CONFIG="${APPLETS_CONFIG}"
MAKE_ENV+=		DOCKLETS_CONFIG="${DOCKLETS_CONFIG}"
MAKE_ENV+=		APPLETS_CONFIG="${APPLETS_CONFIG}"
.endif

pre-configure: ${BUILDLINK_TARGETS.gnome-core}
gnome-core-buildlink: _BUILDLINK_USE
docklets-buildlink-config-wrapper: _BUILDLINK_CONFIG_WRAPPER_USE
applets-buildlink-config-wrapper: _BUILDLINK_CONFIG_WRAPPER_USE

.endif	# GNOME_CORE_BUILDLINK_MK
