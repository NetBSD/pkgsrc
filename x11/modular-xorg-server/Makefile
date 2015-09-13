# $NetBSD: Makefile,v 1.102 2015/09/13 04:59:35 tnn Exp $

DISTNAME=	xorg-server-${XORG_VERSION}
PKGNAME=	modular-${DISTNAME}
PKGREVISION=	5

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Modular X11 server from modular X.org

SPECIAL_PERMS+=		bin/Xorg ${SETUID_ROOT_PERMS}

.include "Makefile.common"

CONFIGURE_ARGS+=	--enable-xorg
CONFIGURE_ARGS+=	--disable-xephyr
CONFIGURE_ARGS+=	--disable-kdrive

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
