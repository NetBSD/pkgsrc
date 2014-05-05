# $NetBSD: Makefile,v 1.14 2014/05/05 00:48:27 ryoon Exp $
#

DISTNAME=	libDesktop-0.1.0
PKGNAME=	deforaos-libdesktop-0.1.0
PKGREVISION=	3
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
BUILDLINK_API_DEPENDS.gtk-doc+=	gtk-doc>=1.20
.include "../../x11/gtk2/buildlink3.mk"
.include "../../textproc/gtk-doc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
