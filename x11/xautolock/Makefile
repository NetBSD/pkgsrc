# $NetBSD: Makefile,v 1.15 2003/08/09 08:32:13 tron Exp $

DISTNAME=	xautolock-pl15
PKGNAME=	xautolock-1.15
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=applications/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	tron@NetBSD.org
COMMENT=	Activate xlock after a user defined time of inactivity

USE_BUILDLINK2=	YES
USE_IMAKE=	YES

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} == SunOS)
PLIST_SRC=	${WRKDIR}/PLIST

post-install:
	${GREP} -v '^man/cat' ${PKGDIR}/PLIST >${PLIST_SRC}
.else
post-install:
	cd ${WRKSRC}; \
	${INSTALL_MAN} xautolock.man ${X11PREFIX}/man/man1/xautolock.1
.endif

.include "../../mk/bsd.pkg.mk"
