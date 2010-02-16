# $NetBSD: Makefile,v 1.20 2010/02/16 17:36:07 joerg Exp $

DISTNAME=	mod_auth_ldap3.05
PKGNAME=	ap2-auth-ldap-3.05
PKGREVISION=	6
CATEGORIES=	www databases
MASTER_SITES=	http://www.muquit.com/muquit/software/mod_auth_ldap/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${MASTER_SITES}/mod_auth_ldap.html
COMMENT=	Module to allow apache2 authentication against an LDAP directory

PKG_DESTDIR_SUPPORT=	user-destdir

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

INSTALLATION_DIRS+=	lib/httpd

do-install:
	${PREFIX}/share/httpd/build/instdso.sh \
	    SH_LIBTOOL=${PREFIX}/share/httpd/build/libtool \
	    ${WRKSRC}/mod_auth_ldap.la ${DESTDIR}${PREFIX}/lib/httpd

.include "../../databases/openldap-client/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
