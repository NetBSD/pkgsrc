# $NetBSD: buildlink.mk,v 1.1 2001/10/06 14:30:05 rh Exp $
#
# This Makefile fragment is included by packages that use glibwww.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.glibwww to the dependency pattern
#     for the version of glibwww desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(GLIBWWW_BUILDLINK_MK)
GLIBWWW_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.glibwww?=	glibwww>=0.2
DEPENDS+=			${BUILDLINK_DEPENDS.glibwww}:../../www/glibwww

EVAL_PREFIX+=			BUILDLINK_PREFIX.glibwww=glibwww
BUILDLINK_PREFIX.glibwww_DEFAULTS=	${X11PREFIX}
BUILDLINK_FILES.glibwww=	include/glibwww/glibwww.h
BUILDLINK_FILES.glibwww+=	lib/libglibwww.*

.include "../../www/libwww/buildlink.mk"
.include "../../x11/gnome-libs/buildlink.mk"

BUILDLINK_TARGETS.glibwww=	glibwww-buildlink
BUILDLINK_TARGETS.glibwww+=	glibwww-buildlink-config-wrapper
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.glibwww}

BUILDLINK_CONFIG.glibwww=	${BUILDLINK_PREFIX.glibwww}/bin/glibwww-config
BUILDLINK_CONFIG_WRAPPER.glibwww=	${BUILDLINK_DIR}/bin/glibwww-config

.if defined(USE_CONFIG_WRAPPER)
GLIBWWW_CONFIG?=		${BUILDLINK_CONFIG_WRAPPER.glibwww}
CONFIGURE_ENV+=			GLIBWWW_CONFIG="${GLIBWWW_CONFIG}"
MAKE_ENV+=			GLIBWWW_CONFIG="${GLIBWWW_CONFIG}"
.endif

pre-configure: ${BUILDLINK_TARGETS.glibwww}
glibwww-buildlink: _BUILDLINK_USE
glibwww-buildlink-config-wrapper: _BUILDLINK_CONFIG_WRAPPER_USE

.endif	# GLIBWWW_BUILDLINK_MK
