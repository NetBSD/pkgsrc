# $NetBSD: Makefile,v 1.3 2001/02/17 17:22:34 wiz Exp $

.include "../../www/php4/Makefile.module"

MODNAME=		mysql
CATEGORIES+=		databases

COMMENT=		PHP4 extension for MySQL databases

DEPENDS+=		mysql-client>=3.22:../../databases/mysql-client

EVAL_PREFIX+=		MYSQLDIR=mysql-client
CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${MYSQLDIR}
LDFLAGS+=		-Wl,-R${LOCALBASE}/lib/mysql

.include "../../mk/bsd.pkg.mk"
