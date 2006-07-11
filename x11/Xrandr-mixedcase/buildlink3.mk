# $NetBSD: buildlink3.mk,v 1.25 2006/07/11 14:42:03 joerg Exp $

.include "../../mk/bsd.prefs.mk"

.if ${X11_TYPE} == "xorg"
.include "../../mk/x11.buildlink3.mk"
.else

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
XRANDR_BUILDLINK3_MK:=	${XRANDR_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	Xrandr
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NXrandr}
BUILDLINK_PACKAGES+=	Xrandr
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}Xrandr

.if !empty(XRANDR_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.Xrandr+=	Xrandr>=0.99
BUILDLINK_ABI_DEPENDS.Xrandr+=	Xrandr>=1.0.2nb3
BUILDLINK_PKGSRCDIR.Xrandr?=	../../x11/Xrandr
.endif	# XRANDR_BUILDLINK3_MK

.include "../../x11/randrproto/buildlink3.mk"
.include "../../x11/Xrender/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}

.endif
