# $NetBSD: Makefile,v 1.1 2003/09/27 14:13:08 grant Exp $

DISTNAME=		MozillaFirebird-bin-java-1.0
WRKSRC=			${WRKDIR}
CATEGORIES=		www lang
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		kei@NetBSD.org
COMMENT=		Java Run Time Environment (JRE) 1.3 plugin for phoenix-bin

DEPENDS+=		sun-jre13-[0-9]*:../../lang/sun-jre13
DEPENDS+=		MozillaFirebird-bin>=0.6.1:../../www/MozillaFirebird-bin

ONLY_FOR_PLATFORM=	NetBSD-1.[6-9]*-i386

NO_CHECKSUM=		YES
NO_BUILDLINK=		YES
NO_EXTRACT=		YES
NO_CONFIGURE=		YES
NO_BUILD=		YES

NS_PLUGINS_DIR=	${PREFIX}/lib/MozillaFirebird-linux/plugins
PLUGIN=		${PREFIX}/java/sun-1.3.1/plugin/i386/ns600/libjavaplugin_oji.so

do-install:
	${INSTALL_DATA_DIR} ${NS_PLUGINS_DIR}
	${LN} -s ${PLUGIN} ${NS_PLUGINS_DIR}/libjavaplugin_oji.so

.include "../../mk/bsd.pkg.mk"
