# $NetBSD: Makefile,v 1.24 2004/04/22 23:15:02 snj Exp $
# $FreeBSD Id: Makefile,v 1.13 1997/07/17 15:13:03 max Exp
#

DISTNAME=		xview3.2p1-X11R6
PKGNAME=		xview-lib-3.2.1
PKGREVISION=		3
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		OpenLook Toolkit libs, includes, and man pages

DEPENDS=		xview-config>=3.2.1nb2:../../x11/xview-config

NO_SRC_ON_FTP=		Already in MASTER_SITE_LOCAL
# builds, but binaries in../xview-clients all crash
NOT_FOR_PLATFORM=       *-*-alpha

USE_BUILDLINK3=		yes
USE_IMAKE=		# defined

post-install:
	cd ${PREFIX}/lib && ${LN} -fs libolgx.so.3.2 libolgx.so.3 && \
		${LN} -fs libxview.so.3.2 libxview.so.3

.include "../../mk/bsd.pkg.mk"
