# $NetBSD: Makefile,v 1.2 2005/02/21 22:48:22 adrianp Exp $

DISTNAME=	mod_auth_ldap2.16
PKGNAME=	ap2-auth-ldap-2.16
CATEGORIES=	www databases
MASTER_SITES=	http://www.muquit.com/muquit/software/mod_auth_ldap/

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://www.muquit.com/muquit/software/mod_auth_ldap/mod_auth_ldap_apache2.html
COMMENT=	Module to allow apache2 authentication against an LDAP directory

GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES
APACHE_MODULE=		YES
APACHE_MODULE_NAME=	mod_auth_ldap
USE_LIBTOOL=		YES
CPPFLAGS+=		-L${PREFIX}/lib ${COMPILER_RPATH_FLAG}${PREFIX}/lib -lldap -llber

BUILDLINK_DEPENDS.apache+=	apache>=2.0.47

CONFIGURE_ARGS+=	--with-apxs=${APXS}
CONFIGURE_ARGS+=	--with-ldap-dir=${BUILDLINK_PREFIX.openldap}
CONFIGURE_ARGS+=	--with-apache-dir=${PREFIX}

do-install:
	cd ${WRKSRC} && ${APXS} -i \
		-n ${APACHE_MODULE_NAME} ${APACHE_MODULE_NAME}.la
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/${APACHE_MODULE_NAME}
	${INSTALL_DATA} ${WRKSRC}/${APACHE_MODULE_NAME}_apache2.html \
		${PREFIX}/share/doc/${APACHE_MODULE_NAME}

.include "../../databases/openldap/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../www/apache2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
