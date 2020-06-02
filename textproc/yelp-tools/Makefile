# $NetBSD: Makefile,v 1.4 2020/06/02 08:24:53 adam Exp $

DISTNAME=	yelp-tools-3.32.0
PKGREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=GNOME/}

MAINTAINER=	pkgsrc.gnome@gmail.com
HOMEPAGE=	https://www.gnome.org/
COMMENT=	Set of command-line tools to build and check your documentation
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config autoreconf autoconf automake gmake

pre-configure:
	${RUN} cd ${WRKSRC} && \
	${SETENV} ${CONFIGURE_ENV} ${SH} ./autogen.sh NOCONFIGURE=1

DEPENDS+=	itstool-[0-9]*:../../textproc/itstool

.include "../../lang/python/application.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../textproc/yelp-xsl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
