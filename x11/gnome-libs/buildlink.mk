# $NetBSD: buildlink.mk,v 1.17 2002/07/14 01:19:15 rh Exp $
#
# This Makefile fragment is included by packages that use gnome-libs.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.gnome-libs to the dependency pattern
#     for the version of gnome-libs desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(GNOME_LIBS_BUILDLINK_MK)
GNOME_LIBS_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.gnome-libs?=	gnome-libs>=1.4.1.4
DEPENDS+=	${BUILDLINK_DEPENDS.gnome-libs}:../../x11/gnome-libs

EVAL_PREFIX+=			BUILDLINK_PREFIX.gnome-libs=gnome-libs
BUILDLINK_PREFIX.gnome-libs_DEFAULTS=	${X11PREFIX}
BUILDLINK_FILES.gnome-libs=	include/gnome-1.0/gnome.h
BUILDLINK_FILES.gnome-libs+=	include/gnome-1.0/gtk-xmhtml/*
BUILDLINK_FILES.gnome-libs+=	include/gnome-1.0/libart_lgpl/*
BUILDLINK_FILES.gnome-libs+=	include/gnome-1.0/libgnome/*
BUILDLINK_FILES.gnome-libs+=	include/gnome-1.0/libgnomeui/*
BUILDLINK_FILES.gnome-libs+=	include/gnome-1.0/libgnorba/*
BUILDLINK_FILES.gnome-libs+=	include/gnome-1.0/popt-gnome.h
BUILDLINK_FILES.gnome-libs+=	include/gnome-1.0/zvt/*
BUILDLINK_FILES.gnome-libs+=	lib/gnome-libs/*/*
BUILDLINK_FILES.gnome-libs+=	lib/libart_lgpl.*
BUILDLINK_FILES.gnome-libs+=	lib/libgnome.*
BUILDLINK_FILES.gnome-libs+=	lib/libgnomesupport.*
BUILDLINK_FILES.gnome-libs+=	lib/libgnomeui.*
BUILDLINK_FILES.gnome-libs+=	lib/libgnorba.*
BUILDLINK_FILES.gnome-libs+=	lib/libgnorbagtk.*
BUILDLINK_FILES.gnome-libs+=	lib/libgtkxmhtml.*
BUILDLINK_FILES.gnome-libs+=	lib/libzvt.*
BUILDLINK_FILES.gnome-libs+=	share/idl/GnomeObject.idl
BUILDLINK_FILES.gnome-libs+=	share/idl/Table.idl
BUILDLINK_FILES.gnome-libs+=	share/idl/desktop-editor.idl
BUILDLINK_FILES.gnome-libs+=	share/idl/desktop-textviewer.idl
BUILDLINK_FILES.gnome-libs+=	share/idl/gnome-factory.idl
BUILDLINK_FILES.gnome-libs+=	share/idl/gnome-unknown.idl
BUILDLINK_FILES.gnome-libs+=	share/idl/name-service.idl

REPLACE_BUILDLINK_SED+=	\
	-e "s|-I${BUILDLINK_DIR}/\(lib/gnome-libs/\)|-I${BUILDLINK_PREFIX.gnome-libs}/\1|g" \
	-e "s|-I${BUILDLINK_DIR}/\(include/gnome-1.0\)|-I${BUILDLINK_PREFIX.gnome-libs}/\1|g" \
	-e "s|-I${BUILDLINK_DIR}/\(share/idl\)|-I${BUILDLINK_PREFIX.gnome-libs}/\1|g"
BUILDLINK_CONFIG_WRAPPER_SED+=	\
	-e "s|-I${BUILDLINK_PREFIX.gnome-libs}/\(lib/gnome-libs/\)|-I${BUILDLINK_DIR}/\1|g" \
	-e "s|-I${BUILDLINK_PREFIX.gnome-libs}/\(include/gnome-1.0\)|-I${BUILDLINK_DIR}/\1|g" \
	-e "s|-I${BUILDLINK_PREFIX.gnome-libs}/\(share/idl\)|-I${BUILDLINK_DIR}/\1|g"

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

BUILDLINK_CONFIG.gnome-libs=		${BUILDLINK_PREFIX.gnome-libs}/bin/gnome-config
BUILDLINK_CONFIG_WRAPPER.gnome-libs=	${BUILDLINK_DIR}/bin/gnome-config
REPLACE_BUILDLINK_SED+=	\
	-e "s|${BUILDLINK_CONFIG_WRAPPER.gnome-libs}|${BUILDLINK_CONFIG.gnome-libs}|g"

BUILDLINK_CONFIG.libart=		${BUILDLINK_PREFIX.gnome-libs}/bin/libart-config
BUILDLINK_CONFIG_WRAPPER.libart=	${BUILDLINK_DIR}/bin/libart-config
REPLACE_BUILDLINK_SED+=	\
	-e "s|${BUILDLINK_CONFIG_WRAPPER.libart}|${BUILDLINK_CONFIG.libart}|g"

.if defined(USE_CONFIG_WRAPPER)
GNOME_CONFIG?=		${BUILDLINK_CONFIG_WRAPPER.gnome-libs}
ART_CONFIG?=		${BUILDLINK_CONFIG_WRAPPER.libart}
CONFIGURE_ENV+=		GNOME_CONFIG="${GNOME_CONFIG}"
CONFIGURE_ENV+=		ART_CONFIG="${ART_CONFIG}"
MAKE_ENV+=		GNOME_CONFIG="${GNOME_CONFIG}"
MAKE_ENV+=		ART_CONFIG="${ART_CONFIG}"
.endif

pre-configure: ${BUILDLINK_TARGETS.gnome-libs}
gnome-libs-buildlink: _BUILDLINK_USE
gnome-libs-buildlink-config-wrapper: _BUILDLINK_CONFIG_WRAPPER_USE
libart-buildlink-config-wrapper: _BUILDLINK_CONFIG_WRAPPER_USE

.endif	# GNOME_LIBS_BUILDLINK_MK
