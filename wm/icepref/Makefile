# $NetBSD: Makefile,v 1.1.1.1 2002/06/21 15:09:47 agc Exp $
#

DISTNAME=	icepref-1.1
CATEGORIES=	wm
MASTER_SITES=	ftp://ftp.freebsd.org/pub/FreeBSD/distfiles/

MAINTAINER=	ptiJo@noos.fr
# This homepage no longer exists - agc 21 June 2002
#HOMEPAGE=	http://members.xoom.com/SaintChoj/icepref.html
COMMENT=	graphical configuration utility for IceWM

WRKSRC=		${WRKDIR}/icepref

USE_BUILDLINK_ONLY=	yes

.include "../../x11/pygtk/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
