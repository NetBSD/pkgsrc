# $NetBSD: Makefile,v 1.9 2020/01/18 23:35:32 rillig Exp $
#

DISTNAME=	sary-1.2.0
PKGREVISION=	4
CATEGORIES=	textproc
MASTER_SITES=	http://sary.sourceforge.net/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sary.sourceforge.net/
COMMENT=	Suffix array library and tools
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	sary.pc.in

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
