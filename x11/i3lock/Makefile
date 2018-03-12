# $NetBSD: Makefile,v 1.5 2018/03/12 11:17:51 wiz Exp $
#

DISTNAME=	i3lock-2.8
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	https://i3wm.org/i3lock/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://i3wm.org/i3lock/
COMMENT=	Slightly improved screen locker based on slock
LICENSE=	modified-bsd

USE_TOOLS+=	gmake pkg-config
USE_LANGUAGES=	c99

MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	EGDIR=${EGDIR}
MAKE_FLAGS+=	MANDIR=${PKGMANDIR}

EGDIR=	${PREFIX}/share/examples/${PKGBASE}

CPPFLAGS.SunOS+=	-Du_int32_t=uint32_t

MESSAGE_SUBST+=	EGDIR=${EGDIR}

.include "../../devel/libev/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.include "../../x11/xcb-util/buildlink3.mk"
.include "../../x11/xcb-util-image/buildlink3.mk"
.include "../../x11/xcb-util-keysyms/buildlink3.mk"
.include "../../mk/pam.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
