# $NetBSD: Makefile,v 1.19 2003/09/16 22:57:08 recht Exp $

DISTNAME=	AuthPG-1.4
PKGNAME=	ap-auth-postgresql-1.4
CATEGORIES=	www databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=authpg/}

MAINTAINER=	jwise@NetBSD.org
HOMEPAGE=	http://authpg.sourceforge.net/
COMMENT=	Module to allow apache authentication against a Postgresql database

CONFLICTS=	ap-auth-pgsql-[0-9]*

USE_BUILDLINK2=	YES

APACHE_MODULE_NAME=	mod_auth_pg.so

CPPFLAGS+=	-I${BUILDLINK_PREFIX.postgresql-lib}/include/postgresql
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

.include "../../databases/postgresql-lib/buildlink2.mk"
.include "../../www/apache/module.mk"
.include "../../mk/bsd.pkg.mk"
