# $NetBSD: Makefile,v 1.1.1.1 2000/01/10 22:33:12 jwise Exp $

DISTNAME=	AuthPG-1.1b1
PKGNAME=	ap-auth-postgresql-1.1b1
CATEGORIES=	www databases
MASTER_SITES=	http://home.bawi.org/~minskim/authpg/

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://home.bawi.org/~minskim/authpg/

DEPENDS+=	apache-1.3.*:../../www/apache
DEPENDS+=	postgresql-*:../../databases/postgresql
# For "apxs":
BUILD_DEPENDS=	${LOCALBASE}/bin/perl:../../lang/perl5

PGUSER?=	pgsql

INCLUDES=	-I${PREFIX}/${PGUSER}/include
LIBS=		-L${PREFIX}/${PGUSER}/lib -Wl,-R${PREFIX}/${PGUSER}/lib -lpq

do-build:
	cd ${WRKSRC} && ${PREFIX}/sbin/apxs ${INCLUDES} ${LIBS} -c mod_auth_pg.c

do-install:
	@cd ${WRKSRC} && ${PREFIX}/sbin/apxs -i mod_auth_pg.so
	-${MKDIR} ${PREFIX}/share/doc/mod_auth_pg
	${INSTALL_DATA} ${WRKSRC}/mod_auth_pg.html ${PREFIX}/share/doc/mod_auth_pg
	${INSTALL_DATA} ${WRKSRC}/mod_auth_pg.ko.html ${PREFIX}/share/doc/mod_auth_pg
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/mod_auth_pg
	${INSTALL_DATA} ${WRKSRC}/README.ko ${PREFIX}/share/doc/mod_auth_pg
	${INSTALL_DATA} ${WRKSRC}/sample.htaccess ${PREFIX}/share/examples/mod_auth_pg.htaccess

.include "../../mk/bsd.pkg.mk"
