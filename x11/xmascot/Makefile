# $NetBSD: Makefile,v 1.12 2003/03/03 04:17:33 jschauma Exp $
# FreeBSD Id: Makefile,v 1.2 1997/06/07 19:47:09 max Exp
#

DISTNAME=	xmascot2.5p2
PKGNAME=        xmascot-2.5p2
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	ftp://cclub.tutcc.tut.ac.jp/pub/xmascot/

MAINTAINER=	Nakai@Mlab.t.u-tokyo.ac.jp
HOMEPAGE=	http://cclub.cc.tut.ac.jp/xmascot/
COMMENT=	Moving mascot on your X-Window screen

USE_IMAKE=	yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "NetBSD"
MANCOMPRESSED=	yes
.endif

.include "../../mk/bsd.pkg.mk"
