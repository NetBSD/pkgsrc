# $NetBSD: buildlink3.mk,v 1.69 2018/11/12 11:29:27 wiz Exp $

BUILDLINK_TREE+=	webkit-gtk

.if !defined(WEBKIT_GTK_BUILDLINK3_MK)
WEBKIT_GTK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.webkit-gtk+=	webkit-gtk>=2.8
BUILDLINK_ABI_DEPENDS.webkit-gtk?=	webkit-gtk>=2.22.3nb2
BUILDLINK_PKGSRCDIR.webkit-gtk?=	../../www/webkit-gtk

# This is necessary to match the package requirement.
GCC_REQD+=	6

pkgbase := webkit-gtk
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.webkit-gtk:Menchant)
.include "../../textproc/enchant2/buildlink3.mk"
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
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/libXdamage/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.endif # WEBKIT_GTK_BUILDLINK3_MK

BUILDLINK_TREE+=	-webkit-gtk
