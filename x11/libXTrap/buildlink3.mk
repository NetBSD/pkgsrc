# $NetBSD: buildlink3.mk,v 1.1.1.1 2006/11/03 20:58:20 joerg Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBXTRAP_BUILDLINK3_MK:=	${LIBXTRAP_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	libXTrap
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NlibXTrap}
BUILDLINK_PACKAGES+=	libXTrap
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libXTrap

.if ${LIBXTRAP_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.libXTrap+=	libXTrap>=1.0.0
BUILDLINK_PKGSRCDIR.libXTrap?=	../../x11/libXTrap
.endif	# LIBXTRAP_BUILDLINK3_MK

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
