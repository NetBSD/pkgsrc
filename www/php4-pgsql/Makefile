# $NetBSD: Makefile,v 1.7 2001/09/27 23:18:57 jlam Exp $

.include "../../www/php4/Makefile.module"

MODNAME=		pgsql
CATEGORIES+=		databases
PHP_PKG_VERS=		# empty

COMMENT=		PHP4 extension for PostgreSQL databases

DEPENDS+=		postgresql-{6.5.3*,7.0*,lib-[0-9]*}:../../databases/postgresql-lib

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${LOCALBASE}

.include "../../mk/bsd.pkg.mk"
