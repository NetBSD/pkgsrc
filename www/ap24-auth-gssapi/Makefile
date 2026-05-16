#	$NetBSD: Makefile,v 1.1 2026/05/16 03:47:28 riastradh Exp $

DISTNAME=	mod_auth_gssapi-1.6.5
PKGNAME=	${DISTNAME:S/mod/${APACHE_PKG_PREFIX}/:S/_/-/g}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=gssapi/}
GITHUB_PROJECT=	${DISTNAME:C/-.*//}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/gssapi/mod_auth_gssapi
COMMENT=	Apache module for GSSAPI authentication
LICENSE=	isc

PKG_APACHE_ACCEPTED=	apache24
APACHE_MODULE=		yes

USE_LIBTOOL=		yes
USE_TOOLS+=		autoconf automake autoreconf pkg-config

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-apxs=${APXS:Q}
CONFIGURE_ARGS+=	APACHE=${_CROSS_DESTDIR:Q}${BUILDLINK_PREFIX.apache:Q}/sbin/httpd
CONFIGURE_ARGS+=	CPPFLAGS=-I${KRB5BASE:Q}/include

INSTALLATION_DIRS=	lib/httpd

pre-configure:
	@${STEP_MSG} Regenerating autoconf/automake products
	${RUN}cd ${WRKSRC} && autoreconf -fiv

do-install:
	@${STEP_MSG} Installing Apache module
	${INSTALL_LIB} ${WRKSRC}/src/.libs/mod_auth_gssapi.so \
	    ${DESTDIR}${PREFIX}/lib/httpd

PYTHON_FOR_BUILD_ONLY=	test

REPLACE_PYTHON+=	tests/*.py

BUILDLINK_DEPMETHOD.nss_wrapper=	build	# for tests only
BUILDLINK_DEPMETHOD.socket_wrapper=	build	# for tests only

TEST_DEPENDS+=	${PYPKGPREFIX}-requests-gssapi>=0:../../devel/py-requests-gssapi

TEST_ENV+=	KRB5_TYPE=${KRB5_TYPE:Q}
TEST_ENV+=	LD_PRELOAD_PREFIX=${BUILDLINK_DIR}/lib/
TEST_ENV+=	APACHE_HTTPD=${PREFIX}/sbin/httpd
TEST_ENV+=	APACHE_MODULE_DIR=${PREFIX}/lib/httpd

TEST_TARGET=	check

# We provide, via patch, a file that was missing in the upstream
# distribution tarball (but included in git), and we have to make it
# executable to run tests.
post-patch: post-patch-fix-permissions
post-patch-fix-permissions: .PHONY
	@${STEP_MSG} Fixing permissions on missing file
	${RUN}cd ${WRKSRC} && ${CHMOD} +x tests/t_file_check.py

.include "../../devel/nss_wrapper/buildlink3.mk"
.include "../../devel/socket_wrapper/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/apache.mk"
.include "../../mk/krb5.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
