# $NetBSD: Makefile,v 1.9 2000/03/21 22:40:58 tron Exp $
#

DISTNAME=		${PKGNAME}-source
PKGNAME=		htmldoc-1.7
WRKSRC=			${WRKDIR}/${PKGNAME}
CATEGORIES=		www
MASTER_SITES=		ftp://ftp.easysw.com/pub/htmldoc/1.7/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.easysw.com/~mike/htmldoc/

DEPENDS+=		jpeg-6b:../../graphics/jpeg
DEPENDS+=		png>=1.0.6:../../graphics/png

NOT_FOR_PLATFORM=	*-*-alpha	#ps-pdf.cpp:3229: Internal compiler error. on 1.4 - 1.7 unknown

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-x
MAKE_ENV+=		CPPFLAGS=-L${LOCALBASE}/lib \
			BINDIR=${PREFIX}/bin \
			MANDIR=${PREFIX}/man

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/htmldoc ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/htmldoc.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
