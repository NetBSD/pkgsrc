# $NetBSD: Makefile,v 1.14 2005/12/26 23:39:35 schmonz Exp $

DISTNAME=	xmascot2.5p2
PKGNAME=        xmascot-2.5p2
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	ftp://cclub.tutcc.tut.ac.jp/pub/xmascot/

MAINTAINER=	Nakai@Mlab.t.u-tokyo.ac.jp
HOMEPAGE=	http://cclub.cc.tut.ac.jp/xmascot/
COMMENT=	Moving mascot on your X-Window screen

PKG_FAIL_REASON+=	"Broken on NetBSD/i386 3.0 in pkgsrc-2005Q4"
PKG_FAIL_REASON+=	"Will be removed in pkgsrc-2006Q1 unless fixed"

USE_IMAKE=	yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "NetBSD"
MANCOMPRESSED=	yes
.endif

.include "../../mk/bsd.pkg.mk"
