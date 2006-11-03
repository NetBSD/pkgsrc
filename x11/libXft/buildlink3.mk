# $NetBSD: buildlink3.mk,v 1.1.1.1 2006/11/03 21:26:36 joerg Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBXFT_BUILDLINK3_MK:=	${LIBXFT_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	libXft
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NlibXft}
BUILDLINK_PACKAGES+=	libXft
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libXft

.if ${LIBXFT_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.libXft+=	libXft>=2.1.10
BUILDLINK_PKGSRCDIR.libXft?=	../../x11/libXft
.endif	# LIBXFT_BUILDLINK3_MK

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
