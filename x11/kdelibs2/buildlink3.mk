# $NetBSD: buildlink3.mk,v 1.2 2004/10/03 00:18:36 tv Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
KDELIBS2_BUILDLINK3_MK:=	${KDELIBS2_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	kdelibs2
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nkdelibs2}
BUILDLINK_PACKAGES+=	kdelibs2

.if !empty(KDELIBS2_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.kdelibs2+=	kdelibs>=2.2.2nb9
BUILDLINK_DEPENDS.kdelibs2+=	kdelibs<3.0	# qt2-designer-kde wants KDE 2
BUILDLINK_RECOMMENDED.kdelibs2?=kdelibs>=2.2.2nb13
BUILDLINK_PKGSRCDIR.kdelibs2?=	../../x11/kdelibs2
.endif	# KDELIB2S_BUILDLINK3_MK

KDEDIR=				${BUILDLINK_PREFIX.kdelibs2}

BUILDLINK_DEPENDS.audiofile=    libaudiofile>=0.2.3

.include "../../audio/libaudiofile/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../x11/qt2-libs/buildlink3.mk"

.if defined(USE_CUPS) && (${USE_CUPS} == "YES")
.  include "../../print/cups/buildlink3.mk"
.endif

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
