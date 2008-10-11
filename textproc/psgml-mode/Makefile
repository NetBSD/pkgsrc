# $NetBSD: Makefile,v 1.19 2008/10/11 09:31:58 uebayasi Exp $

DISTNAME=		psgml-1.3.2
PKGNAME=		${EMACS_PKGNAME_PREFIX}${DISTNAME:S/-/-mode-/}
PKGREVISION=		3
CATEGORIES=		textproc editors
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=psgml/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.lysator.liu.se/~lenst/about_psgml/
COMMENT=		SGML/XML mode for Emacs

PKG_DESTDIR_SUPPORT=	user-destdir

EMACS_MODULES+=		base

.include "../../editors/emacs/modules.mk"

.if ${EMACS_FLAVOR} != "emacs"
BUILD_TARGET=	xemacs
.endif

INFO_FILES=		# PLIST
INSTALLATION_DIRS+=	${EMACS_INFOPREFIX} ${EMACS_LISPPREFIX}/psgml-mode

do-install:
	cd ${WRKSRC} && ${INSTALL_DATA} *.el *.elc			\
		${DESTDIR}${EMACS_LISPPREFIX:Q}/psgml-mode
	${INSTALL_DATA} ${WRKSRC:Q}/iso88591.map			\
		${DESTDIR}${EMACS_LISPPREFIX:Q}/psgml-mode
	cd ${WRKSRC:Q}; for f in *.info *.info-[0-9]*; do		\
		${TEST} ! -f "$$f" ||					\
		${INSTALL_DATA} "$$f" ${DESTDIR}${EMACS_INFOPREFIX:Q};	\
	done

.include "../../mk/bsd.pkg.mk"
