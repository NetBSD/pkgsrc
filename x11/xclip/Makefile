# $NetBSD: Makefile,v 1.12 2008/03/08 20:42:02 tnn Exp $
#

DISTNAME=	xclip-0.10
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xclip/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/xclip/
COMMENT=	Command line interface to the X windows clipboard

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake

.include "../../x11/libXmu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
