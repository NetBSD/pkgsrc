# $NetBSD: Makefile,v 1.6 2005/07/21 16:30:01 wiz Exp $

DISTNAME=	gtkterm2-0.2.3
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gtkterm/}

MAINTAINER=	yui@yui.pe.kr
HOMEPAGE=	http://gtkterm.feige.net/
COMMENT=	Simple GTK-2 terminal with tabs

USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES

.include "../../devel/pkg-config/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/vte/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
