# $NetBSD: buildlink3.mk,v 1.1.1.1 2006/11/03 21:40:59 joerg Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBXV_BUILDLINK3_MK:=	${LIBXV_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	libXv
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NlibXv}
BUILDLINK_PACKAGES+=	libXv
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libXv

.if ${LIBXV_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.libXv+=	libXv>=1.0.1
BUILDLINK_PKGSRCDIR.libXv?=	../../x11/libXv
.endif	# LIBXV_BUILDLINK3_MK

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/videoproto/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
