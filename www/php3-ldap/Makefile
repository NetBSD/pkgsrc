# $NetBSD: Makefile,v 1.6 2001/02/17 17:22:29 wiz Exp $
#

PKGNAME=	php-ldap-${PHP_VERSION}

COMMENT=	PHP3 extension for LDAP databases

DEPENDS+=	openldap-1.2.*:../../databases/openldap

CONFIGURE_ARGS+=--with-ldap=${LOCALBASE}

BUILDING_EXTENSION_MODULE=yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
LD_SHARE_FLAG=	-G
.else
LD_SHARE_FLAG=	-Bshareable
.endif

do-build:
	cd ${WRKSRC}/functions && \
		${COMPILE.c} -I.. -I. -I${LOCALBASE}/include -fPIC -DPIC -DCOMPILE_DL ldap.c && \
		ld ${LD_SHARE_FLAG} -o ldap.so ldap.o -L${LOCALBASE}/lib -R${LOCALBASE}/lib -lldap -llber

do-install:
	${INSTALL_DATA} ${WRKSRC}/functions/ldap.so ${PREFIX}/lib/php3/

.include "../php3/Makefile"
