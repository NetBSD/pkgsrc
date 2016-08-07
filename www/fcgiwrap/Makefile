# $NetBSD: Makefile,v 1.1 2016/08/07 18:01:29 nils Exp $

DISTNAME=	fcgiwrap-1.1.0
CATEGORIES=	www

COMMENT=	FastCGI wrapper for plain CGI scripts
LICENSE=	mit

GITHUB_TAG=	${PKGVERSION_NOREV}
MASTER_SITES=	${MASTER_SITE_GITHUB:=gnosek/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://nginx.localdomain.pl/wiki/FcgiWrap


GNU_CONFIGURE=	yes
USE_TOOLS+=	automake autoreconf pkg-config

LDFLAGS.SunOS+=	-lsocket -lnsl

pre-configure:
	cd ${WRKSRC} && autoreconf -i

.include "../../www/fcgi/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
