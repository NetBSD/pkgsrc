# $NetBSD: Makefile,v 1.4 2001/02/17 22:09:54 agc Exp $
# from FreeBSD: ports/x11/xaniroc/Makefile,v 1.4 1999/08/31 02:50:46 peter Exp
#

DISTNAME=	xaniroc
PKGNAME=	xaniroc-1.02
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.freebird.org/unixware/freebird/x11/utils/ \
		ftp://netlab1.usu.edu/pub/mirror/freebird/x11/utils/
EXTRACT_SUFX=	.src.tar.Z

MAINTAINER=	packages@netbsd.org
COMMENT=	animate your root-cursor

USE_IMAKE=	yes

post-extract:
	${MV} ${WRKSRC}/manpage.1 ${WRKSRC}/xaniroc.man

.include "../../mk/bsd.pkg.mk"
