# $NetBSD: Makefile,v 1.1.1.1.2.1 2007/09/03 12:53:33 ghen Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

XFCE4_VERSION=	0.2.6

DISTNAME=	Terminal-${XFCE4_VERSION}
PKGNAME=	xfce4-terminal-${XFCE4_VERSION}
PKGREVISION=	1
CATEGORIES=	x11
COMMENT=	Xfce terminal emulator

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/xfce4-exo/buildlink3.mk"
.include "../../x11/vte/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
