# $NetBSD: Makefile,v 1.1 2004/02/10 12:55:20 grant Exp $

DISTNAME=		firefox-bin-java-1.0
CATEGORIES=		www lang
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		kei@NetBSD.org
COMMENT=		Java Run Time Environment (JRE) 1.3 plugin for phoenix-bin

DEPENDS+=		sun-jre13-[0-9]*:../../lang/sun-jre13
DEPENDS+=		firefox-bin>=0.8:../../www/firefox-bin

ONLY_FOR_PLATFORM=	NetBSD-1.[6-9]*-i386

WRKSRC=			${WRKDIR}
NO_CHECKSUM=		YES
NO_BUILDLINK=		YES
NO_EXTRACT=		YES
NO_CONFIGURE=		YES
NO_BUILD=		YES

NS_PLUGINS_DIR=	${PREFIX}/lib/firefox-linux/plugins
PLUGIN=		${PREFIX}/java/sun-1.3.1/plugin/i386/ns600/libjavaplugin_oji.so

do-install:
	${INSTALL_DATA_DIR} ${NS_PLUGINS_DIR}
	${LN} -s ${PLUGIN} ${NS_PLUGINS_DIR}/libjavaplugin_oji.so

.include "../../mk/bsd.pkg.mk"
