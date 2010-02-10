# $NetBSD: Makefile,v 1.33 2010/02/10 19:34:07 joerg Exp $

DISTNAME=	AuthPG-1.4
PKGNAME=	ap13-auth-postgresql-1.4
PKGREVISON=	3
CATEGORIES=	www databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=authpg/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://authpg.sourceforge.net/
COMMENT=	Module to allow apache authentication against a Postgresql database

CONFLICTS=	ap-auth-postgresql-[0-9]*
CONFLICTS+=	ap-auth-pgsql-[0-9]*
CONFLICTS+=	ap13-auth-pgsql-[0-9]*

APACHE_MODULE_NAME=	mod_auth_pg.so

CPPFLAGS+=	-I${PGSQL_PREFIX}/include/postgresql
LDFLAGS+=	-lpq -lcrypt

DOCDIR=	${PREFIX}/share/doc/mod_auth_pg
EGDIR=	${PREFIX}/share/examples/mod_auth_pg

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/mod_auth_pg.html ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/mod_auth_pg.ko.html ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README.ko ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/sample.htaccess ${EGDIR}/mod_auth_pg.htaccess
	${INSTALL_DATA} ${WRKSRC}/sample.sql ${EGDIR}/mod_auth_pg.sql

.include "../../www/apache/module.mk"

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
