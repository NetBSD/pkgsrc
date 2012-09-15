# $NetBSD: buildlink3.mk,v 1.17 2012/09/15 10:07:17 obache Exp $

BUILDLINK_TREE+=	wxGTK-contrib

.if !defined(WXGTK_CONTRIB_BUILDLINK3_MK)
WXGTK_CONTRIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.wxGTK-contrib+=	wxGTK-contrib>=2.6.0nb2
BUILDLINK_ABI_DEPENDS.wxGTK-contrib+=	wxGTK-contrib>=2.6.3nb15
BUILDLINK_PKGSRCDIR.wxGTK-contrib?=	../../x11/wxGTK26-contrib

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/wxGTK26/buildlink3.mk"
.endif # WXGTK_CONTRIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-wxGTK-contrib
