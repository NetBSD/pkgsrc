# $NetBSD: buildlink3.mk,v 1.39 2008/09/11 09:34:04 dsainty Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GTK2_BUILDLINK3_MK:=	${GTK2_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gtk2
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngtk2}
BUILDLINK_PACKAGES+=	gtk2
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}gtk2

.if !empty(GTK2_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.4.0
BUILDLINK_ABI_DEPENDS.gtk2+=	gtk2+>=2.8.17nb1
BUILDLINK_PKGSRCDIR.gtk2?=	../../x11/gtk2

PRINT_PLIST_AWK+=	/^@dirrm lib\/gtk-2.0$$/ { next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/gtk-2.0\/(engines|filesystems|immodules|loaders|modules)$$/ \
				{ print "@comment in gtk2: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/gtk-2.0\/2.10.0$$/ { next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/gtk-2.0\/2.10.0\/(engines|filesystems|immodules|loaders|modules|printbackends)$$/ \
				{ print "@comment in gtk2: " $$0; next; }
.endif	# GTK2_BUILDLINK3_MK

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

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
