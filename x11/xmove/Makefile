# $NetBSD: Makefile,v 1.12 2005/06/17 04:49:49 jlam Exp $
#

DISTNAME=	xmove.2.0beta2
PKGNAME=	xmove-2.0b2
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.cs.columbia.edu/pub/xmove/

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Move an X11 display between screens and displays

WRKSRC=		${WRKDIR}/xmove
USE_IMAKE=	yes
XMOVEDOCDIR=	${PREFIX}/share/doc/xmove

pre-configure:
	@${SED} -e 's|@x11base@|'${X11PREFIX}'|' < ${WRKSRC}/xmove/Imakefile > ${WRKSRC}/xmove/Imakefile.new && \
		${MV} ${WRKSRC}/xmove/Imakefile.new ${WRKSRC}/xmove/Imakefile
	${CP} ${WRKSRC}/man/man1/xmove.1 ${WRKSRC}/xmove/xmove.man
	${CP} ${WRKSRC}/man/man1/xmovectrl.1 ${WRKSRC}/xmovectrl/xmovectrl.man

post-install:
	@${INSTALL_DATA_DIR} ${XMOVEDOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/features.txt ${XMOVEDOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/limitations.txt ${XMOVEDOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/using_xmove.txt ${XMOVEDOCDIR}

.include "../../mk/bsd.pkg.mk"
