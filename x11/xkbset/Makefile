# $NetBSD: Makefile,v 1.13 2012/10/03 21:59:09 wiz Exp $
#

DISTNAME=	xkbset-0.3
PKGREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	http://www.math.missouri.edu/~stephen/software/xkbset/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.math.missouri.edu/~stephen/software/#xkbset
COMMENT=	Manages XKB features of the X window system

PKG_DESTDIR_SUPPORT=	user-destdir

USE_X11BASE=	yes
USE_TOOLS+=	perl
REPLACE_PERL=	mskacc-gui

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
