# $NetBSD: Makefile,v 1.24 2004/02/14 17:21:53 jlam Exp $
#

DISTNAME=	metacity-2.6.3
PKGREVISION=	3
CATEGORIES=	wm x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/metacity/2.6/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnome.org/softwaremap/projects/Metacity/
COMMENT=	GNOME-compliant window manager

BUILD_USES_MSGFMT=	YES
DEPENDS=		gnome2-dirs>=1.0:../../misc/gnome2-dirs

USE_BUILDLINK3=		YES
USE_PKGLOCALEDIR=	YES
USE_X11=		YES
USE_GNU_TOOLS+=		make
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

PKGCONFIG_OVERRIDE=	${WRKSRC}/src/libmetacity-private.pc.in

GCONF2_SCHEMAS=		metacity.schemas

.include "../../mk/bsd.prefs.mk"

.if exists(${X11BASE}/lib/libXinerama.so)
CONFIGURE_ENV+=		USE_XINERAMA=yes
.else
CONFIGURE_ENV+=		USE_XINERAMA=no
.endif

.include "../../devel/GConf2/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../net/ORBit2/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
