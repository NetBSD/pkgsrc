# $NetBSD: Makefile,v 1.6 2013/06/15 12:27:47 khorben Exp $
#

DISTNAME=	Keyboard-0.2.1
PKGNAME=	deforaos-keyboard-0.2.1
PKGREVISION=	6
CATEGORIES=	x11
MASTER_SITES=	http://www.defora.org/os/download/download/3696/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://www.defora.org/
COMMENT=	DeforaOS desktop virtual keyboard

LICENSE=	gnu-gpl-v3

CONFLICTS+=	gnome-control-center>=2.20.1{,nb*}

USE_TOOLS+=	pkg-config
USE_TOOLS+=	xgettext

MAKE_FLAGS+=	DESTDIR=${DESTDIR}
MAKE_FLAGS+=	PREFIX=${PREFIX}

.include "../../x11/libXtst/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/deforaos-libdesktop/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
