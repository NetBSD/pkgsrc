# $NetBSD: Makefile,v 1.13 2004/05/15 00:18:06 kristerw Exp $
#

.include "../../meta-pkgs/xfce4/Makefile.common"

XFCE4_VERSION=	2.1.9

DISTNAME=	gtk-xfce-engine-${XFCE4_VERSION}
PKGREVISION=	2
PKGNAME=	xfce4-gtk2-engine-${XFCE4_VERSION}
CATEGORIES=	x11
COMMENT=	XFce4 GTK2 themes
DIST_SUBDIR=	${PKGNAME_NOREV}

USE_DIRS+=	xdg-1.1

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
