# $NetBSD: Makefile,v 1.4 2002/03/18 09:17:37 wiz Exp $
#

DISTNAME=	bbkeys-0.3.5
PKGNAME=	bbkeys-qt-1.2
PKGREVISION=	1
CATEGORIES=	x11 wm
MASTER_SITES=	http://movingparts.thelinuxcommunity.org/bbkeys/

MAINTAINER=	alaric@alaric-snell.com
HOMEPAGE=	http://movingparts.thelinuxcommunity.org/bbkeys.shtml
COMMENT=	Qt-based configuration utility for bbkeys

DEPENDS+=	bbkeys-0.3.5:../bbkeys

WRKSRC=		${WRKDIR}/bbkeys-0.3.5/bbkeysconf-1.2
USE_X11BASE=    YES

.include "../../x11/qt2-libs/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
