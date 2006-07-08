# $NetBSD: buildlink3.mk,v 1.40 2006/07/08 22:39:44 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
XRENDER_BUILDLINK3_MK:=	${XRENDER_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	Xrender
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NXrender}
BUILDLINK_PACKAGES+=	Xrender
BUILDLINK_ORDER+=	Xrender

.if !empty(XRENDER_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.Xrender+=	Xrender>=0.2
BUILDLINK_ABI_DEPENDS.Xrender+=	Xrender>=0.9.0nb1
BUILDLINK_PKGSRCDIR.Xrender?=	../../x11/Xrender
.endif	# XRENDER_BUILDLINK3_MK

.include "../../mk/x11.buildlink3.mk"
.include "../../x11/renderproto/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
