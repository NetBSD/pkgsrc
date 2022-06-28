# $NetBSD: buildlink3.mk,v 1.79 2022/06/28 11:37:53 wiz Exp $

BUILDLINK_TREE+=	gtk2

.if !defined(GTK2_BUILDLINK3_MK)
GTK2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.4.0
BUILDLINK_ABI_DEPENDS.gtk2+=	gtk2+>=2.24.33nb5
BUILDLINK_PKGSRCDIR.gtk2?=	../../x11/gtk2

.include "../../mk/bsd.fast.prefs.mk"

pkgbase := gtk2
.include "../../mk/pkg-build-options.mk"

.include "../../devel/atk/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.if !empty(PKG_BUILD_OPTIONS.gtk2:Mx11)
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXdamage/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXcomposite/buildlink3.mk"
.endif
.endif # GTK2_BUILDLINK3_MK

BUILDLINK_TREE+=	-gtk2
