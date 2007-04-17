# $NetBSD: Makefile,v 1.3 2007/04/17 21:54:35 drochner Exp $
#

DISTNAME=	compiz-0.4.0
CATEGORIES=	wm x11
MASTER_SITES=	http://xorg.freedesktop.org/releases/individual/app/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.go-compiz.org/
COMMENT=	Compositing window manager

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config msgfmt
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes

GCONF2_SCHEMAS+=	gwd.schemas
GCONF2_SCHEMAS+=	compiz.schemas
PKGCONFIG_OVERRIDE+=	compiz.pc.in
PKGCONFIG_OVERRIDE+=	libdecoration/libdecoration.pc.in

CONFIGURE_ARGS+=	--disable-inotify

PKG_SUPPORTED_OPTIONS=	gnome kde
PKG_OPTIONS_VAR=	PKG_OPTIONS.compiz

.include "../../mk/bsd.options.mk"

# this is as much as needed for the basic window decorator
.include "../../graphics/cairo/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/libwnck/buildlink3.mk"

.if !empty(PKG_OPTIONS:Mgnome)
CONFIGURE_ARGS+=	--enable-librsvg
PLIST_SUBST+=		GNOME=""
.include "../../x11/gnome2-control-center/buildlink3.mk"
.include "../../wm/metacity/buildlink3.mk"
.include "../../graphics/librsvg2/buildlink3.mk"
.else
PLIST_SUBST+=		GNOME="@comment "
.endif

.if !empty(PKG_OPTIONS:Mkde)
PLIST_SUBST+=		KDE=""
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../sysutils/dbus-qt3/buildlink3.mk"
.else
PLIST_SUBST+=		KDE="@comment "
.endif

.include "../../devel/GConf2/schemas.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/libXcomposite/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../x11/libXdamage/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
