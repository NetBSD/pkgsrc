# $NetBSD: Makefile,v 1.2 2000/12/30 21:30:18 hubertf Exp $

.include "../../www/php4/Makefile.module"

MODNAME=		mysql
CATEGORIES+=		databases

DEPENDS+=		mysql-client>=3.22:../../databases/mysql-client

EVAL_PREFIX+=		MYSQLDIR=mysql-client
CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${MYSQLDIR}
LDFLAGS+=		-Wl,-R${LOCALBASE}/lib/mysql

.include "../../mk/bsd.pkg.mk"
