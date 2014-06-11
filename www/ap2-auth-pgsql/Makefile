# $NetBSD: Makefile,v 1.26 2014/06/11 12:57:23 joerg Exp $

DISTNAME=		mod_auth_pgsql-2.0.3
PKGNAME=		${APACHE_PKG_PREFIX}-auth-pgsql-2.0.3
PKGREVISION=		8
CATEGORIES=		www databases
MASTER_SITES=		http://www.giuseppetanzilli.it/mod_auth_pgsql2/dist/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.giuseppetanzilli.it/mod_auth_pgsql2/
COMMENT=		Allows users to use PostgreSQL databases for user authentication

CONFLICTS=		ap-auth-postgresql-*

APACHE_MODULE=		yes
APACHE_MODULE_NAME=	mod_auth_pgsql.la

PKG_APACHE_ACCEPTED=	apache22

CPPFLAGS+=	-I${PGSQL_PREFIX}/include/postgresql
LDFLAGS+=	-L${LOCALBASE}/lib \
		${COMPILER_RPATH_FLAG}${LOCALBASE}/lib -lpq

.include "../../mk/apache.module.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
