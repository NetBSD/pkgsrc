# $NetBSD: Makefile,v 1.2 2001/02/17 17:22:03 wiz Exp $

DISTNAME=	curl-7.6
CATEGORIES=	www
MASTER_SITES=	http://curl.haxx.se/download/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://curl.haxx.se/
COMMENT=	client that groks URLs

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
USE_SSL=	yes

.include "../../mk/bsd.pkg.mk"
