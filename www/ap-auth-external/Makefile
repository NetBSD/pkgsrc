# $NetBSD: Makefile,v 1.8 2010/02/12 21:01:27 joerg Exp $
#

DISTNAME=	mod_auth_external-${DISTVERS}
PKGREVISION=	2
PKGNAME=	${APACHE_PKG_PREFIX}-auth-external-${DISTVERS}
CATEGORIES=	www
MASTER_SITES=	http://mod-auth-external.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/mod-auth-external/
COMMENT=	Apache module for external program authentication

PKG_DESTDIR_SUPPORT=	user-destdir

PKG_APACHE_ACCEPTED=	apache13

.include "../../mk/apache.mk"

APACHE_MODULE_NAME=	mod_auth_external.${MODULE_EXT}

DISTVERS=	2.1.19
MODULE_EXT=	so
MESSAGE_SUBST+=	MODULE_NAME=external_auth_module

INSTALLATION_DIRS+=	lib/httpd

do-install:
	${INSTALL_LIB} ${WRKSRC}/mod_auth_external.so \
	    ${DESTDIR}${PREFIX}/lib/httpd

.include "../../www/apache/module.mk"
.include "../../mk/bsd.pkg.mk"
