# $NetBSD: buildlink3.mk,v 1.1.1.1 2006/11/03 21:01:49 joerg Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBXP_BUILDLINK3_MK:=	${LIBXP_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	libXp
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NlibXp}
BUILDLINK_PACKAGES+=	libXp
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libXp

.if ${LIBXP_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.libXp+=	libXp>=1.0.0
BUILDLINK_PKGSRCDIR.libXp?=	../../x11/libXp
.endif	# LIBXP_BUILDLINK3_MK

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/printproto/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
