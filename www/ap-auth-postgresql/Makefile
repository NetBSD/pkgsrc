# $NetBSD: Makefile,v 1.26 2006/02/05 23:11:17 joerg Exp $

DISTNAME=	AuthPG-1.4
PKGNAME=	ap-auth-postgresql-1.4
PKGREVISION=	3
CATEGORIES=	www databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=authpg/}

MAINTAINER=	jwise@NetBSD.org
HOMEPAGE=	http://authpg.sourceforge.net/
COMMENT=	Module to allow apache authentication against a Postgresql database

CONFLICTS=	ap-auth-pgsql-[0-9]*


PGSQL_VERSION_REQD=	73

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
