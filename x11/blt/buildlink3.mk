# $NetBSD: buildlink3.mk,v 1.5 2004/03/18 09:12:16 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
BLT_BUILDLINK3_MK:=	${BLT_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	blt
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nblt}
BUILDLINK_PACKAGES+=	blt

.if !empty(BLT_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.blt+=		blt>=2.4o
BUILDLINK_PKGSRCDIR.blt?=	../../x11/blt
.endif	# BLT_BUILDLINK3_MK

.include "../../lang/tcl83/buildlink3.mk"
.include "../../x11/tk83/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
