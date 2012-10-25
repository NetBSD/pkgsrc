# $NetBSD: Makefile,v 1.4 2012/10/25 06:57:09 asau Exp $
#

DISTNAME=	yelp-xsl-3.4.2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/yelp-xsl/3.4/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	prlw1@cam.ac.uk
HOMEPAGE=	http://www.gnome.org/
COMMENT=	XSL stylesheets for Yelp help browser
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1 AND mit

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config intltool msgfmt
USE_PKGLOCALEDIR=	yes

PKGCONFIG_OVERRIDE+=	yelp-xsl.pc.in

BUILD_DEPENDS+=	itstool-[0-9]*:../../textproc/itstool
DEPENDS+=	libxml2>=2.6.12:../../textproc/libxml2
DEPENDS+=	libxslt>=1.1.8:../../textproc/libxslt
.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
