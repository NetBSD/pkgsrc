# $NetBSD: Makefile,v 1.17 2008/01/18 05:09:47 tnn Exp $

DISTNAME=	mod_auth_ldap3.05
PKGNAME=	ap2-auth-ldap-3.05
PKGREVISION=	5
CATEGORIES=	www databases
MASTER_SITES=	http://www.muquit.com/muquit/software/mod_auth_ldap/

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	${MASTER_SITES}/mod_auth_ldap.html
COMMENT=	Module to allow apache2 authentication against an LDAP directory

GNU_CONFIGURE=		YES
APACHE_MODULE=		YES
APACHE_MODULE_NAME=	mm_auth_ldap_module
USE_LIBTOOL=		YES
CPPFLAGS+=		-L${PREFIX}/lib ${COMPILER_RPATH_FLAG}${PREFIX}/lib -lldap -llber

PKG_APACHE_ACCEPTED=	apache2

.include "../../mk/apache.mk"
BUILDLINK_API_DEPENDS.apache+=	apache>=2.0.47

CONFIGURE_ARGS+=	--with-apxs=${APXS:Q}
CONFIGURE_ARGS+=	--with-ldap-dir=${BUILDLINK_PREFIX.openldap-client}
CONFIGURE_ARGS+=	--with-apache-dir=${PREFIX:Q}
CONFIGURE_ARGS+=	--with-apache-ver=2

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	post-patch
SUBST_FILES.paths=	configure
SUBST_SED.paths=	-e "s|@@HASHLIB@@|${PREFIX}/include|g" \
			-e "s|@@HASHINC@@|${PREFIX}/lib|g"
SUBST_MESSAGE.paths=	Fixing hardcoded paths.

do-install:
	cd ${WRKSRC} && ${APXS} -i -n ${APACHE_MODULE_NAME} mod_auth_ldap.la

.include "../../databases/openldap-client/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
