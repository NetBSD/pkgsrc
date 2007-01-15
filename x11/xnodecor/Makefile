# $NetBSD: Makefile,v 1.9 2007/01/15 18:13:31 joerg Exp $

DISTNAME=	xnodecor-0.1
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.42.org/pub/wmx/contrib/
DISTFILES=	xnodecor.c

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	# none
COMMENT=        Borderless or undecorated window support utility

USE_X11BASE=	yes
NO_CONFIGURE=	yes

do-extract:
	@${MKDIR} ${WRKSRC}
	${CP} ${FILESDIR}/Makefile ${WRKSRC}
	${CP} ${DISTDIR}/${DISTFILES} ${WRKSRC}

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
