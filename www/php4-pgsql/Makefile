# $NetBSD: Makefile,v 1.5 2001/05/14 15:04:51 jlam Exp $

.include "../../www/php4/Makefile.module"

MODNAME=		pgsql
CATEGORIES+=		databases
PHP_PKG_VERS=		# empty

COMMENT=		PHP4 extension for PostgreSQL databases

DEPENDS+=		postgresql-{6.5.3*,7.0*,lib-*}:../../databases/postgresql-lib

EVAL_PREFIX+=		PGSQLDIR=postgresql
CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${PGSQLDIR}

.include "../../mk/bsd.pkg.mk"
