# $NetBSD: Makefile,v 1.10 2024/05/29 16:34:47 adam Exp $

GITHUB_PROJECT=	mod_auth_openidc
DISTNAME=	${GITHUB_PROJECT}-2.4.8.4
PKGNAME=	${DISTNAME:S/mod/${APACHE_PKG_PREFIX}/:S/_/-/g}
PKGREVISION=	8
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=zmartzone/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

HOMEPAGE=	https://github.com/zmartzone/mod_auth_openidc
COMMENT=	OpenID Connect Relying Party implementation for Apache HTTP Server 2.x
LICENSE=	apache-2.0

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-apxs2=${APXS}
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
USE_TOOLS+=		pkg-config

APACHE_MODULE=		yes

INSTALLATION_DIRS+=	lib/httpd

do-install:
	${INSTALL_LIB} ${WRKSRC}/src/.libs/mod_auth_openidc.so ${DESTDIR}${PREFIX}/lib/httpd

.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/apache.mk"
.include "../../textproc/cjose/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
