# $NetBSD: buildlink3.mk,v 1.2 2013/01/26 21:36:55 adam Exp $

BUILDLINK_TREE+=	motif

.if !defined(X11MOTIF_BUILDLINK3_MK)
X11MOTIF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.motif+=	motif>=2.3.4
BUILDLINK_ABI_DEPENDS.motif+=	motif>=2.3.4nb2
BUILDLINK_PKGSRCDIR.motif?=	../../x11/motif

_MOTIFBASE=	${BUILDLINK_PREFIX.motif}
MOTIFLIB=	${COMPILER_RPATH_FLAG}${_MOTIFBASE}/lib \
		-L${_MOTIFBASE}/lib -lXm

BUILDLINK_TRANSFORM+=	rm:-lXp

.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/xbitmaps/buildlink3.mk"
.endif # X11MOTIF_BUILDLINK3_MK

BUILDLINK_TREE+=	-motif
