# $NetBSD: Makefile,v 1.17 2020/11/05 09:09:18 ryoon Exp $

DISTNAME=	mod_auth_mellon-0.13.1
PKGNAME=	${DISTNAME:S/mod/${APACHE_PKG_PREFIX}/:S/_/-/g}
PKGREVISION=	15
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=UNINETT/}
GITHUB_PROJECT=	mod_auth_mellon
GITHUB_TYPE=	release
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	he@NetBSD.org
HOMEPAGE=	https://github.com/UNINETT/mod_auth_mellon
COMMENT=	Module to allow Apache authentication using a SAML 2.0 IdP
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-apxs2=${APXS}
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
USE_TOOLS+=		pkg-config

APACHE_MODULE=		yes

DEPENDS+=	glib2>=2.12:../../devel/glib2

INSTALLATION_DIRS+=	lib/httpd

do-install:
	${INSTALL_LIB} ${WRKSRC}/.libs/mod_auth_mellon.so \
	    ${DESTDIR}${PREFIX}/lib/httpd

.include "../../mk/apache.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../security/lasso/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
