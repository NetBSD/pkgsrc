# $NetBSD: Makefile,v 1.1.1.1 2003/04/29 13:33:34 kei Exp $

DISTNAME= 		phoenix-bin-acroread-1.0
WRKSRC=			${WRKDIR}
CATEGORIES=		www print
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		kei@netbsd.org
COMMENT=		Acrobat Reader 4 plugin for phoenix-bin

DEPENDS+=		phoenix-bin-[0-9]*:../../www/phoenix-bin
DEPENDS+=		acroread-4.[0-9]*:../../print/acroread

ONLY_FOR_PLATFORM=	NetBSD-*-i386

NO_CHECKSUM=		YES
NO_CONFIGURE=		YES
NO_BUILD=		YES

do-install:
			${LN} -s ${PREFIX}/lib/netscape/plugins/nppdf.so \
				${PREFIX}/lib/phoenix-linux/plugins/nppdf.so

.include "../../mk/bsd.pkg.mk"
