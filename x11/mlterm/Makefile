# $NetBSD: Makefile,v 1.1.1.1 2001/12/21 11:33:28 agc Exp $

DISTNAME=	mlterm-2.0.0
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mlterm/}

MAINTAINER=	uebayasi@soum.co.jp
HOMEPAGE=	http://mlterm.sourceforge.net/
COMMENT=	Multingual terminal emulator

USE_BUILDLINK_ONLY=	yes

GNU_CONFIGURE=	yes

USE_LIBTOOL=	yes
LIBTOOL_OVERRIDE=	${WRKSRC}/autoconf/libtool
LIBTOOL_OVERRIDE+=	${WRKSRC}/kiklib/autoconf/libtool
LIBTOOL_OVERRIDE+=	${WRKSRC}/mkf/autoconf/libtool

.include "../../devel/glib/buildlink.mk"
.include "../../x11/gtk/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
