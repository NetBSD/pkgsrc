# $NetBSD: Makefile,v 1.4 2004/10/03 00:18:24 tv Exp $
# FreeBSD Id: ports/www/mod_auth_pgsql2/Makefile,v 1.5 2004/02/06 11:21:00 clement Exp

DISTNAME=		mod_auth_pgsql-2.0.2b1
PKGNAME=		ap2-auth-pgsql-2.0.2b1
PKGREVISION=	1
CATEGORIES=		www databases
MASTER_SITES=	http://www.giuseppetanzilli.it/mod_auth_pgsql2/dist/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.giuseppetanzilli.it/mod_auth_pgsql2/
COMMENT=		Allows users to use PostgreSQL databases for user authentication

CONFLICTS=		ap-auth-postgresql-*
USE_BUILDLINK3=	yes

APACHE_MODULE =		yes
APACHE_MODULE_NAME =	ap2-auth-pgsql

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

