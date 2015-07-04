# $NetBSD: Makefile,v 1.19 2015/07/04 16:18:43 joerg Exp $
#

DISTNAME=	xmove.2.0beta2
PKGNAME=	xmove-2.0b2
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.ntplx.net/pub/unix/source/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Move an X11 display between screens and displays

WRKSRC=		${WRKDIR}/xmove
USE_IMAKE=	yes
XMOVEDOCDIR=	${PREFIX}/share/doc/xmove

INSTALLATION_DIRS=	${XMOVEDOCDIR}

pre-configure:
	@${SED} -e 's|@x11base@|'${PREFIX}'|' < ${WRKSRC}/xmove/Imakefile > ${WRKSRC}/xmove/Imakefile.new && \
		${MV} ${WRKSRC}/xmove/Imakefile.new ${WRKSRC}/xmove/Imakefile
	${CP} ${WRKSRC}/man/man1/xmove.1 ${WRKSRC}/xmove/xmove.man
	${CP} ${WRKSRC}/man/man1/xmovectrl.1 ${WRKSRC}/xmovectrl/xmovectrl.man

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/features.txt ${DESTDIR}${XMOVEDOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/limitations.txt ${DESTDIR}${XMOVEDOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/using_xmove.txt ${DESTDIR}${XMOVEDOCDIR}

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
