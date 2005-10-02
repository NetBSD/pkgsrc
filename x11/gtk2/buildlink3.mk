# $NetBSD: buildlink3.mk,v 1.19 2005/10/02 12:19:06 jmmv Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GTK2_BUILDLINK3_MK:=	${GTK2_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gtk2
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngtk2}
BUILDLINK_PACKAGES+=	gtk2

.if !empty(GTK2_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gtk2+=	gtk2+>=2.4.0
BUILDLINK_RECOMMENDED.gtk2+=	gtk2+>=2.8.4
BUILDLINK_PKGSRCDIR.gtk2?=	../../x11/gtk2

PRINT_PLIST_AWK+=	/^@dirrm lib\/gtk-2.0$$/ { next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/gtk-2.0\/(engines|filesystems|immodules|loaders|modules)$$/ \
				{ print "@comment in gtk2: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/gtk-2.0\/2.4.0$$/ { next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/gtk-2.0\/2.4.0\/(engines|filesystems|immodules|loaders|modules)$$/ \
				{ print "@comment in gtk2: " $$0; next; }
.endif	# GTK2_BUILDLINK3_MK

.include "../../devel/atk/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../fonts/freetype/buildlink3.mk"
.include "../../fonts/Xft2/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/xcursor/buildlink3.mk"
.include "../../x11/Xrandr/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
