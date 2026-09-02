# $NetBSD: Makefile,v 1.2 2026/09/02 19:04:56 wiz Exp $

DISTNAME=	${GITHUB_PROJECT}-4.2.0
PKGNAME=	${DISTNAME:S/mod/${APACHE_PKG_PREFIX}/:S/_/-/g}
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=OpenIDC/}
GITHUB_PROJECT=	mod_oauth2
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

HOMEPAGE=	https://github.com/OpenIDC/mod_oauth2
COMMENT=	OAuth 2.x Resource Server module for the Apache HTTPd web server
LICENSE=	apache-2.0

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-apxs=${APXS}
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config

APACHE_MODULE=		yes

INSTALLATION_DIRS+=	lib/httpd

do-install:
	${INSTALL_LIB} ${WRKSRC}/.libs/mod_oauth2.so ${DESTDIR}${PREFIX}/lib/httpd

.include "../../mk/apache.mk"
.include "../../security/liboauth2-apache/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
