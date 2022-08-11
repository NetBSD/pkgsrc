# $NetBSD: buildlink3.mk,v 1.4 2022/08/11 05:09:34 gutteridge Exp $

BUILDLINK_TREE+=	wxGTK31

.if !defined(WXGTK31_BUILDLINK3_MK)
WXGTK31_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.wxGTK31+=	wxGTK31>=3.1
BUILDLINK_ABI_DEPENDS.wxGTK31+=	wxGTK31>=3.1.7nb3
BUILDLINK_PKGSRCDIR.wxGTK31?=	../../x11/wxGTK31

BUILDLINK_INCDIRS.wxGTK31+=	include/wx-3.1
PREPEND_PATH+=			${PREFIX}/libexec/wx-3.1
CONFIGURE_ARGS+=		--with-wx-version=3.1
CONFIGURE_ARGS+=		--with-wx-config=${PREFIX}/libexec/wx-3.1/wx-config

pkgbase := wxGTK31
.include "../../mk/pkg-build-options.mk"

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.if ${OPSYS} != "Darwin"
.include "../../x11/gtk3/buildlink3.mk"
.endif
.endif # WXGTK31_BUILDLINK3_MK

BUILDLINK_TREE+=	-wxGTK31
