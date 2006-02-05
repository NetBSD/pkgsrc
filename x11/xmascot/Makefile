# $NetBSD: Makefile,v 1.16 2006/02/05 23:11:48 joerg Exp $

DISTNAME=	xmascot2.5p2
PKGNAME=        xmascot-2.5p2
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	ftp://cclub.tutcc.tut.ac.jp/pub/xmascot/

MAINTAINER=	Nakai@Mlab.t.u-tokyo.ac.jp
HOMEPAGE=	http://cclub.cc.tut.ac.jp/xmascot/
COMMENT=	Moving mascot on your X-Window screen

BROKEN_IN=	pkgsrc-2005Q4

USE_IMAKE=	yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "NetBSD"
MANCOMPRESSED=	yes
.endif

.include "../../mk/bsd.pkg.mk"
