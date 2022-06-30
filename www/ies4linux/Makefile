# $NetBSD: Makefile,v 1.24 2022/06/30 11:18:58 nia Exp $

DISTNAME=	ies4linux-2.99.0.1
PKGREVISION=	8
CATEGORIES=	www
MASTER_SITES=	http://www.tatanka.com.br/ies4linux/downloads/

MAINTAINER=	abs@NetBSD.org
#HOMEPAGE=	http://www.tatanka.com.br/ies4linux/page/Main_Page
COMMENT=	Microsoft Internet Explorer installer

DEPENDS+=	wget-[0-9]*:../../net/wget
DEPENDS+=	wine-[0-9]*:../../emulators/wine
DEPENDS+=	${PYPKGPREFIX}-gtk2-[0-9]*:../../x11/py-gtk2
BUILD_DEPENDS+=	cabextract-[0-9]*:../../archivers/cabextract

NO_BUILD=	yes
USE_LANGUAGES=	# none
USE_TOOLS+=	bash:run pax unzip:run
PYTHON_VERSIONS_ACCEPTED= 27 # py-gtk2

SHAREDIR=		share/ies4linux

SUBST_CLASSES+=		sharedir
SUBST_STAGE.sharedir=	pre-configure
SUBST_FILES.sharedir=	${WRKSRC}/ies4linux
SUBST_SED.sharedir=	-e "s|.dirname ..0..|${PREFIX}/${SHAREDIR}|g"

REPLACE_BASH=		${WRKSRC}/ies4linux \
			${WRKSRC}/lib/install.sh ${WRKSRC}/lib/uninstall.sh

INSTALLATION_DIRS=	bin ${SHAREDIR}

do-install:
	cd ${WRKSRC} && rm -f lib/functions.sh.orig
	cd ${WRKSRC} && rm -fr ui/.svn
	cd ${WRKSRC} && pax -rwppm . ${DESTDIR}${PREFIX}/${SHAREDIR}
	mv ${DESTDIR}${PREFIX}/${SHAREDIR}/ies4linux ${DESTDIR}${PREFIX}/bin

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
