# $NetBSD: Makefile,v 1.3 2002/03/13 17:37:46 fredb Exp $
#

.include "../bbkeys/Makefile.common"

PKGNAME=	bbkeys-qt-1.2
PKGREVISION=	1
COMMENT=	Qt-based configuration utility for bbkeys

DEPENDS+=	bbkeys-0.3.5:../bbkeys

WRKSRC=		${WRKDIR}/bbkeys-0.3.5/bbkeysconf-1.2

.include "../../x11/qt2-libs/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
