# $NetBSD: options.mk,v 1.6 2021/03/30 14:45:36 cirnatdan Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.compiz
PKG_SUPPORTED_OPTIONS=	fuse inotify kde4
PLIST_VARS+=		inotify kde

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Linux" && ${OPSYS} != "SunOS"
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

.if !empty(PKG_OPTIONS:Minotify)
.include "../../devel/libinotify/buildlink3.mk"
PLIST.inotify=		yes
.else
CONFIGURE_ARGS+=	--disable-inotify
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
