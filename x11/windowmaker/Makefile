# New ports collection makefile for:	WindowMaker
# Version required:	0.6.3
# Date created:		August 13, 1997
# Whom:			handy@physics.montana.edu (FreeBSD)
# 			explorer@netbsd.org (NetBSD)
#
# $NetBSD: Makefile,v 1.6 1998/03/10 16:47:24 frueauf Exp $
# FreeBSD Id: Makefile,v 1.1.1.1 1997/11/04 10:33:43 tg Exp
#

DISTNAME=		WindowMaker-0.6.3
PKGNAME=		windowmaker-0.6.3
CATEGORIES=		x11
MASTER_SITES=		http://isolation.ml.org/oxygen/wm/bin/ \
			ftp://wm.wep.net/pub/WindowMaker/

MAINTAINER=		handy@physics.montana.edu

LIB_DEPENDS=		Xpm.4.:${PORTSDIR}/graphics/xpm \
			png.0.:${PORTSDIR}/graphics/png \
			jpeg.7.:${PORTSDIR}/graphics/jpeg

USE_X11=		yes
GNU_CONFIGURE=		yes
MAKE_ENV+=		INSTALL_SCRIPT="${INSTALL_SCRIPT}"
CONFIGURE_ARGS+=	--includedir=${PREFIX}/include

.include <bsd.port.mk>
