# $NetBSD: Makefile,v 1.5 2003/08/08 18:18:05 jmc Exp $

DISTNAME=		phoenix-bin-java-1.0
PKGREVISION=		1
WRKSRC=			${WRKDIR}
CATEGORIES=		www lang
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		kei@NetBSD.org
COMMENT=		Java Run Time Environment (JRE) 1.3 plugin for phoenix-bin

DEPENDS+=		sun-jre13-[0-9]*:../../lang/sun-jre13
DEPENDS+=		phoenix-bin>=0.6:../../www/phoenix-bin

ONLY_FOR_PLATFORM=	NetBSD-1.[6-9]*-i386

NO_CHECKSUM=		YES
NO_BUILDLINK=		YES
NO_EXTRACT=		YES
NO_CONFIGURE=		YES
NO_BUILD=		YES

NS_PLUGINS_DIR=         ${PREFIX}/lib/MozillaFirebird-linux/plugins
PLUGIN=		${PREFIX}/java/sun-1.3.1/plugin/i386/ns600/libjavaplugin_oji.so

do-install:
	${INSTALL_DATA_DIR} ${NS_PLUGINS_DIR}
	${LN} -s ${PLUGIN} ${NS_PLUGINS_DIR}/libjavaplugin_oji.so

.include "../../mk/bsd.pkg.mk"
