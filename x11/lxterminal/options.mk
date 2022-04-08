# $NetBSD: options.mk,v 1.1 2022/04/08 22:31:47 gutteridge Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.lxterminal
PKG_OPTIONS_REQUIRED_GROUPS+=	toolkit
PKG_OPTIONS_GROUP.toolkit=	gtk2 gtk3
PKG_SUGGESTED_OPTIONS=		gtk2

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgtk3)
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/vte029/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-gtk3
.else
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/vte/buildlink3.mk"
# No CONFIGURE_ARGS needed, it's the default
.endif
