# $NetBSD: options.mk,v 1.7 2026/05/07 21:14:49 markd Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.compiz
PKG_SUPPORTED_OPTIONS=	fuse inotify
PLIST_VARS+=		inotify

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
