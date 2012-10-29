# $NetBSD: Makefile,v 1.17 2012/10/29 05:06:59 asau Exp $
#

DISTNAME=	xclip-0.11
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xclip/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/xclip/
COMMENT=	Command line interface to the X windows clipboard
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake

.include "../../x11/libXmu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
