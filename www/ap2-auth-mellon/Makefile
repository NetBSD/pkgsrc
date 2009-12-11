# $NetBSD: Makefile,v 1.7 2009/12/11 11:38:20 obache Exp $
#

PKGNAME=	${APACHE_PKG_PREFIX}-${DISTNAME:S/mod_//:S/_/-/}
DISTNAME=	mod_auth_mellon-0.2.5
CATEGORIES=	www security
MASTER_SITES=	http://modmellon.googlecode.com/files/

MAINTAINER=	manu@NetBSD.org
HOMEPAGE=	http://code.google.com/p/modmellon/
COMMENT=	SAML 2.0 authentication for Apache

PKG_DESTDIR_SUPPORT=	destdir

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
USE_TOOLS+=	pkg-config

APACHE_MODULE=	YES
APACHE_MODULE_NAME=	auth_mellon_module
PKG_APACHE_ACCEPTED=    apache2 apache22
.include "../../mk/apache.mk"
BUILDLINK_API_DEPENDS.apache+=  apache>=2.0.47

CONFIGURE_ENV+=		PKG_CONFIG_PATH=${PREFIX}/lib/pkgconfig
CONFIGURE_ENV+=		OPENSSL_CFLAGS="${CPPFLAGS}"
CONFIGURE_ENV+=		OPENSSL_LIBS="-L${PREFIX}/lib -lssl -lcrypto"
CONFIGURE_ARGS+=        --with-apxs2=${APXS:Q}

.include "../../security/lasso/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
