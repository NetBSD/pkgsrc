# $NetBSD: Makefile,v 1.2 2004/02/04 11:51:57 martti Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

XFCE4_VERSION=	1.0rc3

DISTNAME=	xfce4-menueditor-${XFCE4_VERSION}
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://users.skynet.be/p0llux/files/
COMMENT=	XFce4 menu editor

EXTRACT_SUFX=	.tar.bz2
WRKSRC=		${WRKDIR}/xfce4-menueditor

CONFIGURE_ARGS+=--disable-cvs

.include "../../textproc/libxml2/buildlink2.mk"
.include "../../x11/libxfce4gui/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
