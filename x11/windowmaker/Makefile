# $NetBSD: Makefile,v 1.8 1998/04/22 14:22:50 agc Exp $
# FreeBSD Id: Makefile,v 1.1.1.1 1997/11/04 10:33:43 tg Exp
#

DISTNAME=		WindowMaker-0.6.3
PKGNAME=		windowmaker-0.6.3
CATEGORIES=		x11
MASTER_SITES=		http://isolation.ml.org/oxygen/wm/bin/ \
			ftp://wm.wep.net/pub/WindowMaker/

MAINTAINER=		handy@physics.montana.edu

DEPENDS+=		xpm-3.4j:../../graphics/xpm
DEPENDS+=		jpeg-6a:../../graphics/jpeg
DEPENDS+=		png-0.96:../../graphics/png

USE_X11=		yes
GNU_CONFIGURE=		yes
MAKE_ENV+=		INSTALL_SCRIPT="${INSTALL_SCRIPT}"
CONFIGURE_ARGS+=	--includedir=${PREFIX}/include

.include "../../mk/bsd.pkg.mk"
