# $NetBSD: buildlink.mk,v 1.5 2002/03/24 13:07:50 tron Exp $
#
# This Makefile fragment is included by packages that use controlcenter.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.controlcenter to the dependency
#     pattern for the version of controlcenter desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(CONTROLCENTER_BUILDLINK_MK)
CONTROLCENTER_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.controlcenter?=	control-center>=1.4.0.4
DEPENDS+=	${BUILDLINK_DEPENDS.controlcenter}:../../x11/controlcenter

EVAL_PREFIX+=			BUILDLINK_PREFIX.controlcenter=controlcenter
BUILDLINK_PREFIX.controlcenter_DEFAULTS=	${X11PREFIX}
BUILDLINK_FILES.controlcenter=	include/libcapplet1/*
BUILDLINK_FILES.controlcenter+=	lib/libcapplet.*

BUILDLINK_TRANSFORM.controlcenter= \
	-e "s|/include/libcapplet1/|/include/|g
REPLACE_BUILDLINK_SED+= \
	-e "s|-I${BUILDLINK_DIR}/\(include/libcapplet1/\)|-I${BUILDLINK_PREFIX.controlcenter}/\1|g"
BUILDLINK_CONFIG_WRAPPER_SED+=  \
	-e "s|-I${BUILDLINK_PREFIX.controlcenter}/\(include/libcapplet1\)|-I${BUILDLINK_DIR}/\1|g"

.include "../../graphics/gdk-pixbuf/buildlink.mk"
.include "../../devel/gettext-lib/buildlink.mk"
.include "../../sysutils/gnome-vfs/buildlink.mk"
.include "../../x11/gnome-libs/buildlink.mk"

BUILDLINK_TARGETS.controlcenter=	controlcenter-buildlink
BUILDLINK_TARGETS.controlcenter+=	controlcenter-buildlink-config-wrapper
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.controlcenter}

BUILDLINK_CONFIG.controlcenter=	${BUILDLINK_PREFIX.controlcenter}/lib/cappletConf.sh
BUILDLINK_CONFIG_WRAPPER.controlcenter=	${BUILDLINK_DIR}/lib/cappletConf.sh

.if defined(USE_CONFIG_WRAPPER)
CONTROLCENTER_CONFIG?=		${BUILDLINK_CONFIG_WRAPPER.controlcenter}
CONFIGURE_ENV+=			CONTROLCENTER_CONFIG="${CONTROLCENTER_CONFIG}"
MAKE_ENV+=			CONTROLCENTER_CONFIG="${CONTROLCENTER_CONFIG}"
.endif

pre-configure: ${BUILDLINK_TARGETS.controlcenter}
controlcenter-buildlink: _BUILDLINK_USE
controlcenter-buildlink-config-wrapper: _BUILDLINK_CONFIG_WRAPPER_USE

.endif	# CONTROLCENTER_BUILDLINK_MK
