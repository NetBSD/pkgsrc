# $NetBSD: Makefile,v 1.4 2009/12/24 13:18:31 sborrill Exp $
#

DISTNAME=	mod_authnz_external-${DISTVERS}
PKGNAME=	${APACHE_PKG_PREFIX}-authnz-external-${DISTVERS}
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://mod-auth-external.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/mod-auth-external/
COMMENT=	Apache module for external program authentication

PKG_APACHE_ACCEPTED=	apache22

.include "../../mk/apache.mk"

APACHE_MODULE_NAME=	mod_authnz_external.${MODULE_EXT}

DISTVERS=	3.2.3
MODULE_EXT=	la
MESSAGE_SUBST+=	MODULE_NAME=authnz_external_module

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/authnz-external
	${INSTALL_DATA} ${WRKSRC}/AUTHENTICATORS \
		${PREFIX}/share/doc/authnz-external
	${INSTALL_DATA} ${WRKSRC}/INSTALL \
		${PREFIX}/share/doc/authnz-external
	${INSTALL_DATA} ${WRKSRC}/INSTALL.HARDCODE \
		${PREFIX}/share/doc/authnz-external
	${INSTALL_DATA} ${WRKSRC}/TODO \
		${PREFIX}/share/doc/authnz-external
	${INSTALL_DATA} ${WRKSRC}/UPGRADE \
		${PREFIX}/share/doc/authnz-external

.include "../../www/apache/module.mk"
.include "../../mk/bsd.pkg.mk"
