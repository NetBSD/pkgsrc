# $NetBSD: buildlink3.mk,v 1.10 2006/07/08 23:11:14 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GTKGLAREA2_BUILDLINK3_MK:=	${GTKGLAREA2_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gtkglarea2
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngtkglarea2}
BUILDLINK_PACKAGES+=	gtkglarea2
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}gtkglarea2

.if !empty(GTKGLAREA2_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.gtkglarea2+=		gtkglarea2>=1.99.0nb3
BUILDLINK_ABI_DEPENDS.gtkglarea2?=	gtkglarea2>=1.99.0nb7
BUILDLINK_PKGSRCDIR.gtkglarea2?=	../../x11/gtkglarea2
.endif	# GTKGLAREA2_BUILDLINK3_MK

.include "../../graphics/Mesa/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
