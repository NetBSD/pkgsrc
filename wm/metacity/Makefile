# $NetBSD: Makefile,v 1.9 2003/05/17 06:09:30 salo Exp $
#

DISTNAME=	metacity-2.4.34
PKGREVISION=	1
CATEGORIES=	wm x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/metacity/2.4/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnome.org/softwaremap/projects/Metacity
COMMENT=	gnome-compliant window manager

BUILD_USES_MSGFMT=	YES
DEPENDS=		gnome2-dirs>=1.0:../../misc/gnome2-dirs

USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES
USE_X11=		YES
USE_GMAKE=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

CONFIGURE_ARGS=		--without-included-gettext

GCONF2_SCHEMAS=		metacity.schemas

.include "../../devel/GConf2/schemas.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/libglade2/buildlink2.mk"
.include "../../net/ORBit2/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
