# $NetBSD: options.mk,v 1.3 2013/07/17 08:39:59 jperkin Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.compiz
PKG_SUPPORTED_OPTIONS=	fuse gnome inotify kde3 kde4
PLIST_VARS+=		gnome inotify kde kde3

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "SunOS"
PKG_SUGGESTED_OPTIONS+=	inotify
.endif

.include "../../mk/bsd.options.mk"

# XXX configure needs fuse.pc, which isn't in NetBSD's base for some reason
.if !empty(PKG_OPTIONS:Mfuse)
.include "../../filesystems/fuse/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-fuse
.else
CONFIGURE_ARGS+=	--disable-fuse
.endif

.if !empty(PKG_OPTIONS:Mgnome)
CONFIGURE_ARGS+=	--enable-librsvg
PLIST.gnome=		yes
BUILDLINK_DEPMETHOD.gnome-desktop=	build
.include "../../x11/gnome-desktop/buildlink3.mk"
BUILDLINK_DEPMETHOD.gnome-control-center=	build
.include "../../x11/gnome-control-center/buildlink3.mk"
BUILDLINK_DEPMETHOD.metacity=	build
.include "../../wm/metacity/buildlink3.mk"
BUILDLINK_DEPMETHOD.librsvg=	build
.include "../../graphics/librsvg/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-gnome --disable-gnome-keybindings
.endif

.if !empty(PKG_OPTIONS:Minotify)
.include "../../devel/libinotify/buildlink3.mk"
PLIST.inotify=		yes
.else
CONFIGURE_ARGS+=	--disable-inotify
.endif

.if !empty(PKG_OPTIONS:Mkde3)
# XXX This option is broken on NetBSD 6.0.1/amd64 + pkgsrc-current
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../sysutils/dbus-qt3/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-kconfig
PLIST.kde=		yes
PLIST.kde3=		yes
.else
CONFIGURE_ARGS+=	--disable-kde --disable-kconfig
.endif

.if !empty(PKG_OPTIONS:Mkde4)
# XXX This option is broken on NetBSD 6.0.1/amd64 + pkgsrc-current
.include "../../x11/kde-workspace4/buildlink3.mk"
# XXX Test to see which PLIST entries are KDE{3,4}-specific, besides kconfig.
PLIST.kde=		yes
#PLIST.kde4=		yes
.else
CONFIGURE_ARGS+=	--disable-kde4
.endif
