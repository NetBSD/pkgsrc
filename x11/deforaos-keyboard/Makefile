# $NetBSD: Makefile,v 1.12 2016/03/12 02:22:08 khorben Exp $
#

DISTNAME=	Keyboard-0.3.0
PKGNAME=	deforaos-keyboard-0.3.0
CATEGORIES=	x11
MASTER_SITES=	http://www.defora.org/os/download/download/4436/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://www.defora.org/
COMMENT=	DeforaOS desktop virtual keyboard

LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config
USE_TOOLS+=	xgettext

MAKE_FLAGS+=	DESTDIR=${DESTDIR}
MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	CFLAGS=${CFLAGS:Q}
MAKE_FLAGS+=	LDFLAGS=${LDFLAGS:Q}

.include "../../x11/libXtst/buildlink3.mk"
.include "../../x11/deforaos-libdesktop/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
