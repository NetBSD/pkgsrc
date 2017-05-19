# $NetBSD: options.mk,v 1.9 2017/05/19 13:18:19 prlw1 Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gtk3
PKG_SUPPORTED_OPTIONS=	gtk3-atk-bridge cups debug
PKG_OPTIONS_REQUIRED_GROUPS=	gdk-target
PKG_OPTIONS_GROUP.gdk-target=	x11
.if exists(/System/Library/Frameworks/Quartz.framework)
PKG_OPTIONS_GROUP.gdk-target+=	quartz
.endif
PKG_SUGGESTED_OPTIONS=		gtk3-atk-bridge x11

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		cups
.if !empty(PKG_OPTIONS:Mcups)
.include "../../print/cups/buildlink3.mk"
PLIST.cups=		yes
.else
CONFIGURE_ENV+=		ac_cv_path_CUPS_CONFIG=no
.endif

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug=yes
.endif

###
### GDK target
###
PLIST_VARS+=		quartz x11
.if !empty(PKG_OPTIONS:Mquartz)
CONFIGURE_ARGS+=	--without-x
CONFIGURE_ARGS+=	--enable-quartz-backend
PLIST.quartz=		yes
.else
CONFIGURE_ENV+=		ac_cv_header_X11_extensions_Xinerama_h=no
CONFIGURE_ENV+=		ac_cv_lib_Xinerama_XineramaQueryExtension=no
PLIST.x11=		yes

.  if !empty(PKG_OPTIONS:Mgtk3-atk-bridge)
BUILDLINK_API_DEPENDS.at-spi2-atk+=	at-spi2-atk>=2.6.1
.    include "../../devel/at-spi2-atk/buildlink3.mk"
.  else
CONFIGURE_ARGS+=	--without-atk-bridge
.  endif

BUILDLINK_API_DEPENDS.Xft2+=	Xft2>=2.1.2nb2
BUILDLINK_API_DEPENDS.inputproto+=	inputproto>=2.0

.include "../../x11/inputproto/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXcomposite/buildlink3.mk"

.endif
