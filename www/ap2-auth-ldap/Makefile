# $NetBSD: Makefile,v 1.3 2005/02/26 01:06:08 adrianp Exp $

DISTNAME=	mod_auth_ldap3.3
PKGNAME=	ap2-auth-ldap-3.3
CATEGORIES=	www databases
MASTER_SITES=	http://www.muquit.com/muquit/software/mod_auth_ldap/

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://www.muquit.com/muquit/software/mod_auth_ldap/mod_auth_ldap_apache2.html
COMMENT=	Module to allow apache2 authentication against an LDAP directory

GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES
APACHE_MODULE=		YES
APACHE_MODULE_NAME=	mm_auth_ldap_module
USE_LIBTOOL=		YES
CPPFLAGS+=		-L${PREFIX}/lib ${COMPILER_RPATH_FLAG}${PREFIX}/lib -lldap -llber

BUILDLINK_DEPENDS.apache?=      apache>=2.0.47

CONFIGURE_ARGS+=	--with-apxs=${APXS}
CONFIGURE_ARGS+=	--with-ldap-dir=${BUILDLINK_PREFIX.openldap}
CONFIGURE_ARGS+=	--with-apache-dir=${PREFIX}
CONFIGURE_ARGS+=	--with-apache-ver=2

SUBST_CLASSES=		paths
SUBST_STAGE.paths=	post-patch
SUBST_FILES.paths=	configure
SUBST_SED.paths=	-e "s|@@HASHLIB@@|${PREFIX}/include|g" \
			-e "s|@@HASHINC@@|${PREFIX}/lib|g"
SUBST_MESSAGE.paths=	"Fixing hardcoded paths."

do-install:
	cd ${WRKSRC} && ${APXS} -i \
		-n ${APACHE_MODULE_NAME} mod_auth_ldap.la

.include "../../databases/openldap/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../www/apache2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
