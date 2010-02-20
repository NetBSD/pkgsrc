# $NetBSD: Makefile,v 1.14 2010/02/20 14:58:44 joerg Exp $

DISTNAME=	mod_auth_pgsql-0.9.12
PKGNAME=	ap13-auth-pgsql-0.9.12
PKGREVISION=	3
CATEGORIES=	www databases
MASTER_SITES=	http://www.giuseppetanzilli.it/mod_auth_pgsql/dist/

MAINTAINER=	waddell@caravan-epub.com
HOMEPAGE=	http://www.giuseppetanzilli.it/mod_auth_pgsql/
COMMENT=	Apache module for user authentication/logging against a PostgreSQL DB

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=	ap-auth-pgsql-[0-9]*
CONFLICTS+=	ap-auth-postgresql-[0-9]*
CONFLICTS+=	ap13-auth-postgresql-[0-9]*

APACHE_MODULE_NAME=	mod_auth_pgsql.so

CPPFLAGS+=	-I${PGSQL_PREFIX}/include/postgresql
LDFLAGS+=	-lpq -lcrypt

INSTALLATION_DIRS+=	share/doc/mod_auth_pgsql

post-install:
	${INSTALL_DATA} ${WRKSRC}/mod_auth_pgsql.html ${DESTDIR}${PREFIX}/share/doc/mod_auth_pgsql
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/mod_auth_pgsql
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${DESTDIR}${PREFIX}/share/doc/mod_auth_pgsql

.include "../../www/apache/module.mk"

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
