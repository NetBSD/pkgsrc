# $NetBSD: Makefile,v 1.15 2002/10/08 23:48:21 jlam Exp $

DISTNAME=	auth_ldap-1.6.0
PKGNAME=	ap-auth-ldap-1.6.0
SVR4_PKGNAME=	apldap
CATEGORIES=	www databases
MASTER_SITES=	http://www.rudedog.org/auth_ldap/

MAINTAINER=	kleink@netbsd.org
HOMEPAGE=	http://www.rudedog.org/auth_ldap/
COMMENT=	Module to allow apache authentication against an LDAP directory

USE_BUILDLINK2=	# defined

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${APXS} -c		\
		-DWITH_OPENLDAP						\
		-I${BUILDLINK_PREFIX.openldap}/include			\
		-L${BUILDLINK_PREFIX.openldap}/lib			\
		-Wl,-R${BUILDLINK_PREFIX.openldap}/lib -lldap -llber	\
		auth_ldap.c auth_ldap_cache.c auth_ldap_cache_mgr.c	\
		auth_ldap_config.c

do-install:
	@cd ${WRKSRC} && ${APXS} -i auth_ldap.so
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mod_auth_ldap
	${INSTALL_DATA} ${WRKSRC}/FAQ.html				\
		${PREFIX}/share/doc/mod_auth_ldap
	${INSTALL_DATA} ${WRKSRC}/auth_ldap.html			\
		${PREFIX}/share/doc/mod_auth_ldap
	${INSTALL_DATA} ${WRKSRC}/future-directions.html		\
		${PREFIX}/share/doc/mod_auth_ldap

BUILDLINK_DEPMETHOD.apache=	full

.include "../../databases/openldap/buildlink2.mk"
.include "../../www/apache/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
