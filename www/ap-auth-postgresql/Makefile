# $NetBSD: Makefile,v 1.13 2002/07/24 19:45:29 jlam Exp $

DISTNAME=	AuthPG-1.2b2
PKGNAME=	ap-auth-postgresql-1.2b2
CATEGORIES=	www databases
MASTER_SITES=	http://home.bawi.org/~minskim/authpg/

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://home.bawi.org/~minskim/authpg/
COMMENT=	Module to allow apache authentication against a Postgresql database

DEPENDS+=	apache{,6}-1.3.*:../../www/apache
DEPENDS+=	postgresql-{6.5.3*,7.0*,lib-[0-9]*}:../../databases/postgresql-lib
USE_PERL5=	build	# for "apxs"

CPPFLAGS+=	-I${LOCALBASE}/include/pgsql
LIBS=		-lpq -lcrypt

do-build:
	cd ${WRKSRC} && ${PREFIX}/sbin/apxs \
		${CPPFLAGS} ${LDFLAGS} ${LIBS} -c mod_auth_pg.c

do-install:
	@cd ${WRKSRC} && ${PREFIX}/sbin/apxs -i mod_auth_pg.so
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mod_auth_pg
	${INSTALL_DATA} ${WRKSRC}/mod_auth_pg.html ${PREFIX}/share/doc/mod_auth_pg
	${INSTALL_DATA} ${WRKSRC}/mod_auth_pg.ko.html ${PREFIX}/share/doc/mod_auth_pg
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/mod_auth_pg
	${INSTALL_DATA} ${WRKSRC}/README.ko ${PREFIX}/share/doc/mod_auth_pg
	${INSTALL_DATA} ${WRKSRC}/sample.htaccess ${PREFIX}/share/examples/mod_auth_pg.htaccess

.include "../../mk/bsd.pkg.mk"
