# $NetBSD: Makefile,v 1.4 2005/03/24 21:13:04 wiz Exp $

DISTNAME=	xnodecor-0.1
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.42.org/pub/wmx/contrib/
DISTFILES=	xnodecor.c

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	# none
COMMENT=        Borderless or undecorated window support utility

USE_BUILDLINK3=	yes
USE_X11BASE=	yes
NO_CONFIGURE=	yes

do-extract:
	@${MKDIR} ${WRKSRC}
	${CP} ${FILESDIR}/Makefile ${WRKSRC}
	${CP} ${DISTDIR}/${DISTFILES} ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
