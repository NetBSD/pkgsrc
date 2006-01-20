# $NetBSD: Makefile,v 1.51 2006/01/20 13:31:45 jmmv Exp $
#

DISTNAME=	metacity-2.12.2
CATEGORIES=	wm x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/metacity/2.12/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnome.org/softwaremap/projects/Metacity/
COMMENT=	GNOME-compliant window manager

BUILD_USES_MSGFMT=	YES

USE_DIRS+=		gnome2-1.5 theme-1.0
USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

PKGCONFIG_OVERRIDE=	src/libmetacity-private.pc.in

GCONF2_SCHEMAS=		metacity.schemas

.include "../../mk/bsd.prefs.mk"

.if !exists(${X11BASE}/lib/libXinerama.so)
CONFIGURE_ARGS+=	--disable-xinerama
.endif

.include "../../devel/GConf2/schemas.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../x11/xcursor/buildlink3.mk"
.include "../../x11/Xcomposite/buildlink3.mk"
.include "../../x11/Xrender/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
