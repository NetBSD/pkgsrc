# $NetBSD: Makefile,v 1.4 2012/02/06 12:41:45 wiz Exp $
#

DISTNAME=	sary-1.2.0
PKGREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	http://sary.sourceforge.net/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://sary.sourceforge.net/
COMMENT=	Suffix array library and tools
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	sary.pc.in

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
