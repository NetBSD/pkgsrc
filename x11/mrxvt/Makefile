# $NetBSD: Makefile,v 1.9 2007/01/30 15:21:25 joerg Exp $
#

DISTNAME=	mrxvt-0.4.1
PKGREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=materm/}

MAINTAINER=	tnn@netilium.org
HOMEPAGE=	http://materm.sourceforge.net/
COMMENT=	Multi-tabbed terminal emulator with Xft support

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake

CONFIGURE_ARGS+=	--enable-xft
CONFIGURE_ARGS+=	--enable-text-shadow
CONFIGURE_ARGS+=	--enable-24bits

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS:M*BSD} || ${OPSYS} == "Darwin" || ${OPSYS} == "DragonFly"
# Make mrxvt setuid root so that tty ownership setting and utmp logging
# function correctly.
#
CONFIGURE_ARGS+=--enable-ttygid
SPECIAL_PERMS=	${PREFIX}/bin/mrxvt ${SETUID_ROOT_PERMS}
.endif

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
