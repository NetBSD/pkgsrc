# $NetBSD: Makefile,v 1.7 2014/06/11 12:57:23 joerg Exp $
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

APACHE_MODULE_NAME=	mod_authnz_external.${MODULE_EXT}

DISTVERS=	3.2.3
MODULE_EXT=	la
MESSAGE_SUBST+=	MODULE_NAME=authnz_external_module

INSTALLATION_DIRS+=	share/doc/authnz-external

post-install:
	${INSTALL_DATA} ${WRKSRC}/AUTHENTICATORS \
		${DESTDIR}${PREFIX}/share/doc/authnz-external
	${INSTALL_DATA} ${WRKSRC}/INSTALL \
		${DESTDIR}${PREFIX}/share/doc/authnz-external
	${INSTALL_DATA} ${WRKSRC}/INSTALL.HARDCODE \
		${DESTDIR}${PREFIX}/share/doc/authnz-external
	${INSTALL_DATA} ${WRKSRC}/TODO \
		${DESTDIR}${PREFIX}/share/doc/authnz-external
	${INSTALL_DATA} ${WRKSRC}/UPGRADE \
		${DESTDIR}${PREFIX}/share/doc/authnz-external

.include "../../mk/apache.module.mk"
.include "../../mk/bsd.pkg.mk"
