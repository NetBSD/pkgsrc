# $NetBSD: Makefile,v 1.76 2024/05/16 06:15:40 wiz Exp $

DISTNAME=	mod_auth_mellon-0.18.1
PKGNAME=	${APACHE_PKG_PREFIX}-${DISTNAME:S/mod_//:S/_/-/g}
PKGREVISION=	3
#PKGREVISION=	1
CATEGORIES=	www security
MASTER_SITES=	${MASTER_SITE_GITHUB:=latchset/}
GITHUB_PROJECT=	mod_auth_mellon
GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}
WRKSRC=		${WRKDIR}/${DISTNAME}

MAINTAINER=	manu@NetBSD.org
HOMEPAGE=	https://github.com/latchset/mod_auth_mellon
COMMENT=	SAML 2.0 authentication for Apache
LICENSE=	gnu-gpl-v2 # or later

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
USE_TOOLS+=	pkg-config autoconf automake

APACHE_MODULE=	YES
.include "../../mk/apache.mk"

SUBST_CLASSES+=		pthflags
SUBST_STAGE.pthflags=	post-configure
SUBST_FILES.pthflags=	Makefile
SUBST_SED.pthflags=	-e 's| -pthread | |g'
SUBST_NOOP_OK.pthflags=	yes

INSTALLATION_DIRS+=	lib/httpd

pre-configure:
	cd ${WRKSRC} && ./autogen.sh

do-install:
	cd ${WRKSRC} &&							\
	    libexecdir=`${APXS} -q LIBEXECDIR` &&			\
	    ${APXS} -i -S LIBEXECDIR=${DESTDIR}"$${libexecdir}" 	\
	      -n auth_mellon  mod_auth_mellon.la

.include "../../security/lasso/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
