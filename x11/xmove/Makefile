# New ports collection makefile for:	xmove
# Version required:	2.0b2
# Date created:		Tue Mar 10 22:45:33 GMT 1998
# Whom:			Alistair Crooks agc@netbsd.org
#
# $NetBSD: Makefile,v 1.2 1998/03/16 12:36:33 frueauf Exp $
#

DISTNAME=	xmove.2.0beta2
PKGNAME=	xmove-2.0b2
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.cs.columbia.edu/pub/xmove/

MAINTAINER=	packages@netbsd.org

WRKSRC=		${WRKDIR}/xmove
USE_IMAKE=	yes
CAT1=		xmove.0 xmovectrl.0
XMOVEDOCDIR=	${X11BASE}/share/doc/xmove

pre-configure:
	@${SED} -e 's|@x11base@|'${X11BASE}'|' < ${WRKSRC}/xmove/Imakefile > ${WRKSRC}/xmove/Imakefile.new && \
		${MV} ${WRKSRC}/xmove/Imakefile.new ${WRKSRC}/xmove/Imakefile
	${CP} ${WRKSRC}/man/man1/xmove.1 ${WRKSRC}/xmove/xmove.man
	${CP} ${WRKSRC}/man/man1/xmovectrl.1 ${WRKSRC}/xmovectrl/xmovectrl.man

post-install:
	@${MKDIR} ${XMOVEDOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/features.txt ${XMOVEDOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/limitations.txt ${XMOVEDOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/using_xmove.txt ${XMOVEDOCDIR}

.include <bsd.port.mk>
