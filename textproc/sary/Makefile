# $NetBSD: Makefile,v 1.1.1.1 2008/03/01 08:29:07 obache Exp $
#

DISTNAME=	sary-1.2.0
CATEGORIES=	textproc
MASTER_SITES=	http://sary.sourceforge.net/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://sary.sourceforge.net/
COMMENT=	Suffix array library and tools

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	sary.pc.in

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
