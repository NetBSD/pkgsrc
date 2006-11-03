# $NetBSD: buildlink3.mk,v 1.1.1.1 2006/11/03 21:22:58 joerg Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBXRANDR_BUILDLINK3_MK:=	${LIBXRANDR_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	libXrandr
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NlibXrandr}
BUILDLINK_PACKAGES+=	libXrandr
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libXrandr

.if ${LIBXRANDR_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.libXrandr+=	libXrandr>=1.1.2
BUILDLINK_PKGSRCDIR.libXrandr?=	../../x11/libXrandr
.endif	# LIBXRANDR_BUILDLINK3_MK

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/randrproto/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
