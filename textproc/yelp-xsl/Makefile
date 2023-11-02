# $NetBSD: Makefile,v 1.23 2023/11/02 10:23:35 wiz Exp $

DISTNAME=	yelp-xsl-42.1
CATEGORIES=	textproc gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/yelp-xsl/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	prlw1@cam.ac.uk
HOMEPAGE=	https://www.gnome.org/
COMMENT=	XSL stylesheets for Yelp help browser
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1 AND mit

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config intltool msgfmt itstool
USE_PKGLOCALEDIR=	yes
PYTHON_FOR_BUILD_ONLY=	tool

PKGCONFIG_OVERRIDE+=	yelp-xsl.pc.in

.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
