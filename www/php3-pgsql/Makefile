# $NetBSD: Makefile,v 1.6 2000/04/09 04:00:35 jlam Exp $
#

PKGNAME=	php-pgsql-${PHP_VERSION}

DEPENDS+=	postgresql-6.5.3:../../databases/postgresql

CONFIGURE_ARGS+=--with-pgsql=${LOCALBASE}/pgsql

BUILDING_EXTENSION_MODULE=yes

do-build:
	cd ${WRKSRC}/functions && \
		${COMPILE.c} -I.. -I. -I${LOCALBASE}/include/pgsql -fPIC -DPIC -DCOMPILE_DL pgsql.c && \
		ld -Bshareable -o pgsql.so pgsql.o -L${LOCALBASE}/lib -R${LOCALBASE}/lib -lpq -lcrypt

do-install:
	${INSTALL_DATA} ${WRKSRC}/functions/pgsql.so ${PREFIX}/lib/php3/

.include "../php3/Makefile"
