# $NetBSD: buildlink2.mk,v 1.3 2002/09/10 16:06:55 wiz Exp $

.if !defined(KDELIBS3_BUILDLINK2_MK)
KDELIBS3_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		kdelibs3
BUILDLINK_DEPENDS.kdelibs3?=	kdelibs>=3.0.3nb1
BUILDLINK_PKGSRCDIR.kdelibs3?=	../../x11/kdelibs3

.include "../../mk/bsd.prefs.mk"

EVAL_PREFIX+=			BUILDLINK_PREFIX.kdelibs3=kdelibs
BUILDLINK_PREFIX.kdelibs3_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.kdelibs3!=	${GREP} "^\(include\|lib\)" ${.CURDIR}/../../x11/kdelibs3/PLIST

KDEDIR=				${BUILDLINK_PREFIX.kdelibs3}

BUILDLINK_DEPENDS.audiofile=	libaudiofile>=0.1.9
BUILDLINK_DEPENDS.qt3-libs=	qt3-libs>=3.0.3
USE_OPENSSL_VERSION=		${OPENSSL_VERSION_096}

.include "../../audio/libaudiofile/buildlink2.mk"
.include "../../audio/arts/buildlink2.mk"
.include "../../devel/pcre/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../x11/qt3-libs/buildlink2.mk"
.include "../../mk/ossaudio.buildlink2.mk"

.if defined(USE_CUPS) && (${USE_CUPS} == "YES")
.  include "../../print/cups/buildlink2.mk"
.endif

BUILDLINK_TARGETS+=	kdelibs3-buildlink

kdelibs3-buildlink: _BUILDLINK_USE

.endif	# KDELIBS3_BUILDLINK2_MK
