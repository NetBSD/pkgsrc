# New ports collection makefile for:	WindowMaker
# Version required:	0.6.3
# Date created:		August 13, 1997
# Whom (FreeBSD):	handy@physics.montana.edu
# Whom (NetBSD):	explorer@netbsd.org
#
# FreBSD Id: Makefile,v 1.1.1.1 1997/11/04 10:33:43 tg Exp
# $NetBSD: Makefile,v 1.1.1.1 1997/12/08 13:28:51 explorer Exp $
#

DISTNAME=	WindowMaker-0.6.3
PKGNAME=	windowmaker-0.6.3
CATEGORIES=	x11
MASTER_SITES=	http://isolation.ml.org/oxygen/wm/bin/ \
		ftp://wm.wep.net/pub/WindowMaker/

MAINTAINER=	handy@physics.montana.edu

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm \
		png\\.0\\.:${PORTSDIR}/graphics/png \
		jpeg\\.7\\.:${PORTSDIR}/graphics/jpeg

USE_X11=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
STRIP=

.include <bsd.port.mk>
