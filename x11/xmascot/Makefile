# $NetBSD: Makefile,v 1.9 1998/08/20 15:17:40 tsarna Exp $
# FreeBSD Id: Makefile,v 1.2 1997/06/07 19:47:09 max Exp
#

DISTNAME=	xmascot2.5p2
PKGNAME=        xmascot-2.5p2
CATEGORIES=	x11
MASTER_SITES=	ftp://cclub.tutcc.tut.ac.jp/pub/xmascot/

MAINTAINER=	Nakai@Mlab.t.u-tokyo.ac.jp
HOMEPAGE=	http://cclub.cc.tut.ac.jp/xmascot/

OPSYS!=		uname -s

USE_IMAKE=	yes

.if (${OPSYS} != "NetBSD")
MANCOMPRESSED=	yes
.endif

.include "../../mk/bsd.pkg.mk"
