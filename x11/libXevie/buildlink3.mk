# $NetBSD: buildlink3.mk,v 1.1.1.1 2006/11/03 21:50:18 joerg Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBXEVIE_BUILDLINK3_MK:=	${LIBXEVIE_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	libXevie
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NlibXevie}
BUILDLINK_PACKAGES+=	libXevie
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libXevie

.if ${LIBXEVIE_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.libXevie+=	libXevie>=1.0.2
BUILDLINK_PKGSRCDIR.libXevie?=	../../x11/libXevie
.endif	# LIBXEVIE_BUILDLINK3_MK

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
