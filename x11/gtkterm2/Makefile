# $NetBSD: Makefile,v 1.15 2009/06/11 08:10:26 wiz Exp $

DISTNAME=	gtkterm2-0.2.3
PKGREVISION=	6
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gtkterm/}

MAINTAINER=	yui@yui.pe.kr
HOMEPAGE=	http://gtkterm.feige.net/
COMMENT=	Simple GTK-2 terminal with tabs

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		pkg-config
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES

.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/vte/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
