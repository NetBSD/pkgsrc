# $NetBSD: Makefile,v 1.39 2005/02/20 10:19:06 jmmv Exp $
#

DISTNAME=	metacity-2.8.13
CATEGORIES=	wm x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/metacity/2.8/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnome.org/softwaremap/projects/Metacity/
COMMENT=	GNOME-compliant window manager

BUILD_USES_MSGFMT=	YES

USE_BUILDLINK3=		YES
USE_DIRS+=		gnome2-1.5 theme-1.0
USE_PKGLOCALEDIR=	YES
USE_X11=		YES
USE_GNU_TOOLS+=		make
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

PKGCONFIG_OVERRIDE=	src/libmetacity-private.pc.in

GCONF2_SCHEMAS=		metacity.schemas

.include "../../mk/bsd.prefs.mk"

.if !exists(${X11BASE}/lib/libXinerama.so)
CONFIGURE_ARGS+=	--disable-xinerama
.endif

.include "../../devel/GConf2/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../net/ORBit2/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
