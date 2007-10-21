# $NetBSD: options.mk,v 1.7 2007/10/21 01:18:36 obache Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gtk2
PKG_SUPPORTED_OPTIONS=	cups debug
PKG_OPTIONS_REQUIRED_GROUPS=	gdk-target
PKG_OPTIONS_GROUP.gdk-target=	x11
.if exists(/System/Library/Frameworks/Quartz.framework)
PKG_OPTIONS_GROUP.gdk-target+=	quartz
.endif
PKG_SUGGESTED_OPTIONS=		x11

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mcups)
.include "../../print/cups/buildlink3.mk"
PLIST_SUBST+=		CUPS=
.else
PLIST_SUBST+=		CUPS="@comment "
CONFIGURE_ENV+=		ac_cv_path_CUPS_CONFIG=no
.endif

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug=yes
.endif

###
### GDK target
###
.if !empty(PKG_OPTIONS:Mquartz)
CONFIGURE_ARGS+=	--without-x
CONFIGURE_ARGS+=	--with-gdktarget=quartz
PLIST_SUBST+=		QUARTZ=""
PLIST_SUBST+=		X11="@comment "
.else
CONFIGURE_ARGS+=	--with-xinput=xfree
CONFIGURE_ENV+=		ac_cv_header_X11_extensions_Xinerama_h=no
CONFIGURE_ENV+=		ac_cv_lib_Xinerama_XineramaQueryExtension=no
PLIST_SUBST+=		QUARTZ="@comment "
PLIST_SUBST+=		X11=""

BUILDLINK_API_DEPENDS.Xft2+=	Xft2>=2.1.2nb2

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"

.endif
