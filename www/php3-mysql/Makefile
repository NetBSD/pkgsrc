# $NetBSD: Makefile,v 1.4 1999/12/13 20:38:28 bad Exp $
#

PKGNAME=	php-mysql-${PHP_VERSION}

DEPENDS+=	mysql-client-3.22.27:../../databases/mysql-client

CONFIGURE_ARGS+=--with-mysql=${LOCALBASE}

BUILDING_EXTENSION_MODULE=yes

do-build:
	cd ${WRKSRC}/functions && \
		${COMPILE.c} -I.. -I. -I${LOCALBASE}/include/mysql -fPIC -DPIC -DCOMPILE_DL mysql.c && \
		ld -Bshareable -o mysql.so mysql.o -L${LOCALBASE}/lib/mysql -R${LOCALBASE}/lib/mysql -lmysqlclient

do-install:
	${INSTALL_DATA} ${WRKSRC}/functions/mysql.so ${PREFIX}/lib/php3/

.include "../php3/Makefile"
