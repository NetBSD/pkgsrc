# $NetBSD: Makefile,v 1.11 2014/01/11 21:01:18 khorben Exp $
#

DISTNAME=	libDesktop-0.1.0
PKGNAME=	deforaos-libdesktop-0.1.0
CATEGORIES=	x11
MASTER_SITES=	http://www.defora.org/os/download/download/4318/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://www.defora.org/
COMMENT=	DeforaOS desktop library

LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config

MAKE_FLAGS+=	DESTDIR=${DESTDIR}
MAKE_FLAGS+=	PREFIX=${PREFIX}

.include "../../devel/deforaos-libsystem/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../textproc/gtk-doc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
