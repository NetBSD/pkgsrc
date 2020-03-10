# $NetBSD: buildlink3.mk,v 1.21 2020/03/10 22:09:17 wiz Exp $

BUILDLINK_TREE+=	wxGTK30

.if !defined(WXGTK30_BUILDLINK3_MK)
WXGTK30_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.wxGTK30+=	wxGTK30>=3.0.1
BUILDLINK_ABI_DEPENDS.wxGTK30+=	wxGTK30>=3.0.4nb5
BUILDLINK_PKGSRCDIR.wxGTK30?=	../../x11/wxGTK30

BUILDLINK_INCDIRS.wxGTK30+=	include/wx-3.0
PREPEND_PATH+=			${PREFIX}/libexec/wx-3.0
CONFIGURE_ARGS+=		--with-wx-version=3.0
CONFIGURE_ARGS+=		--with-wx-config=${PREFIX}/libexec/wx-3.0/wx-config

pkgbase := wxGTK30
.include "../../mk/pkg-build-options.mk"

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.if ${OPSYS} != "Darwin"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.  if !empty(PKG_BUILD_OPTIONS.wxGTK30:Mgtk2)
.include "../../x11/gtk2/buildlink3.mk"
.  else
.include "../../x11/gtk3/buildlink3.mk"
.  endif
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.endif
.endif # WXGTK30_BUILDLINK3_MK

BUILDLINK_TREE+=	-wxGTK30
