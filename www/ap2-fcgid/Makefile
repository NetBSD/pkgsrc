# $NetBSD: Makefile,v 1.2 2007/06/30 16:09:08 joerg Exp $

DISTNAME=	mod_fcgid.2.0
PKGNAME=	${APACHE_PKG_PREFIX}-fcgid-2.0
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mod-fcgid/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://fastcgi.coremail.cn/
COMMENT=	Binary compatible alternative to Apache module mod_fastcgi

PKG_APACHE_ACCEPTED=	apache2 apache22
APACHE_MODULE=		YES
USE_LIBTOOL=		YES

MAKE_FLAGS+=		LIBTOOL=${LIBTOOL:Q}
MAKE_FLAGS+=		INCLUDES="-I${LOCALBASE}/include/httpd"

SUBST_CLASSES+=		ap2
SUBST_STAGE.ap2=	pre-build
SUBST_FILES.ap2=	Makefile
SUBST_SED.ap2=		-e s,/usr/local/apache2,${PREFIX}/share/httpd,

.include "../../mk/apache.mk"

.include "../../mk/bsd.pkg.mk"
