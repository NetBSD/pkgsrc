# $NetBSD: buildlink3.mk,v 1.4 2009/03/23 00:38:55 joerg Exp $

BUILDLINK_TREE+=	wxGTK28

.if !defined(WXGTK28_BUILDLINK3_MK)
WXGTK28_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.wxGTK28+=	wxGTK28>=2.8.10
BUILDLINK_PKGSRCDIR.wxGTK28?=	../../x11/wxGTK28

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.endif # WXGTK28_BUILDLINK3_MK

BUILDLINK_TREE+=	-wxGTK28
