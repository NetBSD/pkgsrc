# $NetBSD: buildlink.mk,v 1.9 2002/07/15 14:39:21 fredb Exp $
#
# This Makefile fragment is included by packages that use libwww.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.libwww to the dependency pattern
#     for the version of libwww desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(LIBWWW_BUILDLINK_MK)
LIBWWW_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.libwww?=	libwww>=5.3.2nb2
DEPENDS+=	${BUILDLINK_DEPENDS.libwww}:../../www/libwww

EVAL_PREFIX+=			BUILDLINK_PREFIX.libwww=libwww
BUILDLINK_PREFIX.libwww_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libwww=		include/wwwconf.h
BUILDLINK_FILES.libwww+=	include/w3c-libwww/*
BUILDLINK_FILES.libwww+=	lib/libmd5.*
BUILDLINK_FILES.libwww+=	lib/libpics.*
BUILDLINK_FILES.libwww+=	lib/libwwwapp.*
BUILDLINK_FILES.libwww+=	lib/libwwwcache.*
BUILDLINK_FILES.libwww+=	lib/libwwwcore.*
BUILDLINK_FILES.libwww+=	lib/libwwwdir.*
BUILDLINK_FILES.libwww+=	lib/libwwwfile.*
BUILDLINK_FILES.libwww+=	lib/libwwwftp.*
BUILDLINK_FILES.libwww+=	lib/libwwwgopher.*
BUILDLINK_FILES.libwww+=	lib/libwwwhttp.*
BUILDLINK_FILES.libwww+=	lib/libwwwhtml.*
BUILDLINK_FILES.libwww+=	lib/libwwwinit.*
BUILDLINK_FILES.libwww+=	lib/libwwwmime.*
BUILDLINK_FILES.libwww+=	lib/libwwwmux.*
BUILDLINK_FILES.libwww+=	lib/libwwwnews.*
BUILDLINK_FILES.libwww+=	lib/libwwwssl.*
BUILDLINK_FILES.libwww+=	lib/libwwwstream.*
BUILDLINK_FILES.libwww+=	lib/libwwwtelnet.*
BUILDLINK_FILES.libwww+=	lib/libwwwtrans.*
BUILDLINK_FILES.libwww+=	lib/libwwwutils.*
BUILDLINK_FILES.libwww+=	lib/libwwwxml.*
BUILDLINK_FILES.libwww+=	lib/libwwwzip.*
BUILDLINK_FILES.libwww+=	lib/libxmlparse.*
BUILDLINK_FILES.libwww+=	lib/libxmltok.*

.include "../../devel/zlib/buildlink.mk"

BUILDLINK_TARGETS.libwww=	libwww-buildlink
BUILDLINK_TARGETS.libwww+=	libwww-buildlink-config-wrapper
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.libwww}

BUILDLINK_CONFIG.libwww=	${BUILDLINK_PREFIX.libwww}/bin/libwww-config
BUILDLINK_CONFIG_WRAPPER.libwww=${BUILDLINK_DIR}/bin/libwww-config
REPLACE_BUILDLINK_SED+=	\
	-e "s|${BUILDLINK_CONFIG_WRAPPER.libwww}|${BUILDLINK_CONFIG.libwww}|g"

.if defined(USE_CONFIG_WRAPPER)
LIBWWW_CONFIG?=		${BUILDLINK_CONFIG_WRAPPER.libwww}
CONFIGURE_ENV+=		LIBWWW_CONFIG="${LIBWWW_CONFIG}"
MAKE_ENV+=		LIBWWW_CONFIG="${LIBWWW_CONFIG}"
.endif

pre-configure: ${BUILDLINK_TARGETS.libwww}
libwww-buildlink: _BUILDLINK_USE
libwww-buildlink-config-wrapper: _BUILDLINK_CONFIG_WRAPPER_USE

.endif	# LIBWWW_BUILDLINK_MK
