# $NetBSD: Makefile,v 1.18 2020/07/13 06:01:33 kim Exp $

DISTNAME=	Par-1.53.0
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	textproc
MASTER_SITES=	http://www.nicemice.net/par/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.nicemice.net/par/
COMMENT=	Paragraph reformatter, vaguely similar to fmt, but better
LICENSE=	mit

BUILD_TARGET=
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-configure:
	( cd ${WRKSRC}; \
	  ${SED} -E ' \
	    /^(CPPFLAGS|CFLAGS) =/ s/^/# /; \
	    /^LINK1 =/ s/$$/ $${LDFLAGS}/; \
	    ' < protoMakefile > Makefile )

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/par ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/par.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
