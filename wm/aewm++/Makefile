# $NetBSD: Makefile,v 1.1.1.1 2003/03/12 03:21:37 jschauma Exp $
#

DISTNAME=	aewm++-1.0.22
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sapphire/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jrp@hispabsd.org
HOMEPAGE=	http://sapphire.sourceforge.net/
COMMENT=	Fork of the popular minimal window manager aewm

USE_BUILDLINK2=	YES
USE_X11=	YES

pre-install:
	${MV} ${WRKSRC}/aewm++.1x ${WRKSRC}/aewm++.1

.include "../../mk/bsd.pkg.mk"
