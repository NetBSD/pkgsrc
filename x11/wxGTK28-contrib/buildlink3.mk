# $NetBSD: buildlink3.mk,v 1.37 2020/03/08 16:48:34 wiz Exp $

BUILDLINK_TREE+=	wxGTK28-contrib

.if !defined(WXGTK28_CONTRIB_BUILDLINK3_MK)
WXGTK28_CONTRIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.wxGTK28-contrib+=	wxGTK28-contrib>=2.8.10
BUILDLINK_ABI_DEPENDS.wxGTK28-contrib+=	wxGTK28-contrib>=2.8.12nb14
BUILDLINK_PKGSRCDIR.wxGTK28-contrib?=	../../x11/wxGTK28-contrib

.include "../../x11/wxGTK28/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.endif # WXGTK28_CONTRIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-wxGTK28-contrib
