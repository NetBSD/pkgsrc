# $NetBSD: buildlink3.mk,v 1.7 2008/01/06 16:57:42 rillig Exp $

.include "../../mk/bsd.fast.prefs.mk"

.if ${X11_TYPE} != "modular"
.include "../../mk/x11.buildlink3.mk"
.else

BUILDLINK_DEPMETHOD.randrproto?=	build

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
RANDRPROTO_BUILDLINK3_MK:=	${RANDRPROTO_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	randrproto
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nrandrproto}
BUILDLINK_PACKAGES+=	randrproto
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}randrproto

.if !empty(RANDRPROTO_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.randrproto+=	randrproto>=1.2.0
BUILDLINK_PKGSRCDIR.randrproto?=	../../x11/randrproto
.endif	# RANDRPROTO_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}

.endif
