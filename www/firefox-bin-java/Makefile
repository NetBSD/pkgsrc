# $NetBSD: Makefile,v 1.7 2004/10/01 10:37:33 grant Exp $

DISTNAME=		firefox-bin-java-1.1
PKGREVISION=		1
CATEGORIES=		www lang
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		kei@NetBSD.org
COMMENT=		Java Run Time Environment (JRE) 1.3 plugin for firefox-bin

DEPENDS+=		sun-jre14-[0-9]*:../../lang/sun-jre14
DEPENDS+=		firefox-bin>=0.8:../../www/firefox-bin

ONLY_FOR_PLATFORM=	Linux-*-i386 NetBSD-1.6*-i386 NetBSD-[2-9]*-i386

WRKSRC=			${WRKDIR}
NO_CHECKSUM=		YES
NO_BUILDLINK=		YES
NO_EXTRACT=		YES
NO_CONFIGURE=		YES
NO_BUILD=		YES

NS_PLUGINS_DIR=	${PREFIX}/lib/firefox-linux/plugins
PLUGIN=		${PREFIX}/java/sun-1.4/plugin/i386/ns610-gcc32/libjavaplugin_oji.so

do-install:
	${INSTALL_DATA_DIR} ${NS_PLUGINS_DIR}
	${LN} -s ${PLUGIN} ${NS_PLUGINS_DIR}/libjavaplugin_oji.so

.include "../../mk/bsd.pkg.mk"
