# $NetBSD: Makefile,v 1.10 2006/01/24 07:32:41 wiz Exp $
#

DISTNAME=		WindowMaker-extra-0.1
PKGNAME=		wmextra-0.1
PKGREVISION=		2
CATEGORIES=		x11 wm windowmaker
MASTER_SITES=		ftp://ftp.windowmaker.org/pub/source/release/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.windowmaker.org/
COMMENT=		Extras for Window Maker window manager

DEPENDS+=		windowmaker>=0.80.0nb1:../../wm/windowmaker

USE_X11BASE=		yes
GNU_CONFIGURE=		yes

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
