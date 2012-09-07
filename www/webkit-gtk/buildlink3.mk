# $NetBSD: buildlink3.mk,v 1.25 2012/09/07 19:17:42 adam Exp $

BUILDLINK_TREE+=	webkit-gtk

.if !defined(WEBKIT_GTK_BUILDLINK3_MK)
WEBKIT_GTK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.webkit-gtk+=	webkit-gtk>=1.1.3
BUILDLINK_ABI_DEPENDS.webkit-gtk+=	webkit-gtk>=1.8.3
BUILDLINK_PKGSRCDIR.webkit-gtk?=	../../www/webkit-gtk

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/gperf/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
.include "../../net/libsoup24/buildlink3.mk"
.include "../../textproc/enchant/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.endif # WEBKIT_GTK_BUILDLINK3_MK

BUILDLINK_TREE+=	-webkit-gtk
