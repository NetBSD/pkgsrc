# $NetBSD: Makefile,v 1.34 2008/09/08 07:02:52 dholland Exp $

DISTNAME=	libXrender-0.9.0
PKGNAME=	${DISTNAME:S/lib//}
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	http://xlibs.freedesktop.org/release/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://fontconfig.org/
COMMENT=	Client library for the X Rendering Extension protocol

CONFLICTS+=	libXrender-[0-9]*
.if "${X11_TYPE}" != "native"
PKG_FAIL_REASON+="This package is for native X11 only; use libXrender instead."
.endif

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		pkg-config
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
PKGCONFIG_OVERRIDE=	xrender.pc.in
CONFIGURE_ENV+=		X_LIBS=${X11_LDFLAGS:Q}

.include "../../x11/renderproto/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
