# $NetBSD: Makefile,v 1.4 1998/11/13 01:50:22 frueauf Exp $
#

DISTNAME=	${PKGNAME}-source
PKGNAME=	htmldoc-1.4
WRKSRC=		${WRKDIR}/${PKGNAME}
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.easysw.com/pub/htmldoc/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.easysw.com/~mike/htmldoc/

NOT_FOR_ARCHS=	alpha	#ps-pdf.cpp:3229: Internal compiler error.

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--with-x
MAKE_ENV+=	BINDIR=${PREFIX}/bin \
		MANDIR=${PREFIX}/man

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/htmldoc ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/htmldoc.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
