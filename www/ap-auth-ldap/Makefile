# $NetBSD: Makefile,v 1.17 2003/05/02 11:56:39 wiz Exp $

DISTNAME=	auth_ldap-1.6.0
PKGREVISION=	1
PKGNAME=	ap-auth-ldap-1.6.0
SVR4_PKGNAME=	apldap
CATEGORIES=	www databases
MASTER_SITES=	http://www.rudedog.org/auth_ldap/

MAINTAINER=	kleink@netbsd.org
HOMEPAGE=	http://www.rudedog.org/auth_ldap/
COMMENT=	Module to allow apache authentication against an LDAP directory

USE_BUILDLINK2=	# defined

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

BUILDLINK_DEPMETHOD.apache=	full

.include "../../databases/openldap/buildlink2.mk"
.include "../../www/apache/module.mk"

.include "../../mk/bsd.pkg.mk"
