# $NetBSD: buildlink.mk,v 1.1 2002/07/16 11:55:39 agc Exp $
#
# This Makefile fragment is included by packages that use scrollkeeper.
#
# This file was created automatically using createbuildlink 1.5.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.scrollkeeper to the dependency pattern
#     for the version of scrollkeeper desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(SCROLLKEEPER_BUILDLINK_MK)
SCROLLKEEPER_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.scrollkeeper?=		scrollkeeper>=0.2
DEPENDS+=	${BUILDLINK_DEPENDS.scrollkeeper}:../../textproc/scrollkeeper

EVAL_PREFIX+=	BUILDLINK_PREFIX.scrollkeeper=scrollkeeper
BUILDLINK_PREFIX.scrollkeeper_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.scrollkeeper+=	lib/libscrollkeeper.*


BUILDLINK_TARGETS.scrollkeeper=	scrollkeeper-buildlink
BUILDLINK_TARGETS.scrollkeeper+=	scrollkeeper-scrollkeeper-buildlink-config-wrapper
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.scrollkeeper}

BUILDLINK_CONFIG.scrollkeeper-scrollkeeper=					\
	${BUILDLINK_PREFIX.scrollkeeper}/bin/scrollkeeper-config
BUILDLINK_CONFIG_WRAPPER.scrollkeeper-scrollkeeper=				\
	${BUILDLINK_DIR}/bin/scrollkeeper-config
REPLACE_BUILDLINK_SED+=							\
	-e "s|${BUILDLINK_CONFIG_WRAPPER.scrollkeeper-scrollkeeper}|${BUILDLINK_CONFIG.scrollkeeper-scrollkeeper}|g"


.if defined(USE_CONFIG_WRAPPER)
SCROLLKEEPER_SCROLLKEEPER_CONFIG?=	${BUILDLINK_CONFIG_WRAPPER.scrollkeeper-scrollkeeper}
CONFIGURE_ENV+=		SCROLLKEEPER_SCROLLKEEPER_CONFIG="${SCROLLKEEPER_SCROLLKEEPER_CONFIG}"
MAKE_ENV+=		SCROLLKEEPER_SCROLLKEEPER_CONFIG="${SCROLLKEEPER_SCROLLKEEPER_CONFIG}"
.endif

pre-configure: ${BUILDLINK_TARGETS}
scrollkeeper-buildlink: _BUILDLINK_USE
scrollkeeper-scrollkeeper-buildlink-config-wrapper: _BUILDLINK_CONFIG_WRAPPER_USE

.endif	# SCROLLKEEPER_BUILDLINK_MK
