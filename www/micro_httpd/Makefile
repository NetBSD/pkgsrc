# $NetBSD: Makefile,v 1.2 2004/01/20 12:27:59 agc Exp $

DISTNAME=	micro_httpd_14dec2001
PKGNAME=	micro_httpd-20011214
CATEGORIES=	www
MASTER_SITES=	http://www.acme.com/software/micro_httpd/

MAINTAINER=	bjan+pkgsrc@bjan.freeshell.org
HOMEPAGE=	http://www.acme.com/software/micro_httpd/
COMMENT=	Really small HTTP server than runs from inetd(8)

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}/micro_httpd
USE_BUILDLINK3=		yes
NO_CONFIGURE=		yes

INSTALLATION_DIRS=	man/man8 sbin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/micro_httpd ${PREFIX}/sbin/
	${INSTALL_MAN} ${WRKSRC}/micro_httpd.8 ${PREFIX}/man/man8/

.include "../../mk/bsd.pkg.mk"
