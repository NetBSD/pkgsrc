# $NetBSD: Makefile,v 1.24 2009/06/30 00:07:25 joerg Exp $

DISTNAME=	xmascot2.6a
PKGNAME=	xmascot-2.6a
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://cclub-flying.dsl.gr.jp/products/xmascot/

MAINTAINER=	Nakai@Mlab.t.u-tokyo.ac.jp
HOMEPAGE=	http://cclub-flying.dsl.gr.jp/products/xmascot/
COMMENT=	Moving mascot on your X-Window screen

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=		no

USE_IMAKE=	yes

INSTALL_MAKE_FLAGS+=	LANG=ja_JP.eucJP

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXp/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
