# $NetBSD: buildlink3.mk,v 1.1 2004/03/06 06:26:21 minskim Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
BLT_BUILDLINK3_MK:=	${BLT_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	blt
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nblt}
BUILDLINK_PACKAGES+=	blt

.if !empty(BLT_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.blt+=	blt>=2.4o
BUILDLINK_PKGSRCDIR.blt?=	../../x11/blt

.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"

.endif	# BLT_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
