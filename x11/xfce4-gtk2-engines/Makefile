# $NetBSD: Makefile,v 1.8 2004/03/08 19:40:46 jmmv Exp $
#

.include "../../meta-pkgs/xfce4/Makefile.common"

XFCE4_VERSION=	2.1.8

DISTNAME=	gtk-xfce-engine-${XFCE4_VERSION}
PKGNAME=	xfce4-gtk2-engine-${XFCE4_VERSION}
PKGREVISION=	2
CATEGORIES=	x11
COMMENT=	XFce4 GTK2 themes

DEPENDS+=	xdg-dirs>=1.1:../../misc/xdg-dirs

.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
