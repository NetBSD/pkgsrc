# $NetBSD: Makefile,v 1.24 2012/02/06 12:41:47 wiz Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../meta-pkgs/xfce4/Makefile.common"

XFCE4_VERSION=	0.6.1

DISTNAME=	xfce4-datetime-plugin-${XFCE4_VERSION}
PKGREVISION=	7
CATEGORIES=	time
MASTER_SITES=	http://goodies.xfce.org/releases/xfce4-datetime-plugin/
EXTRACT_SUFX=	.tar.bz2
COMMENT=	Xfce calendar plugin

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../x11/libxfce4gui/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
