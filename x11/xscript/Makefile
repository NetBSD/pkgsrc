# $NetBSD: Makefile,v 1.7 2004/01/20 12:28:29 agc Exp $
#

DISTNAME=	xscript.tar
PKGNAME=	xscript-19930228
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.x.org/R5contrib/ \
		ftp://ftp.gwdg.de/pub/x11/x.org/R5contrib/ \
		ftp://ftp.tu-darmstadt.de/pub/X11/R5contrib/ \
		ftp://unix.hensa.ac.uk/mirrors/ftp.x.org/R5contrib/ \
		ftp://ftp.darenet.dk/ny/mirrors/ftp.x.org/R5contrib/
EXTRACT_SUFX=	.Z

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.ee.ryerson.ca/~elf/xapps/Q-XVIII.html
COMMENT=	X Window system script recording and playback

WRKSRC=		${WRKDIR}/test-distrib/src
USE_BUILDLINK2=	YES
USE_X11BASE=	YES
USE_IMAKE=	YES

.include "../../mk/bsd.pkg.mk"
