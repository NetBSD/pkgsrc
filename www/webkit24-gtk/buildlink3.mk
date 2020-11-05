# $NetBSD: buildlink3.mk,v 1.28 2020/11/05 09:07:13 ryoon Exp $

BUILDLINK_TREE+=	webkit24-gtk

.if !defined(WEBKIT24_GTK_BUILDLINK3_MK)
WEBKIT24_GTK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.webkit24-gtk+=	webkit24-gtk>=2.0
BUILDLINK_ABI_DEPENDS.webkit24-gtk?=	webkit24-gtk>=2.4.11nb32
BUILDLINK_PKGSRCDIR.webkit24-gtk?=	../../www/webkit24-gtk

# Linking with this library may require newer libstdc++ features than are
# available under the native compiler, so possibly upgrade the compiler
# used by dependent packages too.
GCC_REQD+=	4.8

pkgbase := webkit24-gtk
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.webkit24-gtk:Menchant)
.include "../../textproc/enchant/buildlink3.mk"
.endif

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/gperf/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
.include "../../security/libsecret/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libXdamage/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.endif # WEBKIT24_GTK_BUILDLINK3_MK

BUILDLINK_TREE+=	-webkit24-gtk
