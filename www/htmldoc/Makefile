# $NetBSD: Makefile,v 1.3 1998/09/22 06:11:41 garbled Exp $
#

DISTNAME=	${PKGNAME}-source
PKGNAME=	htmldoc-1.4
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.easysw.com/pub/htmldoc/

NOT_FOR_ARCHS=	alpha	#ps-pdf.cpp:3229: Internal compiler error.

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.easysw.com/~mike/htmldoc/

GNU_CONFIGURE=	YES
WRKSRC=		${WRKDIR}/${PKGNAME}
CONFIGURE_ARGS+=	--with-x
MAKE_ENV+=	BINDIR=${PREFIX}/bin \
		MANDIR=${PREFIX}/man

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/htmldoc ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/htmldoc.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
