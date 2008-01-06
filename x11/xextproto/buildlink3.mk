# $NetBSD: buildlink3.mk,v 1.7 2008/01/06 16:57:43 rillig Exp $

.include "../../mk/bsd.fast.prefs.mk"

.if ${X11_TYPE} != "modular"
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

.include "../../x11/inputproto/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}

.endif
