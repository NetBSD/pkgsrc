# $NetBSD: Makefile,v 1.143 2024/05/06 08:40:33 jperkin Exp $

DISTNAME=	xorg-server-${XORG_VERSION}
PKGNAME=	modular-${DISTNAME}
PKGREVISION=	2

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Modular X11 server from modular X.org

SPECIAL_PERMS+=		bin/Xorg ${SETUID_ROOT_PERMS}

NOT_FOR_PLATFORM=	Darwin-*-*

.include "Makefile.common"

CONFIGURE_ARGS+=	--enable-xorg
CONFIGURE_ARGS+=	--disable-xephyr
CONFIGURE_ARGS+=	--disable-kdrive

.include "options.mk"

X11_BIN_NAME=	X
.include "../../meta-pkgs/modular-xorg/avoid-duplicate.mk"
.include "../../mk/bsd.pkg.mk"
