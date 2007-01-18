# $NetBSD: buildlink3.mk,v 1.6 2007/01/18 17:48:56 joerg Exp $

.include "../../mk/bsd.fast.prefs.mk"

.if ${X11_TYPE} == "xorg"
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
