# $NetBSD: Makefile,v 1.62 2006/09/15 15:11:34 jmmv Exp $
#

DISTNAME=	metacity-2.16.0
CATEGORIES=	wm x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/metacity/2.16/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnome.org/softwaremap/projects/Metacity/
COMMENT=	GNOME-compliant window manager

USE_DIRS+=		gnome2-1.5 theme-1.0
USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		gmake intltool msgfmt pkg-config
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

PKGCONFIG_OVERRIDE=	src/libmetacity-private.pc.in

GCONF2_SCHEMAS=		metacity.schemas

.include "../../mk/bsd.prefs.mk"

.if !exists(${X11BASE}/lib/libXinerama.so)
CONFIGURE_ARGS+=	--disable-xinerama
.endif

BUILDLINK_API_DEPENDS.glib2+=			glib2>=2.6.0
BUILDLINK_API_DEPENDS.gtk2+=			gtk2+>=2.10.0
BUILDLINK_API_DEPENDS.startup-notification+=	startup-notification>=0.7

.include "../../devel/GConf2/schemas.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../x11/xcursor/buildlink3.mk"
.include "../../x11/Xcomposite/buildlink3.mk"
.include "../../x11/Xrender/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
