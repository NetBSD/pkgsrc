# $NetBSD: Makefile,v 1.11 1998/07/04 09:19:09 mycroft Exp $
# FreeBSD Id: Makefile,v 1.1.1.1 1997/11/04 10:33:43 tg Exp
#

DISTNAME=		WindowMaker-0.6.3
PKGNAME=		windowmaker-0.6.3
CATEGORIES=		x11
MASTER_SITES=		http://isolation.ml.org/oxygen/wm/bin/ \
			ftp://wm.wep.net/pub/WindowMaker/

MAINTAINER=		packages@netbsd.org

DEPENDS+=		xpm-3.4k:../../graphics/xpm
DEPENDS+=		jpeg-6b:../../graphics/jpeg
DEPENDS+=		png-0.96:../../graphics/png

USE_X11=		yes
GNU_CONFIGURE=		yes
MAKE_ENV+=		INSTALL_SCRIPT="${INSTALL_SCRIPT}"
CONFIGURE_ARGS+=	--includedir=${PREFIX}/include

INFO_FILES= 		wmaker.info

.include "../../mk/bsd.pkg.mk"
