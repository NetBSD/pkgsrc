# $NetBSD: buildlink3.mk,v 1.42 2006/07/11 14:42:04 joerg Exp $

.include "../../mk/bsd.prefs.mk"

.if ${X11_TYPE} == "xorg"
.include "../../mk/x11.buildlink3.mk"
.else

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
XRENDER_BUILDLINK3_MK:=	${XRENDER_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	Xrender
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NXrender}
BUILDLINK_PACKAGES+=	Xrender
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}Xrender

.if !empty(XRENDER_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.Xrender+=	Xrender>=0.2
BUILDLINK_ABI_DEPENDS.Xrender+=	Xrender>=0.9.0nb1
BUILDLINK_PKGSRCDIR.Xrender?=	../../x11/Xrender
.endif	# XRENDER_BUILDLINK3_MK

.include "../../mk/x11.buildlink3.mk"
.include "../../x11/renderproto/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}

.endif
