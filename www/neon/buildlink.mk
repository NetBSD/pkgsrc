# $NetBSD: buildlink.mk,v 1.2 2002/04/01 01:28:04 uebayasi Exp $
#
# This Makefile fragment is included by packages that use neon.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.neon to the dependency patthern
#     for the version of neon desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(NEON_BUILDLINK_MK)
NEON_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.neon?=	neon>=0.19.3
DEPENDS+=			${BUILDLINK_DEPENDS.neon}:../../www/neon

EVAL_PREFIX+=			BUILDLINK_PREFIX.neon=neon
BUILDLINK_PREFIX.neon_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.neon=		include/neon/*
BUILDLINK_FILES.neon+=		lib/libneon.*

.include "../../devel/zlib/buildlink.mk"
.include "../../security/openssl/buildlink.mk"
.include "../../textproc/libxml/buildlink.mk"

BUILDLINK_TARGETS.neon=		neon-buildlink
BUILDLINK_TARGETS.neon+=	neon-buildlink-config-wrapper
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.neon}

BUILDLINK_CONFIG.neon=		${BUILDLINK_PREFIX.neon}/bin/neon-config
BUILDLINK_CONFIG_WRAPPER.neon=${BUILDLINK_DIR}/bin/neon-config
REPLACE_BUILDLINK_SED+=	\
	-e "s|${BUILDLINK_CONFIG_WRAPPER.neon}|${BUILDLINK_CONFIG.neon}|g"

.if defined(USE_CONFIG_WRAPPER)
NEON_CONFIG?=		${BUILDLINK_CONFIG_WRAPPER.neon}
CONFIGURE_ENV+=		NEON_CONFIG="${NEON_CONFIG}"
MAKE_ENV+=		NEON_CONFIG="${NEON_CONFIG}"
.endif

pre-configure: ${BUILDLINK_TARGETS.neon}
neon-buildlink: _BUILDLINK_USE
neon-buildlink-config-wrapper: _BUILDLINK_CONFIG_WRAPPER_USE

.endif	# NEON_BUILDLINK_MK
