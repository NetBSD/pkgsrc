# $NetBSD: Makefile,v 1.131 2021/12/03 13:05:59 nia Exp $

DISTNAME=	xorg-server-${XORG_VERSION}
PKGNAME=	modular-${DISTNAME}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Modular X11 server from modular X.org

SPECIAL_PERMS+=		bin/Xorg ${SETUID_ROOT_PERMS}

NOT_FOR_PLATFORM=	Darwin-*-*

CONFLICTS+=		libxcvt-[0-9]*

.include "Makefile.common"

CONFIGURE_ARGS+=	--enable-xorg
CONFIGURE_ARGS+=	--disable-xephyr
CONFIGURE_ARGS+=	--disable-xwayland
CONFIGURE_ARGS+=	--disable-kdrive

.include "options.mk"

X11_BUILTIN_NAME=	modular-xorg-server
.include "../../meta-pkgs/modular-xorg/avoid-duplicate.mk"
.include "../../mk/bsd.pkg.mk"
