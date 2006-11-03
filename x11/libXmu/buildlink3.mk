# $NetBSD: buildlink3.mk,v 1.1.1.1 2006/11/03 20:53:29 joerg Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBXMU_BUILDLINK3_MK:=	${LIBXMU_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	libXmu
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NlibXmu}
BUILDLINK_PACKAGES+=	libXmu
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libXmu

.if ${LIBXMU_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.libXmu+=	libXmu>=1.0.0
BUILDLINK_PKGSRCDIR.libXmu?=	../../x11/libXmu
.endif	# LIBXMU_BUILDLINK3_MK

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
