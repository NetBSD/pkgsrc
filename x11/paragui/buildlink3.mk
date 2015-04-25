# $NetBSD: buildlink3.mk,v 1.27 2015/04/25 14:25:14 tnn Exp $

BUILDLINK_TREE+=	paragui

.if !defined(PARAGUI_BUILDLINK3_MK)
PARAGUI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.paragui+=	paragui>=1.0.4nb3
BUILDLINK_ABI_DEPENDS.paragui+=	paragui>=1.0.4nb22
BUILDLINK_PKGSRCDIR.paragui?=	../../x11/paragui

.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/physfs/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.endif # PARAGUI_BUILDLINK3_MK

BUILDLINK_TREE+=	-paragui
