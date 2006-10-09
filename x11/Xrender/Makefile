# $NetBSD: Makefile,v 1.32 2006/10/09 12:52:36 joerg Exp $

DISTNAME=	libXrender-0.9.0
PKGNAME=	${DISTNAME:S/lib//}
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://xlibs.freedesktop.org/release/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://fontconfig.org/
COMMENT=	Client library for the X Rendering Extension protocol

CONFLICTS+=	libXrender-[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		pkg-config
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
PKGCONFIG_OVERRIDE=	xrender.pc.in

.include "../../x11/renderproto/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
