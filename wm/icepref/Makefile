# $NetBSD: Makefile,v 1.4 2003/03/29 12:42:46 jmmv Exp $
#

DISTNAME=	icepref-1.1
PKGREVISION=	1
WRKSRC=		${WRKDIR}/icepref
CATEGORIES=	wm
MASTER_SITES=	ftp://ftp.freebsd.org/pub/FreeBSD/distfiles/

MAINTAINER=	ptiJo@noos.fr
# This homepage no longer exists - agc 21 June 2002
#HOMEPAGE=	http://members.xoom.com/SaintChoj/icepref.html
COMMENT=	graphical configuration utility for IceWM

USE_BUILDLINK2=	yes

PYTHON_PATCH_SCRIPTS=	icepref

.include "../../lang/python/application.mk"
.include "../../x11/pygtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
