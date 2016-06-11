# $NetBSD: Makefile,v 1.1 2016/06/11 22:07:01 kamil Exp $

DISTNAME=	dunst-1.1.0
CATEGORIES=	x11
MASTER_SITES=	http://www.knopwob.org/public/dunst-release/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://knopwob.org/dunst/
COMMENT=	Customizable and lightweight notification-daemon
LICENSE=	modified-bsd

USE_TOOLS+=	gmake

MAKE_FLAGS+=	MANPREFIX=${PREFIX}/${PKGMANDIR}

.include "../../devel/pango/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../x11/libxdg-basedir/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
