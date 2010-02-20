# $NetBSD: Makefile,v 1.34 2010/02/20 14:58:44 joerg Exp $

DISTNAME=	AuthPG-1.4
PKGNAME=	ap13-auth-postgresql-1.4
PKGREVISON=	3
CATEGORIES=	www databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=authpg/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://authpg.sourceforge.net/
COMMENT=	Module to allow apache authentication against a Postgresql database

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=	ap-auth-postgresql-[0-9]*
CONFLICTS+=	ap-auth-pgsql-[0-9]*
CONFLICTS+=	ap13-auth-pgsql-[0-9]*

APACHE_MODULE_NAME=	mod_auth_pg.so

CPPFLAGS+=	-I${PGSQL_PREFIX}/include/postgresql
LDFLAGS+=	-lpq -lcrypt

DOCDIR=	${PREFIX}/share/doc/mod_auth_pg
EGDIR=	${PREFIX}/share/examples/mod_auth_pg

INSTALLATION_DIRS+=	${DOCDIR} ${EGDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/mod_auth_pg.html ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/mod_auth_pg.ko.html ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README.ko ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/sample.htaccess ${DESTDIR}${EGDIR}/mod_auth_pg.htaccess
	${INSTALL_DATA} ${WRKSRC}/sample.sql ${DESTDIR}${EGDIR}/mod_auth_pg.sql

.include "../../www/apache/module.mk"

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
