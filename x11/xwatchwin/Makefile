# $NetBSD: Makefile,v 1.2 2000/02/09 17:40:20 dmcmahill Exp $

DISTNAME=	xwatchwin
PKGNAME=	xwatchwin-1.1.1
CATEGORIES=	x11
MASTER_SITES=	ftp://sunsite.uio.no/pub/X11/contrib/utilities/

MAINTAINER=	packages@netbsd.org
#HOMEPAGE=	

ONLY_FOR_PLATFORM=	SunOS-*-*	# not tested on NetBSD yet
PLIST_SRC=	${PKGDIR}/PLIST.${LOWER_OPSYS}

USE_X11BASE=	yes
USE_IMAKE=	yes

.include "../../mk/bsd.pkg.mk"
