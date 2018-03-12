# $NetBSD: buildlink3.mk,v 1.11 2018/03/12 11:15:58 wiz Exp $

BUILDLINK_TREE+=	wxGTK30

.if !defined(WXGTK30_BUILDLINK3_MK)
WXGTK30_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.wxGTK30+=	wxGTK30>=3.0.1
BUILDLINK_ABI_DEPENDS.wxGTK30+=	wxGTK30>=3.0.3.1nb1
BUILDLINK_PKGSRCDIR.wxGTK30?=	../../x11/wxGTK30

BUILDLINK_INCDIRS.wxGTK30+=	include/wx-3.0
PREPEND_PATH+=			${PREFIX}/libexec/wx-3.0
CONFIGURE_ARGS+=		--with-wx-version=3.0
CONFIGURE_ARGS+=		--with-wx-config=${PREFIX}/libexec/wx-3.0/wx-config

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.if ${OPSYS} != "Darwin"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.endif
.endif # WXGTK30_BUILDLINK3_MK

BUILDLINK_TREE+=	-wxGTK30
