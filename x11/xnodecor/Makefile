# $NetBSD: Makefile,v 1.3 2004/04/18 07:44:21 snj Exp $
# FreeBSD Id: ports/x11/xnodecor/Makefile,v 1.2 2003/09/09 09:17:20 erwin Exp

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
