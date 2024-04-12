# $NetBSD: options.mk,v 1.20 2024/04/12 19:40:24 riastradh Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.gtk2
PKG_SUPPORTED_OPTIONS=		cups debug introspection
PKG_OPTIONS_REQUIRED_GROUPS=	gdk-target
PKG_OPTIONS_GROUP.gdk-target=	x11
.if exists(/System/Library/Frameworks/Quartz.framework)
PKG_OPTIONS_GROUP.gdk-target+=	quartz
PKG_SUGGESTED_OPTIONS=		quartz
.else
PKG_SUGGESTED_OPTIONS=		x11
.endif

PKG_SUGGESTED_OPTIONS+=	${${USE_CROSS_COMPILE:tl} == "yes":?:introspection}

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		cups
.if !empty(PKG_OPTIONS:Mcups)
.include "../../print/cups-base/buildlink3.mk"
PLIST.cups=		yes
.else
CONFIGURE_ENV+=		ac_cv_path_CUPS_CONFIG=no
.endif

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug=yes
.endif

PLIST_VARS+=		introspection
.if !empty(PKG_OPTIONS:Mintrospection)
CONFIGURE_ARGS+=	--enable-introspection=yes
PLIST.introspection=	yes
BUILDLINK_DEPMETHOD.gobject-introspection:=	build
BUILDLINK_API_DEPENDS.gobject-introspection+=	gobject-introspection>=0.9.3
.include "../../devel/gobject-introspection/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--enable-introspection=no
.endif

###
### GDK target
###
PLIST_VARS+=		quartz x11
.if !empty(PKG_OPTIONS:Mquartz)
CONFIGURE_ARGS+=	--without-x
CONFIGURE_ARGS+=	--with-gdktarget=quartz
PLIST.quartz=		yes
.else
CONFIGURE_ARGS+=	--with-xinput=xfree
CONFIGURE_ENV+=		ac_cv_header_X11_extensions_Xinerama_h=no
CONFIGURE_ENV+=		ac_cv_lib_Xinerama_XineramaQueryExtension=no
PLIST.x11=		yes

BUILDLINK_API_DEPENDS.Xft2+=	Xft2>=2.1.2nb2

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXdamage/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
BUILDLINK_API_DEPENDS.libXi+=	libXi>=1.3.0
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXcomposite/buildlink3.mk"

.endif
