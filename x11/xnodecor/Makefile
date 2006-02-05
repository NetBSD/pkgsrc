# $NetBSD: Makefile,v 1.7 2006/02/05 23:11:48 joerg Exp $

DISTNAME=	xnodecor-0.1
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.42.org/pub/wmx/contrib/
DISTFILES=	xnodecor.c

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	# none
COMMENT=        Borderless or undecorated window support utility

USE_X11BASE=	yes
NO_CONFIGURE=	yes

.include "../../mk/x11.buildlink3.mk"

do-extract:
	@${MKDIR} ${WRKSRC}
	${CP} ${FILESDIR}/Makefile ${WRKSRC}
	${CP} ${DISTDIR}/${DISTFILES} ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
