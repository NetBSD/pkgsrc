# $NetBSD: Makefile,v 1.16 2003/02/18 00:34:43 grant Exp $

DISTNAME=	AuthPG-1.2b2
PKGNAME=	ap-auth-postgresql-1.2b2
PKGREVISION=	1
CATEGORIES=	www databases
MASTER_SITES=	http://home.bawi.org/~minskim/authpg/

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://home.bawi.org/~minskim/authpg/
COMMENT=	Module to allow apache authentication against a Postgresql database

USE_BUILDLINK2=	YES

APACHE_MODULE_NAME=	mod_auth_pg.so

CPPFLAGS+=	-I${BUILDLINK_PREFIX.postgresql-lib}/include/postgresql
LDFLAGS+=	-lpq -lcrypt

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mod_auth_pg
	${INSTALL_DATA} ${WRKSRC}/mod_auth_pg.html ${PREFIX}/share/doc/mod_auth_pg
	${INSTALL_DATA} ${WRKSRC}/mod_auth_pg.ko.html ${PREFIX}/share/doc/mod_auth_pg
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/mod_auth_pg
	${INSTALL_DATA} ${WRKSRC}/README.ko ${PREFIX}/share/doc/mod_auth_pg
	${INSTALL_DATA} ${WRKSRC}/sample.htaccess ${PREFIX}/share/examples/mod_auth_pg.htaccess

.include "../../databases/postgresql-lib/buildlink2.mk"
.include "../../www/apache/module.mk"
.include "../../mk/bsd.pkg.mk"
