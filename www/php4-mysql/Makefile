# $NetBSD: Makefile,v 1.4 2001/03/01 18:18:16 jlam Exp $

.include "../../www/php4/Makefile.module"

MODNAME=		mysql
CATEGORIES+=		databases
PHP_PKG_VERS=		nb1

COMMENT=		PHP4 extension for MySQL databases

DEPENDS+=		mysql-client>=3.22:../../databases/mysql-client

EVAL_PREFIX+=		MYSQLDIR=mysql-client
CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${MYSQLDIR}
LDFLAGS+=		-Wl,-R${LOCALBASE}/lib/mysql

.include "../../mk/bsd.pkg.mk"
