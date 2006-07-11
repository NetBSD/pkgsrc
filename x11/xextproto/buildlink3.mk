# $NetBSD: buildlink3.mk,v 1.4 2006/07/11 14:42:04 joerg Exp $

.include "../../mk/bsd.prefs.mk"

.if ${X11_TYPE} == "xorg"
.include "../../mk/x11.buildlink3.mk"
.else

BUILDLINK_DEPMETHOD.xextproto?=	build

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
XEXTPROTO_BUILDLINK3_MK:=	${XEXTPROTO_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	xextproto
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxextproto}
BUILDLINK_PACKAGES+=	xextproto
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}xextproto

.if !empty(XEXTPROTO_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.xextproto+=	xextproto>=7.0
BUILDLINK_PKGSRCDIR.xextproto?=	../../x11/xextproto
.endif	# XEXTPROTO_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}

.endif
