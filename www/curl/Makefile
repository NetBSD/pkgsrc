# $NetBSD: Makefile,v 1.1.1.1 2001/02/05 14:32:21 itojun Exp $

DISTNAME=	curl-7.6
CATEGORIES=	www
MASTER_SITES=	http://curl.haxx.se/download/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://curl.haxx.se/

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
USE_SSL=	yes

.include "../../mk/bsd.pkg.mk"
