# $NetBSD: Makefile,v 1.14 2005/04/11 21:47:47 tv Exp $
#

DISTNAME=	icepref-1.1
PKGREVISION=	6
CATEGORIES=	wm
MASTER_SITES=	ftp://ftp.freebsd.org/pub/FreeBSD/distfiles/

MAINTAINER=	tech-pkg@NetBSD.org
# This homepage no longer exists - agc 21 June 2002
#HOMEPAGE=	http://members.xoom.com/SaintChoj/icepref.html
COMMENT=	Graphical configuration utility for IceWM

WRKSRC=		${WRKDIR}/icepref

PYTHON_PATCH_SCRIPTS=	icepref

.include "../../lang/python/application.mk"
.include "../../x11/pygtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
