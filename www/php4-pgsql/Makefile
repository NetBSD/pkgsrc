# $NetBSD: Makefile,v 1.2 2001/02/17 17:22:35 wiz Exp $

.include "../../www/php4/Makefile.module"

MODNAME=		pgsql
CATEGORIES+=		databases

COMMENT=		PHP4 extension for PostgreSQL databases

DEPENDS+=		postgresql>=6.5.3:../../databases/postgresql

EVAL_PREFIX+=		PGSQLDIR=postgresql
CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${PGSQLDIR}

.include "../../mk/bsd.pkg.mk"
