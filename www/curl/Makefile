# $NetBSD: Makefile,v 1.6 2001/09/20 11:33:47 itojun Exp $

DISTNAME=	curl-7.8.1
CATEGORIES=	www
MASTER_SITES=	http://curl.haxx.se/download/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://curl.haxx.se/
COMMENT=	client that groks URLs

USE_BUILDLINK_ONLY=	yes
REPLACE_BUILDLINK=	curl-config

GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
CONFIGURE_ARGS+=	--with-ssl=${BUILDLINK_DIR}

.include "../../security/openssl/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
