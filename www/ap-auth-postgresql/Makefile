# $NetBSD: Makefile,v 1.3 2000/06/21 16:07:35 darcy Exp $

DISTNAME=	AuthPG-1.2b2
PKGNAME=	ap-auth-postgresql-1.2b2
CATEGORIES=	www databases
MASTER_SITES=	http://home.bawi.org/~minskim/authpg/

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://home.bawi.org/~minskim/authpg/

DEPENDS+=	apache-1.3.*:../../www/apache
DEPENDS+=	postgresql-*:../../databases/postgresql
# For "apxs":
BUILD_DEPENDS=	${LOCALBASE}/bin/perl:../../lang/perl5

CPPFLAGS+=	-I${LOCALBASE}/include/pgsql
LIBS=		-lpq -lcrypt

do-build:
	cd ${WRKSRC} && ${PREFIX}/sbin/apxs \
		${CPPFLAGS} ${LDFLAGS} ${LIBS} -c mod_auth_pg.c

do-install:
	@cd ${WRKSRC} && ${PREFIX}/sbin/apxs -i mod_auth_pg.so
	-${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mod_auth_pg
	${INSTALL_DATA} ${WRKSRC}/mod_auth_pg.html ${PREFIX}/share/doc/mod_auth_pg
	${INSTALL_DATA} ${WRKSRC}/mod_auth_pg.ko.html ${PREFIX}/share/doc/mod_auth_pg
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/mod_auth_pg
	${INSTALL_DATA} ${WRKSRC}/README.ko ${PREFIX}/share/doc/mod_auth_pg
	${INSTALL_DATA} ${WRKSRC}/sample.htaccess ${PREFIX}/share/examples/mod_auth_pg.htaccess

.include "../../mk/bsd.pkg.mk"
