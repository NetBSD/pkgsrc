# $NetBSD: Makefile,v 1.1.1.1 2005/06/25 01:55:08 reed Exp $

# Package version reflects icecc version, with PKGREVISION incremented
# for any tool updates, according to the authors scheme.
DISTNAME=		icecc-2.9
PKGREVISION=		1
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

DEPENDS+=		vim-{gtk,gtk2,kde,motif,xaw}>=6.3.0:../../editors/vim-xaw

USE_TOOLS+=		gmake

WRKSRC=			${WRKDIR}

QSRC=			icecc-2.9 icebgset-1.3 iceked-1.5 icemc-2.1
QSRC+=			icesndcfg-1.3 icets-1.4 icewoed-1.8

BUILD_DIRS=		${QSRC:S/^/${WRKSRC}\//}

PYTHON_PATCH_SCRIPTS=	icecursorscfg-0.6/icecurcfg.py iceiconcvt-1.0/iceiconcvt.py
PYTHON_PATCH_SCRIPTS+=	icemergeprefs-0.5/icemergeprefs.py icerrun-0.5/icerrrun.py
PYTHON_PATCH_SCRIPTS+=	icerrun-0.5/icerrun.py

SUBST_CLASSES=		path
SUBST_STAGE.path=	post-patch
SUBST_FILES.path=	icebgset-1.3/icebgset.pro icecc-2.9/icecc.pro iceked-1.5/iceked.pro
SUBST_FILES.path+=	icemc-2.1/icemc.pro icesndcfg-1.3/icesndcfg.pro icets-1.4/icets.pro
SUBST_FILES.path+=	icewoed-1.8/icewoed.pro
SUBST_FILES.path+=	icecursorscfg-0.6/icecurcfg.py iceiconcvt-1.0/iceiconcvt.py
SUBST_FILES.path+=	icemergeprefs-0.5/icemergeprefs.py
SUBST_SED.path=		"s|/usr/local|${PREFIX}|g"
SUBST_MESSAGE.path=	"Fixing hardcoded paths."

# VIM_SUBDIR comes from "editors/vim-share/version.mk"
PLIST_SUBST+=		VIM_SUBDIR=${VIM_SUBDIR}

do-configure:
.   for dir in ${QSRC}
	cd ${WRKSRC}/${dir} && ${QTDIR}/bin/qmake "QMAKE_MKDIR=${MKDIR}" "QMAKE_CHK_DIR_EXISTS=${TEST} -d"
.   endfor

post-build:
	cd ${WRKSRC}/icewm4vim && ${GMAKE} QTDIR=${QTDIR}

post-install:
.   for script in ${PYTHON_PATCH_SCRIPTS}
	${INSTALL_SCRIPT} ${WRKSRC}/${script} ${PREFIX}/bin
.   endfor
	${INSTALL_PROGRAM} ${WRKSRC}/icewm4vim/icecolsel ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/icewm4vim/icefonsel ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/icewm4vim/icewm.vim ${PREFIX}/share/vim/${VIM_SUBDIR}/ftplugin/iceprefs.vim
	${INSTALL_DATA} ${WRKSRC}/icewm4vim/syntax/icewm.vim ${PREFIX}/share/vim/${VIM_SUBDIR}/syntax/iceprefs.vim

.include "../../editors/vim-share/version.mk"
.include "../../lang/python/application.mk"
.include "../../x11/py-qt3-base/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
