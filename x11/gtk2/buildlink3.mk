# $NetBSD: buildlink3.mk,v 1.41 2009/06/14 22:58:11 joerg Exp $

BUILDLINK_TREE+=	gtk2

.if !defined(GTK2_BUILDLINK3_MK)
GTK2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.4.0
BUILDLINK_ABI_DEPENDS.gtk2+=	gtk2+>=2.8.17nb1
BUILDLINK_PKGSRCDIR.gtk2?=	../../x11/gtk2

.include "../../mk/bsd.fast.prefs.mk"

pkgbase := gtk2
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.gtk2:Mx11)
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.gtk2:Mcups)
.include "../../print/cups/buildlink3.mk"
.endif

.include "../../devel/atk/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.endif # GTK2_BUILDLINK3_MK

BUILDLINK_TREE+=	-gtk2
