# $NetBSD: Makefile,v 1.9 2001/11/12 12:27:30 seb Exp $

DISTNAME=	curl-7.9.1
CATEGORIES=	www
MASTER_SITES=	http://curl.haxx.se/download/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://curl.haxx.se/
COMMENT=	client that groks URLs

USE_BUILDLINK_ONLY=	yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
CONFIGURE_ARGS+=	--with-ssl=${BUILDLINK_DIR}

.include "../../security/openssl/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
