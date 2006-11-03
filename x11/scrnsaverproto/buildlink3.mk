# $NetBSD: buildlink3.mk,v 1.1.1.1 2006/11/03 20:11:57 joerg Exp $

BUILDLINK_DEPMETHOD.scrnsaverproto?=	build

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
SCRNSAVERPROTO_BUILDLINK3_MK:=	${SCRNSAVERPROTO_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	scrnsaverproto
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nscrnsaverproto}
BUILDLINK_PACKAGES+=	scrnsaverproto
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}scrnsaverproto

.if ${SCRNSAVERPROTO_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.scrnsaverproto+=	scrnsaverproto>=1.1.0
BUILDLINK_PKGSRCDIR.scrnsaverproto?=	../../x11/scrnsaverproto
.endif	# SCRNSAVERPROTO_BUILDLINK3_MK

.include "../../x11/xproto/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
