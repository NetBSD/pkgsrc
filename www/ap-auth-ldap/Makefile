# $NetBSD: Makefile,v 1.26 2006/02/05 23:11:16 joerg Exp $

DISTNAME=	auth_ldap-1.6.1
PKGNAME=	ap-auth-ldap-1.6.1
PKGREVISION=	2
SVR4_PKGNAME=	apldap
CATEGORIES=	www databases
MASTER_SITES=	http://www.rudedog.org/auth_ldap/

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	http://www.rudedog.org/auth_ldap/
COMMENT=	Module to allow apache authentication against an LDAP directory


APACHE_MODULE_NAME=	auth_ldap.so
CPPFLAGS+=		-DWITH_OPENLDAP
LDFLAGS+=		-lldap -llber

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mod_auth_ldap
	${INSTALL_DATA} ${WRKSRC}/FAQ.html				\
		${PREFIX}/share/doc/mod_auth_ldap
	${INSTALL_DATA} ${WRKSRC}/auth_ldap.html			\
		${PREFIX}/share/doc/mod_auth_ldap
	${INSTALL_DATA} ${WRKSRC}/future-directions.html		\
		${PREFIX}/share/doc/mod_auth_ldap

.include "../../www/apache/module.mk"

.include "../../databases/openldap/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
