# $NetBSD: Makefile,v 1.1.1.1 2004/07/03 09:08:06 xtraeme Exp $

DISTNAME=		gtkterm2-0.2.1
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gtkterm/}

MAINTAINER=		yui@yui.pe.kr
HOMEPAGE=		http://gtkterm.feige.net/
COMMENT=		Simple GTK-2 terminal with tabs

USE_LIBTOOL=		YES
USE_BUILDLINK3=		YES
GNU_CONFIGURE=		YES
USE_X11=		YES
USE_PKGLOCALEDIR=	YES

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/vte/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
