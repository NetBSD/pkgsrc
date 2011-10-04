# $NetBSD: Makefile,v 1.16 2011/10/04 20:55:35 shattered Exp $
#

DISTNAME=	xclip-0.11
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xclip/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/xclip/
COMMENT=	Command line interface to the X windows clipboard
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake

.include "../../x11/libXmu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
