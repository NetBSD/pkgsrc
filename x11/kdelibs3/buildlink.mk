# $NetBSD: buildlink.mk,v 1.2 2002/06/27 06:57:08 skrll Exp $
#
# This Makefile fragment is included by packages that use kdelibs3.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.kdelibs3 to the dependency pattern
#     for the version of kdelibs3 desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(KDELIBS3_BUILDLINK_MK)
KDELIBS3_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.kdelibs3?=	kdelibs>=3.0
DEPENDS+=	${BUILDLINK_DEPENDS.kdelibs3}:../../x11/kdelibs3

.include "../../mk/bsd.prefs.mk"

EVAL_PREFIX+=			BUILDLINK_PREFIX.kdelibs3=kdelibs
BUILDLINK_PREFIX.kdelibs3_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.kdelibs3!=	${GREP} "^\(include\|lib\)" ${.CURDIR}/../../x11/kdelibs3/PLIST
BUILDLINK_FILES.kdelibs3+=	bin/dcopserver
BUILDLINK_FILES.kdelibs3+=	bin/dcopidl

#REPLACE_BUILDLINK_SED+=	\
#	-e "s|-I${BUILDLINK_DIR}/\(include/artsc\)|-I${BUILDLINK_PREFIX.kdelibs3}/\1|g"
#BUILDLINK_CONFIG_WRAPPER_SED+=  \
#	-e "s|-I${BUILDLINK_PREFIX.kdelibs3}/\(include/artsc\)|-I${BUILDLINK_DIR}/\1|g"

BUILDLINK_KDEDIR=		${BUILDLINK_DIR}
KDEDIR=				${BUILDLINK_PREFIX.kdelibs3}

CONFIGURE_ENV+=			DCOPIDL=${BUILDLINK_KDEDIR}/bin/dcopidl

BUILDLINK_DEPENDS.audiofile=	libaudiofile>=0.1.9
BUILDLINK_DEPENDS.qt3-libs=	qt3-libs>=3.0.3
USE_OPENSSL_VERSION=		${OPENSSL_VERSION_096}

.include "../../audio/libaudiofile/buildlink.mk"
.include "../../audio/arts/buildlink.mk"
.include "../../devel/pcre/buildlink.mk"
.include "../../security/openssl/buildlink.mk"
.include "../../x11/qt3-libs/buildlink.mk"
.include "../../mk/ossaudio.buildlink.mk"

.if defined(USE_CUPS) && (${USE_CUPS} == "YES")
.include "../../print/cups/buildlink.mk"
.endif

BUILDLINK_TARGETS.kdelibs3=	kdelibs3-buildlink
BUILDLINK_TARGETS.kdelibs3+=	kdelibs3-buildlink-config-wrapper
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.kdelibs3}

BUILDLINK_CONFIG.kdelibs3=		${BUILDLINK_PREFIX.kdelibs3}/bin/kde-config
BUILDLINK_CONFIG_WRAPPER.kdelibs3=	${BUILDLINK_DIR}/bin/kde-config
REPLACE_BUILDLINK_SED+=	\
	-e "s|${BUILDLINK_CONFIG_WRAPPER.kdelibs3}|${BUILDLINK_CONFIG.kdelibs3}|g"

.if defined(USE_CONFIG_WRAPPER)
KDECONFIG?=		${BUILDLINK_CONFIG_WRAPPER.kdelibs3}
CONFIGURE_ENV+=		KDECONFIG="${KDECONFIG}"
MAKE_ENV+=		KDECONFIG="${KDECONFIG}"
.endif

pre-configure: ${BUILDLINK_TARGETS.kdelibs3}
kdelibs3-buildlink: _BUILDLINK_USE
kdelibs3-buildlink-config-wrapper: _BUILDLINK_CONFIG_WRAPPER_USE

.endif	# KDELIBS3_BUILDLINK_MK
