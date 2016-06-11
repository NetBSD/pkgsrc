# $NetBSD: Makefile,v 1.1 2016/06/11 23:00:13 kamil Exp $
#

DISTNAME=	i3lock-2.7
CATEGORIES=	x11
MASTER_SITES=	http://i3wm.org/i3lock/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://i3wm.org/i3lock/
COMMENT=	Slightly improved screen locker based on slock
LICENSE=	modified-bsd

USE_TOOLS+=	gmake pkg-config
USE_LANGUAGES=	c99

MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	EGDIR=${EGDIR}
MAKE_FLAGS+=	MANDIR=${PKGMANDIR}

EGDIR=	${PREFIX}/share/examples/${PKGBASE}

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
