# $NetBSD: buildlink.mk,v 1.1 2001/06/16 19:23:20 jlam Exp $
#
# This Makefile fragment is included by packages that use gnome-libs.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define GNOME_LIBS_REQD to the version of gnome-libs desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(GNOME_LIBS_BUILDLINK_MK)
GNOME_LIBS_BUILDLINK_MK=	# defined

GNOME_LIBS_REQD?=	1.0.53
DEPENDS+=		gnome-libs>=${GNOME_LIBS_REQD}:../../x11/gnome-libs

BUILDLINK_PREFIX.gnome-libs=	${X11PREFIX}
BUILDLINK_FILES.gnome-libs=	include/gnome.h
BUILDLINK_FILES.gnome-libs+=	include/gtk-xmhtml/*
BUILDLINK_FILES.gnome-libs+=	include/libart_lgpl/*
BUILDLINK_FILES.gnome-libs+=	include/libgnome/*
BUILDLINK_FILES.gnome-libs+=	include/libgnomeui/*
BUILDLINK_FILES.gnome-libs+=	include/libgnorba/*
BUILDLINK_FILES.gnome-libs+=	include/popt-gnome.h
BUILDLINK_FILES.gnome-libs+=	include/zvt/*
BUILDLINK_FILES.gnome-libs+=	lib/gnome-libs/*/*
BUILDLINK_FILES.gnome-libs+=	lib/libart_lgpl.*
BUILDLINK_FILES.gnome-libs+=	lib/libgnome.*
BUILDLINK_FILES.gnome-libs+=	lib/libgnomesupport.*
BUILDLINK_FILES.gnome-libs+=	lib/libgnomeui.*
BUILDLINK_FILES.gnome-libs+=	lib/libgnorba.*
BUILDLINK_FILES.gnome-libs+=	lib/libgnorbagtk.*
BUILDLINK_FILES.gnome-libs+=	lib/libgtkxmhtml.*
BUILDLINK_FILES.gnome-libs+=	lib/libzvt.*

.include "../../audio/esound/buildlink.mk"
.include "../../devel/gettext-lib/buildlink.mk"
.include "../../graphics/imlib/buildlink.mk"
.include "../../graphics/xpm/buildlink.mk"
.include "../../net/ORBit/buildlink.mk"
.include "../../x11/gtk/buildlink.mk"

BUILDLINK_TARGETS.gnome-libs=	gnome-libs-buildlink
BUILDLINK_TARGETS.gnome-libs+=	gnome-libs-buildlink-config-wrapper
BUILDLINK_TARGETS.gnome-libs+=	libart-buildlink-config-wrapper
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.gnome-libs}

BUILDLINK_CONFIG.gnome-libs=		${LOCALBASE}/bin/gnome-config
BUILDLINK_CONFIG_WRAPPER.gnome-libs=	${BUILDLINK_DIR}/bin/gnome-config
BUILDLINK_CONFIG_WRAPPER.libart=	${BUILDLINK_DIR}/bin/libart-config

.if defined(USE_CONFIG_WRAPPER) && defined(GNU_CONFIGURE)
CONFIGURE_ENV+=		GNOME_CONFIG="${BUILDLINK_CONFIG_WRAPPER.gnome-libs}"
CONFIGURE_ENV+=		LIBART_CONFIG="${BUILDLINK_CONFIG_WRAPPER.libart}"
.endif

pre-configure: ${BUILDLINK_TARGETS.gnome-libs}
gnome-libs-buildlink: _BUILDLINK_USE
gnome-libs-buildlink-config-wrapper: _BUILDLINK_CONFIG_WRAPPER_USE
libart-buildlink-config-wrapper: _BUILDLINK_CONFIG_WRAPPER_USE

.include "../../mk/bsd.buildlink.mk"

.endif	# GNOME_LIBS_BUILDLINK_MK
