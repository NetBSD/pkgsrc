# $NetBSD: Makefile,v 1.1.1.1 2003/04/29 13:38:59 kei Exp $

DISTNAME=		phoenix-bin-java-1.0
WRKSRC=			${WRKDIR}
CATEGORIES=		www lang
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		kei@netbsd.org
COMMENT=		Java Run Time Environment (JRE) 1.3 plugin for phoenix-bin

DEPENDS+=		sun-jre13-[0-9]*:../../lang/sun-jre13/
DEPENDS+=		phoenix-bin-[0-9]*:../../www/phoenix-bin/

ONLY_FOR_PLATFORM=	NetBSD-1.[6-9]*-i386

NO_CHECKSUM=		YES
NO_BUILDLINK=		YES
NO_EXTRACT=		YES
NO_CONFIGURE=		YES
NO_BUILD=		YES

do-install:
			${LN} -s ${PREFIX}/java/sun-1.3.1/plugin/i386/ns600/libjavaplugin_oji.so ${PREFIX}/lib/phoenix-linux/plugins/libjavaplugin_oji.so

.include "../../mk/bsd.pkg.mk"
