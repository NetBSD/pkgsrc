# $NetBSD: Makefile,v 1.5 2001/09/27 23:18:57 jlam Exp $
#

PKGNAME=	php-snmp-${PHP_VERSION}

COMMENT=	PHP3 extension for SNMP databases

DEPENDS+=	ucd-snmp-[0-9]*:../../net/ucd-snmp

CONFIGURE_ARGS+=--with-snmp=${LOCALBASE}

BUILDING_EXTENSION_MODULE=yes

do-build:
	cd ${WRKSRC}/functions && \
		${COMPILE.c} -I.. -I. -I${LOCALBASE}/include/ucd-snmp -I../dl -fPIC -DPIC -DCOMPILE_DL snmp.c && \
		ld -Bshareable -o snmp.so snmp.o -L${LOCALBASE}/lib -R${LOCALBASE}/lib -lsnmp

do-install:
	${INSTALL_DATA} ${WRKSRC}/functions/snmp.so ${PREFIX}/lib/php3/

.include "../php3/Makefile"
