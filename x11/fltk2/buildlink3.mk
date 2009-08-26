# $NetBSD: buildlink3.mk,v 1.4 2009/08/26 19:56:42 sno Exp $

BUILDLINK_TREE+=	fltk2

.if !defined(FLTK2_BUILDLINK3_MK)
FLTK2_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.fltk2?=	build
BUILDLINK_API_DEPENDS.fltk2+=	fltk2>=2.0pre6129
BUILDLINK_ABI_DEPENDS.fltk2?=	fltk2>=2.0pre6129nb2
BUILDLINK_PKGSRCDIR.fltk2?=	../../x11/fltk2

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.endif # FLTK2_BUILDLINK3_MK

BUILDLINK_TREE+=	-fltk2
