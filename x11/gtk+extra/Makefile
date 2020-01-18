# $NetBSD: Makefile,v 1.26 2020/01/18 23:35:48 rillig Exp $

DISTNAME=	gtk+extra-0.99.17
PKGREVISION=	6
CATEGORIES=	x11
MASTER_SITES=	http://gtkextra.sourceforge.net/src/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gtkextra.sourceforge.net/
COMMENT=	Useful set of GTK+ widgets for creating GUIs

USE_TOOLS+=		gmake
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
