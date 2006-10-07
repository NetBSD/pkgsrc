# $NetBSD: Makefile,v 1.15 2006/10/07 21:02:43 reed Exp $

DISTNAME=		mod_auth_pgsql-2.0.3
PKGNAME=		ap2-auth-pgsql-2.0.3
PKGREVISION=		3
CATEGORIES=		www databases
MASTER_SITES=		http://www.giuseppetanzilli.it/mod_auth_pgsql2/dist/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.giuseppetanzilli.it/mod_auth_pgsql2/
COMMENT=		Allows users to use PostgreSQL databases for user authentication

CONFLICTS=		ap-auth-postgresql-*

APACHE_MODULE=		yes
APACHE_MODULE_NAME=	ap2-auth-pgsql

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

.include "../../www/apache2/buildlink3.mk"

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
