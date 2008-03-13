# $NetBSD: Makefile,v 1.19 2008/03/13 17:38:49 joerg Exp $

DISTNAME=		mod_auth_pgsql-2.0.3
PKGNAME=		${APACHE_PKG_PREFIX}-auth-pgsql-2.0.3
PKGREVISION=		5
CATEGORIES=		www databases
MASTER_SITES=		http://www.giuseppetanzilli.it/mod_auth_pgsql2/dist/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.giuseppetanzilli.it/mod_auth_pgsql2/
COMMENT=		Allows users to use PostgreSQL databases for user authentication

CONFLICTS=		ap-auth-postgresql-*

APACHE_MODULE=		yes
APACHE_MODULE_NAME=	ap2-auth-pgsql

PKG_APACHE_ACCEPTED=	apache2 apache22

do-build:
	cd ${WRKSRC} && \
		${APXS} -c -n ${APACHE_MODULE_NAME} \
		-I${PGSQL_PREFIX}/include/postgresql \
		-L${LOCALBASE}/lib \
		${COMPILER_RPATH_FLAG}${LOCALBASE}/lib \
		-lpq ${DISTNAME:C/-[^-]*$//}.c

do-install:
	(cd ${WRKSRC} && ${APXS} -i ${DISTNAME:C/-[^-]*$//}.la)
	#${MKDIR} ${DOCSDIR}
	#${INSTALL_DATA} ${WRKSRC}/mod_auth_pgsql.html ${DOCSDIR}

.include "../../mk/apache.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
