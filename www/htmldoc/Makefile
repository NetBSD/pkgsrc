# $NetBSD: Makefile,v 1.12 2001/05/13 01:16:23 dmcmahill Exp $
#

DISTNAME=		${PKGNAME}-source
PKGNAME=		htmldoc-1.7
WRKSRC=			${WRKDIR}/${PKGNAME}
CATEGORIES=		www
MASTER_SITES=		ftp://ftp.easysw.com/pub/htmldoc/1.7/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.easysw.com/~mike/htmldoc/
COMMENT=		Converts HTML to indexed HTML, PDF and/or PostScript

DEPENDS+=		jpeg-6b:../../graphics/jpeg
DEPENDS+=		png>1.0.9:../../graphics/png

NOT_FOR_PLATFORM=	NetBSD-1.[3-4]*-alpha	#ps-pdf.cpp:3229: Internal compiler error. on 1.4 - 1.7 unknown

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-x
MAKE_ENV+=		CPPFLAGS=-L${LOCALBASE}/lib \
			BINDIR=${PREFIX}/bin \
			MANDIR=${PREFIX}/man

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/htmldoc ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/htmldoc.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
