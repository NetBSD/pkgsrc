# $NetBSD: buildlink2.mk,v 1.22 2003/12/08 14:41:42 wiz Exp $

.if !defined(KDELIBS3_BUILDLINK2_MK)
KDELIBS3_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		kdelibs3
BUILDLINK_PKGBASE.kdelibs3?=	kdelibs
BUILDLINK_DEPENDS.kdelibs3?=	kdelibs>=3.1.4nb2
BUILDLINK_PKGSRCDIR.kdelibs3?=	../../x11/kdelibs3

.include "../../mk/bsd.prefs.mk"

EVAL_PREFIX+=			BUILDLINK_PREFIX.kdelibs3=kdelibs
BUILDLINK_PREFIX.kdelibs3_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES_CMD.kdelibs3= \
	${BUILDLINK_PLIST_CMD.kdelibs3} | ${GREP} '^\(include\|lib\)'

KDEDIR=				${BUILDLINK_PREFIX.kdelibs3}

BUILDLINK_DEPENDS.audiofile=	libaudiofile>=0.2.3nb1

.include "../../audio/libaudiofile/buildlink2.mk"
.include "../../audio/arts/buildlink2.mk"
.include "../../devel/pcre/buildlink2.mk"
.include "../../graphics/libart2/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../x11/qt3-libs/buildlink2.mk"
.include "../../textproc/libxslt/buildlink2.mk"
.include "../../mk/ossaudio.buildlink2.mk"

.if defined(USE_CUPS) && (${USE_CUPS} == "YES")
.  include "../../print/cups/buildlink2.mk"
.endif

BUILDLINK_TARGETS+=	kdelibs3-buildlink

kdelibs3-buildlink: _BUILDLINK_USE

.endif	# KDELIBS3_BUILDLINK2_MK
