# $NetBSD: Makefile,v 1.21 2018/11/14 22:22:38 kleink Exp $
#

DISTNAME=	Keyboard-0.3.1
PKGNAME=	deforaos-keyboard-0.3.1
PKGREVISION=	4
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
