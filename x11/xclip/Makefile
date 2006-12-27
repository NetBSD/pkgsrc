# $NetBSD: Makefile,v 1.10 2006/12/27 13:37:43 joerg Exp $
#

DISTNAME=	xclip-0.08
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	http://people.debian.org/~kims/xclip/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://people.debian.org/~kims/xclip/
COMMENT=	Command line interface to the X windows clipboard

WRKSRC=		${WRKDIR}/xclip
USE_IMAKE=	YES

.include "../../x11/libXmu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
