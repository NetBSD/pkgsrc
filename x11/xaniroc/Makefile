# $NetBSD: Makefile,v 1.2 1999/09/28 00:55:53 simonb Exp $
#
# New ports collection makefile for:   xaniroc
# Version required:    0.3
# Date created:        20 Sep 1997
# Whom:                Stefan Zehl <sec@42.org>
#
# FreeBSD: ports/x11/xaniroc/Makefile,v 1.4 1999/08/31 02:50:46 peter Exp
#

DISTNAME=	xaniroc
PKGNAME=	xaniroc-1.02
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.freebird.org/unixware/freebird/x11/utils/ \
		ftp://netlab1.usu.edu/pub/mirror/freebird/x11/utils/
EXTRACT_SUFX=	.src.tar.Z

MAINTAINER=	packages@netbsd.org

USE_IMAKE=	yes

post-extract:
	${MV} ${WRKSRC}/manpage.1 ${WRKSRC}/xaniroc.man

.include "../../mk/bsd.pkg.mk"
