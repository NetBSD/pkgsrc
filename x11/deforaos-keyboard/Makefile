# $NetBSD: Makefile,v 1.17 2017/08/01 14:59:07 wiz Exp $
#

DISTNAME=	Keyboard-0.3.1
PKGNAME=	deforaos-keyboard-0.3.1
CATEGORIES=	x11
MASTER_SITES=	https://www.defora.org/os/download/download/4453/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://www.defora.org/
COMMENT=	DeforaOS desktop virtual keyboard

LICENSE=	2-clause-bsd

USE_TOOLS+=	pkg-config
USE_TOOLS+=	xgettext

MAKE_FLAGS+=	DESTDIR=${DESTDIR}
MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	CFLAGS=${CFLAGS:Q}
MAKE_FLAGS+=	LDFLAGS=${LDFLAGS:Q}

.include "../../x11/libXtst/buildlink3.mk"
.include "../../x11/deforaos-libdesktop/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
