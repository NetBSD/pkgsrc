# $NetBSD: buildlink.mk,v 1.3 2002/09/11 22:36:52 wiz Exp $
#
# This Makefile fragment is included by packages that use gnome--.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.gnome-- to the dependency
#     pattern for the version of gnome-- desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(GNOMEMM_BUILDLINK_MK)
GNOMEMM_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.gnomemm?=	gnome-->=1.2.2
DEPENDS+=	${BUILDLINK_DEPENDS.gnomemm}:../../x11/gnome--

EVAL_PREFIX+=				BUILDLINK_PREFIX.gnomemm=gnome--
BUILDLINK_PREFIX.gnomemm_DEFAULTS=	${X11PREFIX}
BUILDLINK_FILES.gnomemm=		include/gnome--/private/*
BUILDLINK_FILES.gnomemm+=		include/gnome--/*
BUILDLINK_FILES.gnomemm+=		include/gnome--.h
BUILDLINK_FILES.gnomemm+=		lib/libgnomemm-1.1.*
BUILDLINK_FILES.gnomemm+=		lib/libgnomemm.*

.include "../../devel/libsigc++/buildlink.mk"
.include "../../x11/gnome-libs/buildlink.mk"
.include "../../x11/gtk--/buildlink.mk"

BUILDLINK_TARGETS.gnomemm=	gnomemm-buildlink
BUILDLINK_TARGETS.gnomemm+=	gnomemm-buildlink-config-wrapper
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.gnomemm}

BUILDLINK_CONFIG.gnomemm=	${BUILDLINK_PREFIX.gnomemm}/lib/gnomemmConf.sh
BUILDLINK_CONFIG_WRAPPER.gnomemm=	${BUILDLINK_DIR}/lib/gnomemmConf.sh

.if defined(USE_CONFIG_WRAPPER)
GNOMEMM_CONFIG?=		${BUILDLINK_CONFIG_WRAPPER.gnomemm}
CONFIGURE_ENV+=			GNOMEMM_CONFIG="${GNOMEMM_CONFIG}"
MAKE_ENV+=			GNOMEMM_CONFIG="${GNOMEMM_CONFIG}"
.endif

pre-configure: ${BUILDLINK_TARGETS.gnomemm}
gnomemm-buildlink: _BUILDLINK_USE
gnomemm-buildlink-config-wrapper: _BUILDLINK_CONFIG_WRAPPER_USE

.endif	# GNOMEMM_BUILDLINK_MK
