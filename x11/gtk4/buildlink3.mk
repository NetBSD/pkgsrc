# $NetBSD: buildlink3.mk,v 1.7 2023/01/29 21:15:07 ryoon Exp $

BUILDLINK_TREE+=	gtk4

.if !defined(GTK4_BUILDLINK3_MK)
GTK4_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gtk4+=	gtk4>=4.0.3
BUILDLINK_ABI_DEPENDS.gtk4+=	gtk4>=4.8.3nb1
BUILDLINK_PKGSRCDIR.gtk4?=	../../x11/gtk4

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/cairo-gobject/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../graphics/graphene/buildlink3.mk"
.include "../../graphics/libepoxy/buildlink3.mk"

pkgbase := gtk4
.include "../../mk/pkg-build-options.mk"

.if ${PKG_BUILD_OPTIONS.gtk4:Mx11}
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.endif

.endif	# GTK4_BUILDLINK3_MK

BUILDLINK_TREE+=	-gtk4
