# $NetBSD: Makefile,v 1.15 2008/06/20 01:09:40 joerg Exp $
#

DISTNAME=		WindowMaker-extra-0.1
PKGNAME=		wmextra-0.1
PKGREVISION=		3
CATEGORIES=		x11 wm windowmaker
MASTER_SITES=		ftp://ftp.windowmaker.info/pub/source/release/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.windowmaker.info/
COMMENT=		Extras for Window Maker window manager

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		windowmaker>=0.80.0nb1:../../wm/windowmaker

USE_X11BASE=		yes
GNU_CONFIGURE=		yes

.include "../../mk/bsd.pkg.mk"
