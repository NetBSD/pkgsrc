# $NetBSD: Makefile,v 1.3 2002/01/31 14:34:39 agc Exp $

DISTNAME=	mlterm-2.2.0
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mlterm/}

MAINTAINER=	uebayasi@soum.co.jp
HOMEPAGE=	http://mlterm.sourceforge.net/
COMMENT=	Multingual terminal emulator

# CODESET is only supported on NetBSD in 1.5T and later - see <langinfo.h>
ONLY_FOR_PLATFORM=	NetBSD-1.5[T-Z]-* NetBSD-1.5Z[A-Z]-*

USE_BUILDLINK_ONLY=	yes

GNU_CONFIGURE=	yes

USE_LIBTOOL=	yes
LIBTOOL_OVERRIDE=	${WRKSRC}/autoconf/ltmain.sh
LIBTOOL_OVERRIDE+=	${WRKSRC}/kiklib/autoconf/ltmain.sh
LIBTOOL_OVERRIDE+=	${WRKSRC}/mkf/autoconf/ltmain.sh

.include "../../devel/glib/buildlink.mk"
.include "../../x11/gtk/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
