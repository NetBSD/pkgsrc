# $NetBSD: Makefile,v 1.2 1999/09/01 17:09:53 bad Exp $
#

PKGNAME=	php-ldap-${PHP_VERSION}

DEPENDS+=	openldap-1.2.1p1:../../databases/openldap

CONFIGURE_ARGS+=--with-ldap=${LOCALBASE}

BUILDING_EXTENSION_MODULE=yes

do-build:
	cd ${WRKSRC}/functions && \
		${COMPILE.c} -I.. -I. -I${LOCALBASE}/include -fPIC -DPIC -DCOMPILE_DL ldap.c && \
		ld -Bshareable -o ldap.so ldap.o -L${LOCALBASE}/lib -R${LOCALBASE}/lib -lldap -llber

do-install:
	${INSTALL_DATA} ${WRKSRC}/functions/ldap.so ${PREFIX}/lib/php3/

.include "../php3/Makefile"
