# $NetBSD: buildlink3.mk,v 1.16 2004/11/08 12:38:19 markd Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
XRANDR_BUILDLINK3_MK:=	${XRANDR_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	Xrandr
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NXrandr}
BUILDLINK_PACKAGES+=	Xrandr

.if !empty(XRANDR_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.Xrandr+=	Xrandr>=0.99
BUILDLINK_RECOMMENDED.Xrandr+=	Xrandr>=1.0.2nb1
BUILDLINK_PKGSRCDIR.Xrandr?=	../../x11/Xrandr
.endif	# XRANDR_BUILDLINK3_MK

USE_X11=	yes

.include "../../x11/randrext/buildlink3.mk"
.include "../../x11/Xrender/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
