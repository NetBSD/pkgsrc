# $NetBSD: Makefile,v 1.4 1999/12/02 01:47:06 darcy Exp $
#

PKGNAME=	php-pgsql-${PHP_VERSION}

DEPENDS+=	postgresql-6.5.3:../../databases/postgresql

CONFIGURE_ARGS+=--with-pgsql=${LOCALBASE}/pgsql

BUILDING_EXTENSION_MODULE=yes

do-build:
	cd ${WRKSRC}/functions && \
		${COMPILE.c} -I.. -I. -I${LOCALBASE}/pgsql/include -fPIC -DPIC -DCOMPILE_DL pgsql.c && \
		ld -Bshareable -o pgsql.so pgsql.o -L${LOCALBASE}/pgsql/lib -R${LOCALBASE}/pgsql/lib -lpq

do-install:
	${INSTALL_DATA} ${WRKSRC}/functions/pgsql.so ${PREFIX}/lib/php3/

.include "../php3/Makefile"
