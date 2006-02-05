# $NetBSD: Makefile,v 1.15 2006/02/05 23:11:13 joerg Exp $
#

DISTNAME=	icepref-1.1
PKGREVISION=	7
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
