# $NetBSD: Makefile,v 1.3 2001/03/01 18:18:16 jlam Exp $

.include "../../www/php4/Makefile.module"

MODNAME=		pgsql
CATEGORIES+=		databases
PHP_PKG_VERS=		nb1

COMMENT=		PHP4 extension for PostgreSQL databases

DEPENDS+=		postgresql>=6.5.3:../../databases/postgresql

EVAL_PREFIX+=		PGSQLDIR=postgresql
CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${PGSQLDIR}

.include "../../mk/bsd.pkg.mk"
