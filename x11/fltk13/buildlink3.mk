# $NetBSD: buildlink3.mk,v 1.4 2013/02/16 11:18:12 wiz Exp $

BUILDLINK_TREE+=	fltk

.if !defined(FLTK_BUILDLINK3_MK)
FLTK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.fltk+=	fltk>=1.3.0
BUILDLINK_ABI_DEPENDS.fltk?=	fltk>=1.3.0nb10
BUILDLINK_PKGSRCDIR.fltk?=	../../x11/fltk13
BUILDLINK_FILES.fltk+=		include/Fl/*

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.endif # FLTK_BUILDLINK3_MK

BUILDLINK_TREE+=	-fltk
