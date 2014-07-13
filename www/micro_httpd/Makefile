# $NetBSD: Makefile,v 1.10 2014/07/13 14:49:13 schwarz Exp $

DISTNAME=	micro_httpd_10jul2014
PKGNAME=	micro_httpd-20140710
CATEGORIES=	www
MASTER_SITES=	http://www.acme.com/software/micro_httpd/

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://www.acme.com/software/micro_httpd/
COMMENT=	Really small HTTP server than runs from inetd(8)

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}/micro_httpd
NO_CONFIGURE=		yes

LIBS.SunOS+=		-lnsl -lsocket

INSTALLATION_DIRS=	${PKGMANDIR}/man8 sbin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/micro_httpd ${DESTDIR}${PREFIX}/sbin/
	${INSTALL_MAN} ${WRKSRC}/micro_httpd.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/

.include "../../mk/bsd.pkg.mk"
