# $NetBSD: Makefile,v 1.9 2001/05/14 15:04:51 jlam Exp $
#

PKGNAME=	php-pgsql-${PHP_VERSION}

COMMENT=	PHP3 extension for PostgreSQL databases

DEPENDS+=	postgresql-{6.5.3*,7.0*,lib-*}:../../databases/postgresql-lib

CONFIGURE_ARGS+=--with-pgsql=${LOCALBASE}/pgsql

BUILDING_EXTENSION_MODULE=yes

do-build:
	cd ${WRKSRC}/functions && \
		${COMPILE.c} -I.. -I. -I${LOCALBASE}/include/pgsql -fPIC -DPIC -DCOMPILE_DL pgsql.c && \
		ld -Bshareable -o pgsql.so pgsql.o -L${LOCALBASE}/lib -R${LOCALBASE}/lib -lpq -lcrypt

do-install:
	${INSTALL_DATA} ${WRKSRC}/functions/pgsql.so ${PREFIX}/lib/php3/

.include "../php3/Makefile"
