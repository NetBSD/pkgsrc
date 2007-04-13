# $NetBSD: buildlink3.mk,v 1.16 2007/04/13 05:45:36 xtraeme Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
FOX_BUILDLINK3_MK:=	${FOX_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	fox
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nfox}
BUILDLINK_PACKAGES+=	fox
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}fox

.if !empty(FOX_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.fox+=	fox>=1.6.25
BUILDLINK_PKGSRCDIR.fox?=	../../x11/fox
BUILDLINK_INCDIRS.fox?=		include/fox-1.6
.endif	# FOX_BUILDLINK3_MK

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
