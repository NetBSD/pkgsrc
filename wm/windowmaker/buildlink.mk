# $NetBSD: buildlink.mk,v 1.5 2001/07/27 13:33:35 jlam Exp $
#
# This Makefile fragment is included by packages that use windowmaker.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.windowmaker to the dependency pattern
#     for the version of windowmaker desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(WINDOWMAKER_BUILDLINK_MK)
WINDOWMAKER_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.windowmaker?=	windowmaker>=0.65.0
DEPENDS+=	${BUILDLINK_DEPENDS.windowmaker}:../../wm/windowmaker

EVAL_PREFIX+=			BUILDLINK_PREFIX.windowmaker=windowmaker
BUILDLINK_PREFIX.windowmaker_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.windowmaker=	include/WINGs/*
BUILDLINK_FILES.windowmaker+=	include/WMaker.h
BUILDLINK_FILES.windowmaker+=	include/wraster.h
BUILDLINK_FILES.windowmaker+=	lib/libExtraWINGs.a
BUILDLINK_FILES.windowmaker+=	lib/libWINGs.a
BUILDLINK_FILES.windowmaker+=	lib/libWMaker.a
BUILDLINK_FILES.windowmaker+=	lib/libWUtil.a
BUILDLINK_FILES.windowmaker+=	lib/libwraster.*

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../devel/libproplist/buildlink.mk"
.include "../../graphics/hermes/buildlink.mk"
.include "../../graphics/libungif/buildlink.mk"
.include "../../graphics/jpeg/buildlink.mk"
.include "../../graphics/png/buildlink.mk" 
.include "../../graphics/tiff/buildlink.mk"
.include "../../graphics/xpm/buildlink.mk" 

BUILDLINK_TARGETS.windowmaker=	windowmaker-buildlink
BUILDLINK_TARGETS.windowmaker+=	wm-wings-buildlink-config-wrapper
BUILDLINK_TARGETS.windowmaker+=	wm-wutil-buildlink-config-wrapper
BUILDLINK_TARGETS.windowmaker+=	wm-wraster-buildlink-config-wrapper
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.windowmaker}

BUILDLINK_CONFIG.wm-wings=		${BUILDLINK_PREFIX.windowmaker}/bin/get-wings-flags
BUILDLINK_CONFIG_WRAPPER.wm-wings=	${BUILDLINK_DIR}/bin/get-wings-flags

BUILDLINK_CONFIG.wm-wutil=		${BUILDLINK_PREFIX.windowmaker}/bin/get-wutil-flags
BUILDLINK_CONFIG_WRAPPER.wm-wutil=	${BUILDLINK_DIR}/bin/get-wutil-flags

BUILDLINK_CONFIG.wm-wraster=		${BUILDLINK_PREFIX.windowmaker}/bin/get-wraster-flags
BUILDLINK_CONFIG_WRAPPER.wm-wraster=	${BUILDLINK_DIR}/bin/get-wraster-flags

.if defined(USE_CONFIG_WRAPPER)
GET_WINGS_FLAGS?=	${BUILDLINK_CONFIG_WRAPPER.wm-wings}
GET_WUTIL_FLAGS?=	${BUILDLINK_CONFIG_WRAPPER.wm-wutil}
GET_WRASTER_FLAGS?=	${BUILDLINK_CONFIG_WRAPPER.wm-wraster}
CONFIGURE_ENV+=		GET_WINGS_FLAGS="${GET_WINGS_FLAGS}"
MAKE_ENV+=		GET_WINGS_FLAGS="${GET_WINGS_FLAGS}"
CONFIGURE_ENV+=		GET_WUTIL_FLAGS="${GET_WUTIL_FLAGS}"
MAKE_ENV+=		GET_WUTIL_FLAGS="${GET_WUTIL_FLAGS}"
CONFIGURE_ENV+=		GET_WRASTER_FLAGS="${GET_WRASTER_FLAGS}"
MAKE_ENV+=		GET_WRASTER_FLAGS="${GET_WRASTER_FLAGS}"
.endif

pre-configure: ${BUILDLINK_TARGETS.windowmaker}
windowmaker-buildlink: _BUILDLINK_USE
wm-wings-buildlink-config-wrapper: _BUILDLINK_CONFIG_WRAPPER_USE
wm-wutil-buildlink-config-wrapper: _BUILDLINK_CONFIG_WRAPPER_USE
wm-wraster-buildlink-config-wrapper: _BUILDLINK_CONFIG_WRAPPER_USE

.endif	# WINDOWMAKER_BUILDLINK_MK
