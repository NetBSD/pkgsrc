# $NetBSD: buildlink3.mk,v 1.5 2006/07/11 14:42:04 joerg Exp $

.include "../../mk/bsd.prefs.mk"

.if ${X11_TYPE} == "xorg"
.include "../../mk/x11.buildlink3.mk"
.else

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
RENDERPROTO_BUILDLINK3_MK:=	${RENDERPROTO_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	renderproto
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nrenderproto}
BUILDLINK_PACKAGES+=	renderproto
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}renderproto

.if !empty(RENDERPROTO_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.renderproto+=	renderproto>=0.9.1
BUILDLINK_PKGSRCDIR.renderproto?=	../../x11/renderproto
BUILDLINK_DEPMETHOD.renderproto?=	build
.endif	# RENDERPROTO_BUILDLINK3_MK

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}

.endif
