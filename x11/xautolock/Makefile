# $NetBSD: Makefile,v 1.16 2004/01/06 07:17:13 jlam Exp $

DISTNAME=	xautolock-pl15
PKGNAME=	xautolock-1.15
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=applications/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	tron@NetBSD.org
COMMENT=	Activate xlock after a user defined time of inactivity

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=	YES
USE_IMAKE=	YES

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} == SunOS)
PLIST_SRC=	${WRKDIR}/PLIST

post-install:
	${GREP} -v '^man/cat' ${PKGDIR}/PLIST >${PLIST_SRC}
.else
INSTALLATION_DIRS=	man/man1

post-install:
	cd ${WRKSRC}; \
	${INSTALL_MAN} xautolock.man ${PREFIX}/man/man1/xautolock.1
.endif

.include "../../mk/bsd.pkg.mk"
