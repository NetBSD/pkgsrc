# $NetBSD: Makefile,v 1.118 2019/02/27 16:32:58 wiz Exp $

DISTNAME=	xorg-server-${XORG_VERSION}
PKGNAME=	modular-${DISTNAME}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Modular X11 server from modular X.org

SPECIAL_PERMS+=		bin/Xorg ${SETUID_ROOT_PERMS}

NOT_FOR_PLATFORM=	Darwin-*-*

.include "Makefile.common"

CONFIGURE_ARGS+=	--enable-xorg
CONFIGURE_ARGS+=	--disable-xephyr
CONFIGURE_ARGS+=	--disable-kdrive
CONFIGURE_ARGS.SunOS+=	--disable-input-thread

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
