# $NetBSD: Makefile,v 1.8 2000/10/21 23:04:34 wiz Exp $
#

PKGNAME=	php-mysql-${PHP_VERSION}

DEPENDS+=	mysql-client-3.22.32:../../databases/mysql-client

CONFIGURE_ARGS+=--with-mysql=${LOCALBASE}

BUILDING_EXTENSION_MODULE=yes

MESSAGE_FILE=	${WRKDIR}/MESSAGE

do-build:
	cd ${WRKSRC}/functions && \
		${COMPILE.c} -I.. -I. -I${LOCALBASE}/include/mysql -fPIC -DPIC -DCOMPILE_DL mysql.c && \
		ld -Bshareable -o mysql.so mysql.o -L${LOCALBASE}/lib/mysql -R${LOCALBASE}/lib/mysql -lmysqlclient -lm

do-install:
	${INSTALL_DATA} ${WRKSRC}/functions/mysql.so ${PREFIX}/lib/php3/
	${SED} -e 's|@PREFIX@|${PREFIX}|g' ${PKGDIR}/MESSAGE >${MESSAGE_FILE}

.include "../php3/Makefile"
