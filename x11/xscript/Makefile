# $NetBSD: Makefile,v 1.15 2008/07/14 12:56:20 joerg Exp $
#

DISTNAME=	xscript.tar
PKGNAME=	xscript-19930228
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.x.org/R5contrib/ \
		ftp://ftp.gwdg.de/pub/x11/x.org/R5contrib/
EXTRACT_SUFX=	.Z

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ee.ryerson.ca/~elf/xapps/Q-XVIII.html
COMMENT=	X Window system script recording and playback

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/test-distrib/src
USE_IMAKE=	YES

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
