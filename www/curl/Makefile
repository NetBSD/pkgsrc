# $NetBSD: Makefile,v 1.7 2001/09/29 15:42:24 seb Exp $

DISTNAME=	curl-7.9
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
