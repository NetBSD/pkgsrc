# $NetBSD: Makefile,v 1.3 2002/11/23 23:23:52 wiz Exp $
#

DISTNAME=	icepref-1.1
PKGREVISION=	1
CATEGORIES=	wm
MASTER_SITES=	ftp://ftp.freebsd.org/pub/FreeBSD/distfiles/

MAINTAINER=	ptiJo@noos.fr
# This homepage no longer exists - agc 21 June 2002
#HOMEPAGE=	http://members.xoom.com/SaintChoj/icepref.html
COMMENT=	graphical configuration utility for IceWM

WRKSRC=		${WRKDIR}/icepref

USE_BUILDLINK2=	yes

PYTHON_PATCH_SCRIPTS=	icepref

.include "../../lang/python/application.mk"
.include "../../x11/pygtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
