# $NetBSD: Makefile,v 1.10 2001/09/27 23:18:56 jlam Exp $
#

PKGNAME=	php-pgsql-${PHP_VERSION}

COMMENT=	PHP3 extension for PostgreSQL databases

DEPENDS+=	postgresql-{6.5.3*,7.0*,lib-[0-9]*}:../../databases/postgresql-lib

CONFIGURE_ARGS+=--with-pgsql=${LOCALBASE}/pgsql

BUILDING_EXTENSION_MODULE=yes

do-build:
	cd ${WRKSRC}/functions && \
		${COMPILE.c} -I.. -I. -I${LOCALBASE}/include/pgsql -fPIC -DPIC -DCOMPILE_DL pgsql.c && \
		ld -Bshareable -o pgsql.so pgsql.o -L${LOCALBASE}/lib -R${LOCALBASE}/lib -lpq -lcrypt

do-install:
	${INSTALL_DATA} ${WRKSRC}/functions/pgsql.so ${PREFIX}/lib/php3/

.include "../php3/Makefile"
