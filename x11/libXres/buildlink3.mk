# $NetBSD: buildlink3.mk,v 1.1.1.1 2006/11/03 22:05:26 joerg Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBXRES_BUILDLINK3_MK:=	${LIBXRES_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	libXres
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NlibXres}
BUILDLINK_PACKAGES+=	libXres
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libXres

.if ${LIBXRES_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.libXres+=	libXres>=1.0.0
BUILDLINK_PKGSRCDIR.libXres?=	../../x11/libXres
.endif	# LIBXRES_BUILDLINK3_MK

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
