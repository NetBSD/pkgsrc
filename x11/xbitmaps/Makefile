# $NetBSD: Makefile,v 1.9 2021/12/01 13:01:16 nia Exp $

DISTNAME=		xbitmaps-1.1.2
CATEGORIES=		x11 devel
MASTER_SITES=		${MASTER_SITE_XORG:=data/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		Common X11 bitmaps

GNU_CONFIGURE=		yes

X11_BUILTIN_NAME=	xbitmaps
.include "../../meta-pkgs/modular-xorg/avoid-duplicate.mk"
.include "../../mk/bsd.pkg.mk"
