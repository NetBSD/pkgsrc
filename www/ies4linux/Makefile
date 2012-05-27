# $NetBSD: Makefile,v 1.8 2012/05/27 16:11:20 marino Exp $
#

DISTNAME=	ies4linux-2.99.0.1
PKGREVISION=	4
CATEGORIES=	www
MASTER_SITES=	http://www.tatanka.com.br/ies4linux/downloads/

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://www.tatanka.com.br/ies4linux/page/Main_Page
COMMENT=	Microsoft Internet Explorer installer

DEPENDS+=  wget-[0-9]*:../../net/wget
DEPENDS+=  wine-[0-9]*:../../emulators/wine
DEPENDS+=  ${PYPKGPREFIX}-gtk2-[0-9]*:../../x11/py-gtk2
BUILD_DEPENDS+= cabextract-[0-9]*:../../archivers/cabextract

NO_BUILD= 	yes
PKG_DESTDIR_SUPPORT=    user-destdir
USE_LANGUAGES=	# none
USE_TOOLS+=	bash:run pax unzip:run

SHAREDIR=		share/ies4linux

SUBST_CLASSES+= 	sharedir scripts
SUBST_STAGE.sharedir=	post-patch
SUBST_FILES.sharedir=	${WRKSRC}/ies4linux
SUBST_SED.sharedir=	-e "s|.dirname ..0..|${PREFIX}/${SHAREDIR}|g"
SUBST_STAGE.scripts=	post-patch
SUBST_FILES.scripts=	${WRKSRC}/ies4linux \
			${WRKSRC}/lib/install.sh ${WRKSRC}/lib/uninstall.sh
SUBST_SED.scripts=	-e "s|/usr/bin/env bash|/usr/pkg/bin/bash|"

INSTALLATION_DIRS	= bin ${SHAREDIR}

do-install:
	cd ${WRKSRC} && rm -f lib/functions.sh.orig
	cd ${WRKSRC} && rm -fr ui/.svn
	cd ${WRKSRC} && pax -rwppm . ${DESTDIR}${PREFIX}/${SHAREDIR}
	mv ${DESTDIR}${PREFIX}/${SHAREDIR}/ies4linux ${DESTDIR}${PREFIX}/bin

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
