# $NetBSD: buildlink3.mk,v 1.1.1.1 2006/11/03 20:02:34 joerg Exp $

BUILDLINK_DEPMETHOD.trapproto?=	build

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
TRAPPROTO_BUILDLINK3_MK:=	${TRAPPROTO_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	trapproto
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ntrapproto}
BUILDLINK_PACKAGES+=	trapproto
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}trapproto

.if ${TRAPPROTO_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.trapproto+=	trapproto>=3.4.3
BUILDLINK_PKGSRCDIR.trapproto?=	../../x11/trapproto
.endif	# TRAPPROTO_BUILDLINK3_MK

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
