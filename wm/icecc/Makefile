# $NetBSD: Makefile,v 1.34 2014/05/09 07:37:23 wiz Exp $

# Package version reflects icecc version, with PKGREVISION incremented
# for any tool updates, according to the authors scheme.
DISTNAME=		icecc-2.9
PKGREVISION=		20
CATEGORIES=		wm
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=icecc/}
DISTFILES=		icecc-2.9.tar.bz2		\
			icebgset-1.3.tar.bz2		\
			icecursorscfg-0.6.tar.bz2	\
			iceked-1.5.tar.bz2		\
			iceiconcvt-1.0.tar.bz2		\
			icemergeprefs-0.5.tar.bz2	\
			icemc-2.1.tar.bz2		\
			icerrun-0.5.tar.bz2		\
			icesndcfg-1.3.tar.bz2		\
			icets-1.4.tar.bz2		\
			icewm4vim.tar.bz2		\
			icewoed-1.8.tar.bz2

MAINTAINER=		plunky@rya-online.net
HOMEPAGE=		http://icecc.sourceforge.net/
COMMENT=		IceWM Control Centre

DEPENDS+=		vim-{gtk,gtk2,kde,motif,xaw}>=${VIM_VERSION}:../../editors/vim-xaw
DEPENDS+=		${PYPKGPREFIX}-qt3-base-[0-9]*:../../x11/py-qt3-base

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake

WRKSRC=			${WRKDIR}

CONFIGURE_DIRS=		icecc-2.9 icebgset-1.3 iceked-1.5 icemc-2.1
CONFIGURE_DIRS+=	icesndcfg-1.3 icets-1.4 icewoed-1.8

REPLACE_PYTHON=	icecursorscfg-0.6/icecurcfg.py iceiconcvt-1.0/iceiconcvt.py
REPLACE_PYTHON+=	icemergeprefs-0.5/icemergeprefs.py icerrun-0.5/icerrrun.py
REPLACE_PYTHON+=	icerrun-0.5/icerrun.py

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # py-qt3-base

SUBST_CLASSES+=		path
SUBST_STAGE.path=	post-patch
SUBST_FILES.path=	icebgset-1.3/icebgset.pro icecc-2.9/icecc.pro iceked-1.5/iceked.pro
SUBST_FILES.path+=	icemc-2.1/icemc.pro icesndcfg-1.3/icesndcfg.pro icets-1.4/icets.pro
SUBST_FILES.path+=	icewoed-1.8/icewoed.pro
SUBST_FILES.path+=	icecursorscfg-0.6/icecurcfg.py iceiconcvt-1.0/iceiconcvt.py
SUBST_FILES.path+=	icemergeprefs-0.5/icemergeprefs.py
SUBST_SED.path=		-e "s|/usr/local|${PREFIX}|g"
SUBST_MESSAGE.path=	Fixing hardcoded paths.

# VIM_SUBDIR comes from "editors/vim-share/version.mk"
PLIST_SUBST+=		VIM_SUBDIR=${VIM_SUBDIR:Q}

INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}
INSTALLATION_DIRS=	bin share/vim/${VIM_SUBDIR}/ftplugin \
			share/vim/${VIM_SUBDIR}/syntax

do-configure:
.   for dir in ${CONFIGURE_DIRS}
	cd ${WRKSRC} && cd ${dir} && ${QTDIR}/bin/qmake QMAKE_MKDIR=${MKDIR:Q} QMAKE_CHK_DIR_EXISTS=${TEST:Q}\ -d
.   endfor

post-build:
	cd ${WRKSRC}/icewm4vim && ${SETENV} ${MAKE_ENV} ${GMAKE} QTDIR=${QTDIR:Q}

post-install:
.   for script in ${REPLACE_PYTHON}
	${INSTALL_SCRIPT} ${WRKSRC}/${script:Q} ${DESTDIR}${PREFIX}/bin
.   endfor
	${INSTALL_PROGRAM} ${WRKSRC}/icewm4vim/icecolsel ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/icewm4vim/icefonsel ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/icewm4vim/icewm.vim ${DESTDIR}${PREFIX}/share/vim/${VIM_SUBDIR}/ftplugin/iceprefs.vim
	${INSTALL_DATA} ${WRKSRC}/icewm4vim/syntax/icewm.vim ${DESTDIR}${PREFIX}/share/vim/${VIM_SUBDIR}/syntax/iceprefs.vim

.include "../../editors/vim-share/version.mk"
.include "../../lang/python/application.mk"
.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
