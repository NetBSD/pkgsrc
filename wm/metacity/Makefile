# $NetBSD: Makefile,v 1.75 2008/01/11 12:55:59 drochner Exp $
#

DISTNAME=	metacity-2.20.2
CATEGORIES=	wm x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/metacity/2.20/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnome.org/softwaremap/projects/Metacity/
COMMENT=	GNOME-compliant window manager

USE_DIRS+=		gnome2-1.5 theme-1.0 xdg-1.4
USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		gmake intltool msgfmt pkg-config
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

PKGCONFIG_OVERRIDE=	src/libmetacity-private.pc.in

GCONF_SCHEMAS=		metacity.schemas

.include "../../mk/bsd.prefs.mk"

.if ${X11_TYPE} != "native"
.include "../../x11/libXinerama/buildlink3.mk"
.elif !exists(${X11BASE}/lib/libXinerama.so)
CONFIGURE_ARGS+=	--disable-xinerama
.endif

BUILDLINK_API_DEPENDS.glib2+=			glib2>=2.6.0
BUILDLINK_API_DEPENDS.gtk2+=			gtk2+>=2.10.0
BUILDLINK_API_DEPENDS.startup-notification+=	startup-notification>=0.7

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../devel/GConf/schemas.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libXcomposite/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
