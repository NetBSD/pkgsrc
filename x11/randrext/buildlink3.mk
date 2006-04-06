# $NetBSD: buildlink3.mk,v 1.8 2006/04/06 06:23:03 reed Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
RANDREXT_BUILDLINK3_MK:=	${RANDREXT_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	randrext
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nrandrext}
BUILDLINK_PACKAGES+=	randrext

.if !empty(RANDREXT_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.randrext+=	randrext>=1.0
BUILDLINK_ABI_DEPENDS.randrext?=	randrext>=1.0nb2
BUILDLINK_PKGSRCDIR.randrext?=	../../x11/randrext
BUILDLINK_DEPMETHOD.randrext?=	build
.endif	# RANDREXT_BUILDLINK3_MK

.include "../../x11/xextensions/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
