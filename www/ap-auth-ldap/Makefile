# $NetBSD: Makefile,v 1.10 2001/05/20 05:23:26 jonb Exp $

DISTNAME=	auth_ldap-1.5.2
PKGNAME=	ap-auth-ldap-1.5.2
CATEGORIES=	www databases
MASTER_SITES=	http://www.rudedog.org/auth_ldap/

MAINTAINER=	kleink@netbsd.org
HOMEPAGE=	http://www.rudedog.org/auth_ldap/
COMMENT=	Module to allow apache authentication against an LDAP directory

DEPENDS+=	apache{,6}-1.3.*:../../www/apache
DEPENDS+=	openldap-1.2.*:../../databases/openldap

# For "apxs":
BUILD_DEPENDS=	perl>=${PERL5_REQD}:../../lang/perl5

do-build:
	@cd ${WRKSRC} && ${LOCALBASE}/sbin/apxs -c			\
	    -D WITH_OPENLDAP						\
	    -I ${LOCALBASE}/include					\
	    -L ${LOCALBASE}/lib -Wl,-R${LOCALBASE}/lib -lldap -llber	\
	    auth_ldap.c auth_ldap_cache.c auth_ldap_cache_mgr.c		\
	    auth_ldap_config.c

do-install:
	@cd ${WRKSRC} && ${PREFIX}/sbin/apxs -i auth_ldap.so
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mod_auth_ldap
	${INSTALL_DATA} ${WRKSRC}/FAQ.html				\
	    ${PREFIX}/share/doc/mod_auth_ldap
	${INSTALL_DATA} ${WRKSRC}/auth_ldap.html			\
	    ${PREFIX}/share/doc/mod_auth_ldap
	${INSTALL_DATA} ${WRKSRC}/future-directions.html		\
	    ${PREFIX}/share/doc/mod_auth_ldap

.include "../../mk/bsd.pkg.mk"
