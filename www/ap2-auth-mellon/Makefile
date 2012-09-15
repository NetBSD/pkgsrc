# $NetBSD: Makefile,v 1.22 2012/09/15 10:06:44 obache Exp $
#

PKGNAME=	${APACHE_PKG_PREFIX}-${DISTNAME:S/mod_//:S/_/-/}
DISTNAME=	mod_auth_mellon-0.4.0
PKGREVISION=	5
CATEGORIES=	www security
MASTER_SITES=	http://modmellon.googlecode.com/files/

MAINTAINER=	manu@NetBSD.org
HOMEPAGE=	http://code.google.com/p/modmellon/
COMMENT=	SAML 2.0 authentication for Apache
LICENSE=	gnu-gpl-v2 # or later

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
USE_TOOLS+=	pkg-config
CFLAGS+=	-DLASSO_SERVER_LOAD_METADATA_FLAG_DEFAULT=0

APACHE_MODULE=	YES
APACHE_MODULE_NAME=	auth_mellon_module
PKG_APACHE_ACCEPTED=	apache22
.include "../../mk/apache.mk"
BUILDLINK_API_DEPENDS.apache+=	apache>=2.0.47

SUBST_CLASSES+=		pthflags
SUBST_MESSAGES=		Remove -pthread flag
SUBST_STAGE.pthflags=	post-configure
SUBST_FILES.pthflags=	Makefile
SUBST_SED.pthflags=	-e 's| -pthread | |g'

INSTALLATION_DIRS+=	lib/httpd

do-install:
	cd ${WRKSRC} &&							\
	    libexecdir=`${APXS} -q LIBEXECDIR` &&			\
	    ${APXS} -i -S LIBEXECDIR=${DESTDIR}"$${libexecdir}" 	\
	      -n auth_mellon  mod_auth_mellon.la

.include "../../security/lasso/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../www/curl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
