# $NetBSD: options.mk,v 1.2 2018/12/13 21:21:55 adam Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.wxGTK30
PKG_OPTIONS_REQUIRED_GROUPS=	gtk
PKG_OPTIONS_GROUP.gtk=		gtk2 gtk3
PKG_SUGGESTED_OPTIONS=		gtk3

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgtk2)
PLIST_SRC+=		PLIST.gtk2
CONFIGURE_ARGS+=	--with-gtk=2
.include "../../x11/gtk2/buildlink3.mk"
.else
PLIST_SRC+=		PLIST.gtk3
CONFIGURE_ARGS+=	--with-gtk=3
.include "../../x11/gtk3/buildlink3.mk"
.endif
