# $NetBSD: Makefile,v 1.14 2001/11/26 15:02:30 jlam Exp $

DISTNAME=	auth_ldap-1.6.0
PKGNAME=	ap-auth-ldap-1.6.0
SVR4_PKGNAME=	apldap
CATEGORIES=	www databases
MASTER_SITES=	http://www.rudedog.org/auth_ldap/

MAINTAINER=	kleink@netbsd.org
HOMEPAGE=	http://www.rudedog.org/auth_ldap/
COMMENT=	Module to allow apache authentication against an LDAP directory

DEPENDS+=	${BUILDLINK_DEPENDS.apache}:../../www/apache

do-build:
	@cd ${WRKSRC} && ${APXS} -c					\
	    -D WITH_OPENLDAP						\
	    -I ${BUILDLINK_DIR}/include					\
	    -L ${BUILDLINK_DIR}/lib -Wl,-R${LOCALBASE}/lib -lldap -llber \
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

.include "../../databases/openldap/buildlink.mk"
.include "../../www/apache/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
