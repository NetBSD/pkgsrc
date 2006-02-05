# $NetBSD: buildlink3.mk,v 1.20 2006/02/05 23:11:31 joerg Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
XRANDR_BUILDLINK3_MK:=	${XRANDR_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	Xrandr
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NXrandr}
BUILDLINK_PACKAGES+=	Xrandr

.if !empty(XRANDR_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.Xrandr+=	Xrandr>=0.99
BUILDLINK_RECOMMENDED.Xrandr+=	Xrandr>=1.0.2nb3
BUILDLINK_PKGSRCDIR.Xrandr?=	../../x11/Xrandr
.endif	# XRANDR_BUILDLINK3_MK

.include "../../x11/randrext/buildlink3.mk"
.include "../../x11/Xrender/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
