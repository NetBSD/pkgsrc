# $NetBSD: Makefile,v 1.3 2009/03/01 01:28:17 adrianp Exp $
#

DISTNAME=	mod_authnz_external-${DISTVERS}
PKGNAME=	${APACHE_PKG_PREFIX}-authnz-external-${DISTVERS}
CATEGORIES=	www
MASTER_SITES=	http://unixpapa.com/software/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://unixpapa.com/mod_authnz_external/
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
