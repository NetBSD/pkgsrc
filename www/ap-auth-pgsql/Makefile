# $NetBSD: Makefile,v 1.1.1.1 2003/07/31 19:22:28 wiz Exp $

DISTNAME=	mod_auth_pgsql-0.9.12
PKGNAME=	ap-auth-pgsql-0.9.12
CATEGORIES=	www databases
MASTER_SITES=	http://www.giuseppetanzilli.it/mod_auth_pgsql/dist/

MAINTAINER=	waddell@caravan.com
HOMEPAGE=	http://www.giuseppetanzilli.it/mod_auth_pgsql/
COMMENT=	Module to allow apache log accesses and authenticate against a Postgresql database

CONFLICTS=	ap-auth-postgresql-[0-9]*
USE_BUILDLINK2=	YES

APACHE_MODULE_NAME=	mod_auth_pgsql.so

CPPFLAGS+=	-I${BUILDLINK_PREFIX.postgresql-lib}/include/postgresql
LDFLAGS+=	-lpq -lcrypt

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mod_auth_pgsql
	${INSTALL_DATA} ${WRKSRC}/mod_auth_pgsql.html ${PREFIX}/share/doc/mod_auth_pgsql
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/mod_auth_pgsql
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${PREFIX}/share/doc/mod_auth_pgsql

.include "../../databases/postgresql-lib/buildlink2.mk"
.include "../../www/apache/module.mk"
.include "../../mk/bsd.pkg.mk"
