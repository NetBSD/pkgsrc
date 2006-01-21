# $NetBSD: Makefile,v 1.9 2006/01/21 13:08:37 rillig Exp $

DISTNAME=		mod_auth_pgsql-2.0.3
PKGNAME=		${DISTNAME:S/^mod-/ap2/:S/_/-/g}
CATEGORIES=		www databases
MASTER_SITES=		http://www.giuseppetanzilli.it/mod_auth_pgsql2/dist/

MAINTAINER=		tech-pkg@NetBSD.org
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
	(cd ${WRKSRC} && ${APXS} -A -i ${DISTNAME:C/-[^-]*$//}.la)
	#${MKDIR} ${DOCSDIR}
	#${INSTALL_DATA} ${WRKSRC}/mod_auth_pgsql.html ${DOCSDIR}

.include "../../www/apache2/buildlink3.mk"

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
