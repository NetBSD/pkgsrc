# $NetBSD: buildlink2.mk,v 1.1.2.1 2002/05/11 02:09:30 jlam Exp $
#
# This Makefile fragment is included by packages that use kdelibs2.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.kdelibs2 to the dependency pattern
#     for the version of kdelibs2 desired.
# (2) Include this Makefile fragment in the package Makefile.

.if !defined(KDELIBS2_BUILDLINK2_MK)
KDELIBS2_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.buildlink2.mk"

BUILDLINK_DEPENDS.kdelibs2?=	kdelibs>=2.2.2nb1
DEPENDS+=	${BUILDLINK_DEPENDS.kdelibs2}:../../x11/kdelibs2

.include "../../mk/bsd.prefs.mk"

EVAL_PREFIX+=	BUILDLINK_PREFIX.kdelibs2=kdelibs
BUILDLINK_PREFIX.kdelibs2_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.kdelibs2!=	${GREP} "^\(include\|lib\)" ${.CURDIR}/../../x11/kdelibs2/PLIST

KDEDIR=				${BUILDLINK_PREFIX.kdelibs2}

BUILDLINK_DEPENDS.audiofile=	libaudiofile>=0.1.9
BUILDLINK_DEPENDS.qt2-libs=	qt2-libs>=2.3.1nb2
USE_OPENSSL_VERSION=		${OPENSSL_VERSION_096}

.include "../../audio/libaudiofile/buildlink2.mk"
.include "../../devel/pcre/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../x11/qt2-libs/buildlink2.mk"
.include "../../mk/ossaudio.buildlink2.mk"

.if defined(USE_CUPS) && (${USE_CUPS} == "YES")
.include "../../print/cups/buildlink2.mk"
.endif

BUILDLINK_TARGETS+=	kdelibs2-buildlink

kdelibs2-buildlink: _BUILDLINK_USE

.endif	# KDELIBS2_BUILDLINK2_MK
