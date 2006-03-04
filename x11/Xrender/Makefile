# $NetBSD: Makefile,v 1.29 2006/03/04 21:31:07 jlam Exp $

DISTNAME=	libXrender-0.9.0
PKGNAME=	${DISTNAME:S/lib//}
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://xlibs.freedesktop.org/release/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://fontconfig.org/
COMMENT=	Client library for the X Rendering Extension protocol

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=		pkg-config
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
PKGCONFIG_OVERRIDE=	xrender.pc.in

.include "../../x11/renderext/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
