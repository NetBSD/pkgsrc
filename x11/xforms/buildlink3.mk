# $NetBSD: buildlink3.mk,v 1.3 2006/02/05 23:11:47 joerg Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
XFORMS_BUILDLINK3_MK:=	${XFORMS_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	xforms
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxforms}
BUILDLINK_PACKAGES+=	xforms

.if !empty(XFORMS_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.xforms+=	xforms>=1.0nb2
BUILDLINK_RECOMMENDED.xforms+=	xforms>=1.0nb5
BUILDLINK_PKGSRCDIR.xforms?=	../../x11/xforms
.endif	# XFORMS_BUILDLINK3_MK

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
