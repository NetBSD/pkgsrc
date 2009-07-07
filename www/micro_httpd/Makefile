# $NetBSD: Makefile,v 1.8 2009/07/07 19:06:08 joerg Exp $

DISTNAME=	micro_httpd_12dec2005
PKGNAME=	micro_httpd-20051212
CATEGORIES=	www
MASTER_SITES=	http://www.acme.com/software/micro_httpd/

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://www.acme.com/software/micro_httpd/
COMMENT=	Really small HTTP server than runs from inetd(8)

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/micro_httpd
NO_CONFIGURE=		yes

INSTALLATION_DIRS=	${PKGMANDIR}/man8 sbin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/micro_httpd ${DESTDIR}${PREFIX}/sbin/
	${INSTALL_MAN} ${WRKSRC}/micro_httpd.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/

.include "../../mk/bsd.pkg.mk"
