# $NetBSD: Makefile,v 1.12 2019/07/08 21:20:28 schwarz Exp $

DISTNAME=	micro_httpd_14Aug2014
PKGNAME=	micro_httpd-20140814
CATEGORIES=	www
MASTER_SITES=	http://www.acme.com/software/micro_httpd/

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://www.acme.com/software/micro_httpd/
COMMENT=	Really small HTTP server than runs from inetd(8)

WRKSRC=			${WRKDIR}/micro_httpd
NO_CONFIGURE=		yes

LIBS.SunOS+=		-lnsl -lsocket

INSTALLATION_DIRS=	${PKGMANDIR}/man8 sbin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/micro_httpd ${DESTDIR}${PREFIX}/sbin/
	${INSTALL_MAN} ${WRKSRC}/micro_httpd.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/

.include "../../mk/bsd.pkg.mk"
