# $NetBSD: Makefile,v 1.13 2005/03/24 21:13:04 wiz Exp $

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
