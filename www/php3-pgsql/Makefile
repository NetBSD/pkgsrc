# $NetBSD: Makefile,v 1.2 1999/09/01 17:09:56 bad Exp $
#

PKGNAME=	php-pgsql-${PHP_VERSION}

DEPENDS+=	postgresql-6.4.2:../../databases/postgresql

CONFIGURE_ARGS+=--with-pgsql=${LOCALBASE}/pgsql

BUILDING_EXTENSION_MODULE=yes

do-build:
	cd ${WRKSRC}/functions && \
		${COMPILE.c} -I.. -I. -I${LOCALBASE}/pgsql/include -fPIC -DPIC -DCOMPILE_DL pgsql.c && \
		ld -Bshareable -o pgsql.so pgsql.o -L${LOCALBASE}/pgsql/lib -R${LOCALBASE}/pgsql/lib -lpq

do-install:
	${INSTALL_DATA} ${WRKSRC}/functions/pgsql.so ${PREFIX}/lib/php3/

.include "../php3/Makefile"
