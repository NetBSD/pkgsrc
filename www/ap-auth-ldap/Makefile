# $NetBSD: Makefile,v 1.31 2008/01/18 05:09:47 tnn Exp $

DISTNAME=	auth_ldap-1.6.1
PKGNAME=	ap13-auth-ldap-1.6.1
PKGREVISION=	1
SVR4_PKGNAME=	apldap
CATEGORIES=	www databases
MASTER_SITES=	http://www.rudedog.org/auth_ldap/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rudedog.org/auth_ldap/
COMMENT=	Module to allow apache authentication against an LDAP directory

CONFLICTS=	ap-auth-ldap-[0-9]*

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

.include "../../databases/openldap-client/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
