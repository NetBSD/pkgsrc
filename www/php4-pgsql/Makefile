# $NetBSD: Makefile,v 1.1.1.1 2000/12/17 09:21:20 jlam Exp $

.include "../../www/php4/Makefile.module"

MODNAME=		pgsql
CATEGORIES+=		databases

DEPENDS+=		postgresql>=6.5.3:../../databases/postgresql

EVAL_PREFIX+=		PGSQLDIR=postgresql
CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${PGSQLDIR}

.include "../../mk/bsd.pkg.mk"
