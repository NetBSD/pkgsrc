# $NetBSD: Makefile,v 1.1 2012/12/17 00:09:34 khorben Exp $
#

DISTNAME=	libDesktop-0.0.8
PKGNAME=	deforaos-libdesktop-0.0.8
CATEGORIES=	x11
MASTER_SITES=	http://www.defora.org/os/download/download/3699/

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
