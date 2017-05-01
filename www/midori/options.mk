# $NetBSD: options.mk,v 1.1.12.1 2017/05/01 09:02:16 bsiegert Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.midori

PKG_OPTIONS_REQUIRED_GROUPS=	gtk
PKG_OPTIONS_GROUP.gtk=		gtk2 gtk3

PKG_SUGGESTED_OPTIONS=		gtk2

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgtk2)
.include "../../www/webkit24-gtk/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mgtk3)
CONFIGURE_ARGS+=	--enable-gtk3
CMAKE_ARGS+=		-DUSE_GTK3=1
.include "../../www/webkit24-gtk3/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.endif
