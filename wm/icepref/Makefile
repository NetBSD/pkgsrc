# $NetBSD: Makefile,v 1.9 2004/01/20 12:27:35 agc Exp $
#

DISTNAME=	icepref-1.1
PKGREVISION=	4
CATEGORIES=	wm
MASTER_SITES=	ftp://ftp.freebsd.org/pub/FreeBSD/distfiles/

MAINTAINER=	ptiJo@noos.fr
# This homepage no longer exists - agc 21 June 2002
#HOMEPAGE=	http://members.xoom.com/SaintChoj/icepref.html
COMMENT=	Graphical configuration utility for IceWM

WRKSRC=		${WRKDIR}/icepref
USE_BUILDLINK2=	yes

PYTHON_PATCH_SCRIPTS=	icepref

.include "../../lang/python/application.mk"
.include "../../x11/pygtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
