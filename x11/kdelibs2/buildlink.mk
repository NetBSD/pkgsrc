# $NetBSD: buildlink.mk,v 1.18 2001/12/20 12:09:50 tron Exp $
#
# This Makefile fragment is included by packages that use kdelibs2.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.kdelibs2 to the dependency pattern
#     for the version of kdelibs2 desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(KDELIBS2_BUILDLINK_MK)
KDELIBS2_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.kdelibs2?=	kdelibs-2.[1-9]*
DEPENDS+=	${BUILDLINK_DEPENDS.kdelibs2}:../../x11/kdelibs2

.include "../../mk/bsd.prefs.mk"

EVAL_PREFIX+=			BUILDLINK_PREFIX.kdelibs2=kdelibs
BUILDLINK_PREFIX.kdelibs2_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.kdelibs2!=	${GREP} "^\(include\|lib\)" ${.CURDIR}/../../x11/kdelibs2/PLIST
BUILDLINK_FILES.kdelibs2+=	bin/dcopserver

REPLACE_BUILDLINK_SED+=	\
	-e "s|-I${BUILDLINK_DIR}/\(include/artsc\)|-I${BUILDLINK_PREFIX.kdelibs2}/\1|g"
BUILDLINK_CONFIG_WRAPPER_SED+=  \
	-e "s|-I${BUILDLINK_PREFIX.kdelibs2}/\(include/artsc\)|-I${BUILDLINK_DIR}/\1|g"

BUILDLINK_KDEDIR=		${BUILDLINK_DIR}
KDEDIR=				${BUILDLINK_PREFIX.kdelibs2}

BUILDLINK_DEPENDS.audiofile=	libaudiofile>=0.1.9
USE_OPENSSL_VERSION=		${OPENSSL_VERSION_096}

.include "../../audio/libaudiofile/buildlink.mk"
.include "../../devel/pcre/buildlink.mk"
.include "../../security/openssl/buildlink.mk"
.include "../../x11/qt2-libs/buildlink.mk"
.include "../../mk/ossaudio.buildlink.mk"

.if defined(USE_CUPS) && (${USE_CUPS} == "YES")
.include "../../print/cups/buildlink.mk"
.endif

BUILDLINK_TARGETS.kdelibs2=	kdelibs2-buildlink
BUILDLINK_TARGETS.kdelibs2+=	kdelibs2-buildlink-config-wrapper
BUILDLINK_TARGETS.kdelibs2+=	kdelibs2-artsc-buildlink-config-wrapper
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.kdelibs2}

BUILDLINK_CONFIG.kdelibs2=		${BUILDLINK_PREFIX.kdelibs2}/bin/kde-config
BUILDLINK_CONFIG_WRAPPER.kdelibs2=	${BUILDLINK_DIR}/bin/kde-config
REPLACE_BUILDLINK_SED+=	\
	-e "s|${BUILDLINK_CONFIG_WRAPPER.kdelibs2}|${BUILDLINK_CONFIG.kdelibs2}|g"

BUILDLINK_CONFIG.kdelibs2-artsc=	 ${BUILDLINK_PREFIX.kdelibs2}/bin/artsc-config
BUILDLINK_CONFIG_WRAPPER.kdelibs2-artsc= ${BUILDLINK_DIR}/bin/artsc-config
REPLACE_BUILDLINK_SED+=	\
	-e "s|${BUILDLINK_CONFIG_WRAPPER.kdelibs2-artsc}|${BUILDLINK_CONFIG.kdelibs2-artsc}|g"

.if defined(USE_CONFIG_WRAPPER)
ARTSCCONFIG?=		${BUILDLINK_CONFIG_WRAPPER.kdelibs2-artsc}
KDECONFIG?=		${BUILDLINK_CONFIG_WRAPPER.kdelibs2}
CONFIGURE_ENV+=		ARTSCCONFIG="${ARTSCCONFIG}"
CONFIGURE_ENV+=		KDECONFIG="${KDECONFIG}"
MAKE_ENV+=		ARTSCCONFIG="${ARTSCCONFIG}"
MAKE_ENV+=		KDECONFIG="${KDECONFIG}"
.endif

pre-configure: ${BUILDLINK_TARGETS.kdelibs2}
kdelibs2-buildlink: _BUILDLINK_USE
kdelibs2-buildlink-config-wrapper: _BUILDLINK_CONFIG_WRAPPER_USE
kdelibs2-artsc-buildlink-config-wrapper: _BUILDLINK_CONFIG_WRAPPER_USE

.endif	# KDELIBS2_BUILDLINK_MK
