# $NetBSD: Makefile,v 1.20 2023/11/14 14:03:15 wiz Exp $

DISTNAME=	lxinput-0.3.5
PKGREVISION=	17
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lxde/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	youri@NetBSD.org
HOMEPAGE=	https://lxde.org/
COMMENT=	Simple graphical front end to configure keyboard and mouse
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake intltool pkg-config msgfmt

.include "../../x11/gtk2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
