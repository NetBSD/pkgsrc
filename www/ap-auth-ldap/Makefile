# $NetBSD: Makefile,v 1.1.1.1 2000/05/30 13:58:49 kleink Exp $

DISTNAME=	auth_ldap-1.4.2
PKGNAME=	ap-auth-ldap-1.4.2
CATEGORIES=	www databases
MASTER_SITES=	http://www.rudedog.org/auth_ldap/

MAINTAINER=	kleink@netbsd.org
HOMEPAGE=	http://www.rudedog.org/auth_ldap/

DEPENDS+=	apache-1.3.*:../../www/apache
DEPENDS+=	openldap-1.2.7p1:../../databases/openldap

# For "apxs":
BUILD_DEPENDS=	${LOCALBASE}/bin/perl:../../lang/perl5

do-build:
	@cd ${WRKSRC} && ${LOCALBASE}/sbin/apxs -c			\
	    -D WITH_OPENLDAP						\
	    -I ${LOCALBASE}/include					\
	    -L ${LOCALBASE}/lib -Wl,-R${LOCALBASE}/lib -lldap -llber	\
	    auth_ldap.c auth_ldap_cache.c auth_ldap_config.c

do-install:
	@cd ${WRKSRC} && ${PREFIX}/sbin/apxs -i auth_ldap.so
	-${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mod_auth_ldap
	${INSTALL_DATA} ${WRKSRC}/auth_ldap.html			\
	    ${PREFIX}/share/doc/mod_auth_ldap
	${INSTALL_DATA} ${WRKSRC}/future-directions.html		\
	    ${PREFIX}/share/doc/mod_auth_ldap

.include "../../mk/bsd.pkg.mk"
