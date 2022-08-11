# $NetBSD: buildlink3.mk,v 1.2 2022/08/11 05:09:34 gutteridge Exp $

BUILDLINK_TREE+=	wxGTK32

.if !defined(WXGTK32_BUILDLINK3_MK)
WXGTK32_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.wxGTK32+=	wxGTK32>=3.2
BUILDLINK_ABI_DEPENDS.wxGTK32?=	wxGTK32>=3.2.0nb5
BUILDLINK_PKGSRCDIR.wxGTK32?=	../../x11/wxGTK32

BUILDLINK_INCDIRS.wxGTK32+=	include/wx-3.2
PREPEND_PATH+=			${PREFIX}/libexec/wx-3.2
CONFIGURE_ARGS+=		--with-wx-version=3.2
CONFIGURE_ARGS+=		--with-wx-config=${PREFIX}/libexec/wx-3.2/wx-config

pkgbase := wxGTK32
.include "../../mk/pkg-build-options.mk"

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.if ${OPSYS} != "Darwin"
.include "../../x11/gtk3/buildlink3.mk"
.endif
.endif # WXGTK32_BUILDLINK3_MK

BUILDLINK_TREE+=	-wxGTK32
