# $NetBSD: Makefile,v 1.7 2006/01/24 07:32:41 wiz Exp $

DISTNAME=	mod_auth_pgsql-0.9.12
PKGNAME=	ap-auth-pgsql-0.9.12
PKGREVISION=	2
CATEGORIES=	www databases
MASTER_SITES=	http://www.giuseppetanzilli.it/mod_auth_pgsql/dist/

MAINTAINER=	waddell@caravan.com
HOMEPAGE=	http://www.giuseppetanzilli.it/mod_auth_pgsql/
COMMENT=	Apache module for user authentication/logging against a PostgreSQL DB

CONFLICTS=	ap-auth-postgresql-[0-9]*

APACHE_MODULE_NAME=	mod_auth_pgsql.so

CPPFLAGS+=	-I${PGSQL_PREFIX}/include/postgresql
LDFLAGS+=	-lpq -lcrypt

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mod_auth_pgsql
	${INSTALL_DATA} ${WRKSRC}/mod_auth_pgsql.html ${PREFIX}/share/doc/mod_auth_pgsql
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/mod_auth_pgsql
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${PREFIX}/share/doc/mod_auth_pgsql

.include "../../www/apache/module.mk"

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
