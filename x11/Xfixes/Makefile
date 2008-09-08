# $NetBSD: Makefile,v 1.24 2008/09/08 07:02:52 dholland Exp $
#

DISTNAME=		libXfixes-2.0.1
PKGNAME=		${DISTNAME:S/libX/X/}
PKGREVISION=		4
CATEGORIES=		x11 devel
MASTER_SITES=		http://xlibs.freedesktop.org/release/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://freedesktop.org/
COMMENT=		X Fixes extension of X RandR

CONFLICTS+=		libXfixes-[0-9]*
.if "${X11_TYPE}" != "native"
PKG_FAIL_REASON+="This package is for native X11 only; use libXfixes instead."
.endif

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=		pkg-config
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	xfixes.pc.in

.include "../../mk/bsd.prefs.mk"
.if (${OPSYS} == "Darwin")
CFLAGS+=	-fno-common
.endif

.include "../../x11/fixesproto/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
