# $NetBSD: Makefile,v 1.16 2003/12/13 00:45:26 wiz Exp $
#

DISTNAME=	metacity-2.4.55
PKGREVISION=	2
CATEGORIES=	wm x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/metacity/2.4/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnome.org/softwaremap/projects/Metacity
COMMENT=	GNOME-compliant window manager

BUILD_USES_MSGFMT=	YES
DEPENDS=		gnome2-dirs>=1.0:../../misc/gnome2-dirs

USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES
USE_X11=		YES
USE_GMAKE=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

GCONF2_SCHEMAS=		metacity.schemas

.include "../../devel/GConf2/schemas.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/libglade2/buildlink2.mk"
.include "../../net/ORBit2/buildlink2.mk"
.include "../../x11/startup-notification/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
