# $NetBSD: Makefile,v 1.8 2001/02/17 17:22:30 wiz Exp $
#

PKGNAME=	php-pgsql-${PHP_VERSION}

COMMENT=	PHP3 extension for PostgreSQL databases

DEPENDS+=	postgresql>=6.5.3:../../databases/postgresql

CONFIGURE_ARGS+=--with-pgsql=${LOCALBASE}/pgsql

BUILDING_EXTENSION_MODULE=yes

do-build:
	cd ${WRKSRC}/functions && \
		${COMPILE.c} -I.. -I. -I${LOCALBASE}/include/pgsql -fPIC -DPIC -DCOMPILE_DL pgsql.c && \
		ld -Bshareable -o pgsql.so pgsql.o -L${LOCALBASE}/lib -R${LOCALBASE}/lib -lpq -lcrypt

do-install:
	${INSTALL_DATA} ${WRKSRC}/functions/pgsql.so ${PREFIX}/lib/php3/

.include "../php3/Makefile"
