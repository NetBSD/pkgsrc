# $NetBSD: Makefile,v 1.6 2004/10/03 00:18:39 tv Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

XFCE4_VERSION=	1.05

DISTNAME=	xfce4-menueditor-${XFCE4_VERSION}
PKGREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	http://users.skynet.be/p0llux/files/
COMMENT=	XFce4 menu editor

EXTRACT_SUFX=	.tar.bz2
WRKSRC=		${WRKDIR}/xfce4-menueditor

CONFIGURE_ARGS+=--disable-cvs

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/libxfce4gui/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
