# $NetBSD: Makefile,v 1.4 1997/11/05 13:40:16 agc Exp $
# New ports collection makefile for:   xmascot
# Version required:    2.5p2
# Date created:        20 November 1996
# Whom:                Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# FreeBSD Id: Makefile,v 1.2 1997/06/07 19:47:09 max Exp
#

DISTNAME=	xmascot2.5p2
PKGNAME=        xmascot-2.5p2
CATEGORIES=	x11
MASTER_SITES=	ftp://cclub.tutcc.tut.ac.jp/pub/xmascot/

MAINTAINER=	Nakai@Mlab.t.u-tokyo.ac.jp

OPSYS!=		uname -s

USE_GMAKE=	yes
USE_IMAKE=	yes
CAT1=		xmascot.0

.if (${OPSYS} != "NetBSD")
MANCOMPRESSED=	yes
.endif

.include <bsd.port.mk>
