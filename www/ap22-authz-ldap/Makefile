# $NetBSD: Makefile,v 1.7 2020/05/27 19:37:43 wiz Exp $

DISTNAME=	mod_authz_ldap-0.30
PKGNAME=	${APACHE_PKG_PREFIX}-${DISTNAME:C/^mod_//:C/_/-/}
PKGREVISION=	3
CATEGORIES=	www
MASTER_SITES=	http://authzldap.othello.ch/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://authzldap.othello.ch/
COMMENT=	Apache LDAP Authorization module
LICENSE=	apache-2.0

.include "../../mk/apache.mk"
.include "options.mk"

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

CONFIGURE_ARGS+=	--with-apxs=${APXS:Q}
CONFIGURE_ARGS+=	--with-apr=${PREFIX}/bin/apr-1-config
CONFIGURE_ARGS+=	--with-apu=${PREFIX}/bin/apu-1-config

INSTALLATION_DIRS+=	bin lib/httpd ${PKGMANDIR}/man1

do-install:
	${INSTALL_LIB} ${WRKSRC}/module/.libs/mod_authz_ldap.so \
	  ${DESTDIR}${PREFIX}/lib/httpd
	${INSTALL_PROGRAM} ${WRKSRC}/tools/cert2ldap ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/tools/certfind ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/docs/cert2ldap.1 \
	  ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/docs/certfind.1 \
	  ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../databases/openldap-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
