# $NetBSD: Makefile,v 1.1.1.1 2004/12/21 02:59:57 xtraeme Exp $

DISTNAME=	firefox-gtk2-bin-acroread-1.0
CATEGORIES=	www print
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.adobe.com/products/acrobat/readermain.html
COMMENT=	Acrobat Reader 5 plugin for firefox-gtk2-bin

DEPENDS+=	acroread5>=5.10nb1:../../print/acroread
DEPENDS+=	firefox-gtk2-bin>=0.10.1:../../www/firefox-gtk2-bin

ONLY_FOR_PLATFORM=	Linux-*-i386 NetBSD-*-i386
PLATFORM=		intellinux

WRKSRC=			${WRKDIR}
NO_CHECKSUM=		YES
NO_CONFIGURE=		YES
NO_BUILD=		YES

ACROREAD=		Acrobat5

PLIST_SRC=		../../www/firefox-gtk2-bin-acroread/PLIST
PLIST_SUBST+=		ACROREAD=${ACROREAD}
PLIST_SUBST+=		PLATFORM=${PLATFORM}
NS_PLUGINS_DIR=		${PREFIX}/lib/firefox-gtk2-linux/plugins

do-install:
	${INSTALL_DATA_DIR} ${NS_PLUGINS_DIR}
	${LN} -sf ${PREFIX}/${ACROREAD}/Browsers/${PLATFORM}/nppdf.so \
		${NS_PLUGINS_DIR}/nppdf.so

.include "../../mk/bsd.pkg.mk"
