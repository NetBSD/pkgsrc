# $NetBSD: Makefile,v 1.10 1999/07/02 08:37:29 agc Exp $
# FreeBSD Id: Makefile,v 1.2 1997/06/07 19:47:09 max Exp
#

DISTNAME=	xmascot2.5p2
PKGNAME=        xmascot-2.5p2
CATEGORIES=	x11
MASTER_SITES=	ftp://cclub.tutcc.tut.ac.jp/pub/xmascot/

MAINTAINER=	Nakai@Mlab.t.u-tokyo.ac.jp
HOMEPAGE=	http://cclub.cc.tut.ac.jp/xmascot/

USE_IMAKE=	yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "NetBSD"
MANCOMPRESSED=	yes
.endif

.include "../../mk/bsd.pkg.mk"
