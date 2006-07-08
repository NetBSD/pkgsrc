# $NetBSD: buildlink3.mk,v 1.7 2006/07/08 23:11:17 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
XFORMS_BUILDLINK3_MK:=	${XFORMS_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	xforms
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxforms}
BUILDLINK_PACKAGES+=	xforms
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}xforms

.if !empty(XFORMS_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.xforms+=	xforms>=1.0nb2
BUILDLINK_ABI_DEPENDS.xforms+=	xforms>=1.0nb5
BUILDLINK_PKGSRCDIR.xforms?=	../../x11/xforms
.endif	# XFORMS_BUILDLINK3_MK

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
