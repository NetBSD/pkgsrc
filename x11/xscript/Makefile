# $NetBSD: Makefile,v 1.2.2.1 2002/06/24 06:02:05 jlam Exp $
#

DISTNAME=	xscript.tar
PKGNAME=	xscript-19930228
WRKSRC=		${WRKDIR}/test-distrib/src
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.x.org/R5contrib/ \
		ftp://ftp.gwdg.de/pub/x11/x.org/R5contrib/ \
		ftp://ftp.tu-darmstadt.de/pub/X11/R5contrib/ \
		ftp://unix.hensa.ac.uk/mirrors/ftp.x.org/R5contrib/ \
		ftp://ftp.darenet.dk/ny/mirrors/ftp.x.org/R5contrib/
EXTRACT_SUFX=	.Z

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.ee.ryerson.ca/~elf/xapps/Q-XVIII.html
COMMENT=	X Window system script recording and playback

USE_BUILDLINK2=	YES
USE_X11BASE=	YES
USE_IMAKE=	YES

.include "../../mk/bsd.pkg.mk"
