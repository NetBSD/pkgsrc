# $NetBSD: Makefile,v 1.16 2010/02/20 14:58:45 joerg Exp $

DISTNAME=	mod_throttle312
PKGNAME=	ap13-throttle-3.1.2
CATEGORIES=	www
MASTER_SITES=	http://www.snert.com/Software/mod_throttle/
EXTRACT_SUFX=	.tgz

MAINTAINER=	eric@cirr.com
HOMEPAGE=	${MASTER_SITES}
COMMENT=	Apache module for limiting bandwidth usage

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=	ap-throttle-[0-9]*

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV:S/ap13-/mod_/}

APACHE_MODULE_NAME=	mod_throttle.so
APACHE_MODULE_SRC=	mod_throttle.c

INSTALLATION_DIRS+=	share/doc/mod_throttle

post-install:
	${INSTALL_DATA} ${WRKSRC}/index.shtml \
	    ${DESTDIR}${PREFIX}/share/doc/mod_throttle/index.html

.include "../../www/apache/module.mk"
.include "../../mk/bsd.pkg.mk"
