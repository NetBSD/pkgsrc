# $NetBSD: Makefile,v 1.4 2003/07/17 22:55:14 grant Exp $
#

DISTNAME=	larswm-7.2.10
CATEGORIES=	wm x11
MASTER_SITES=	http://www-personal.umich.edu/~larsb/larswm/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DOCFILES}

MAINTAINER=	jschauma@NetBSD.org
HOMEPAGE=	http://www-personal.umich.edu/~larsb/larswm/
COMMENT=	9wm-like window manager

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

DOCFILES=	keyboard_refcard.pdf mouse_refcard.pdf

USE_PKGINSTALL=	YES
USE_IMAKE=	YES

EGDIR=		${PREFIX}/share/examples/larswm
CONF_FILES=	${EGDIR}/sample.larswmrc ${PKG_SYSCONFDIR}/larswmrc

CPPFLAGS=	-DPKG_SYSCONFDIR=\"\\\"${PKG_SYSCONFDIR}\\\"\"

post-patch:
	@cd ${WRKSRC} &&					\
	(							\
		${MV} larswm.man larswm.man.orig;		\
		${SED} ${FILES_SUBST_SED} larswm.man.orig >	\
			larswm.man;				\
	)

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/larswm
.for pdf in ${DOCFILES}
	${INSTALL_DATA} ${DISTDIR}/${pdf} ${PREFIX}/share/doc/larswm
.endfor
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/sample.* ${EGDIR}

.include "../../mk/bsd.pkg.mk"
