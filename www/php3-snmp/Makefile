# $NetBSD: Makefile,v 1.2 1999/09/01 17:09:56 bad Exp $
#

PKGNAME=	php-snmp-${PHP_VERSION}

DEPENDS+=	ucd-snmp-3.6.1p1:../../net/ucd-snmp

CONFIGURE_ARGS+=--with-snmp=${LOCALBASE}

BUILDING_EXTENSION_MODULE=yes

do-build:
	cd ${WRKSRC}/functions && \
		${COMPILE.c} -I.. -I. -I${LOCALBASE}/include/ucd-snmp -I../dl -fPIC -DPIC -DCOMPILE_DL snmp.c && \
		ld -Bshareable -o snmp.so snmp.o -L${LOCALBASE}/lib -R${LOCALBASE}/lib -lsnmp

do-install:
	${INSTALL_DATA} ${WRKSRC}/functions/snmp.so ${PREFIX}/lib/php3/

.include "../php3/Makefile"
