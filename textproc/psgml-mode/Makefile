# $NetBSD: Makefile,v 1.16 2006/06/15 13:43:57 wiz Exp $

DISTNAME=		psgml-1.3.2
PKGNAME=		${EMACS_PKGNAME_PREFIX}${DISTNAME:S/-/-mode-/}
PKGREVISION=		3
CATEGORIES=		textproc editors
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=psgml/}

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://www.lysator.liu.se/~lenst/about_psgml/
COMMENT=		SGML/XML mode for Emacs

EMACS_MODULES+=		base

.include "../../mk/emacs.mk"

.if ${EMACS_FLAVOR} != "emacs"
BUILD_TARGET=	xemacs
.endif

INFO_FILES=		# PLIST
INSTALLATION_DIRS+=	${EMACS_INFOPREFIX} ${EMACS_LISPPREFIX}/psgml-mode

do-install:
	cd ${WRKSRC} && ${INSTALL_DATA} *.el *.elc			\
		${EMACS_LISPPREFIX:Q}/psgml-mode
	${INSTALL_DATA} ${WRKSRC:Q}/iso88591.map			\
		${EMACS_LISPPREFIX:Q}/psgml-mode
	cd ${WRKSRC:Q}; for f in *.info *.info-[0-9]*; do		\
		${TEST} ! -f "$$f" ||					\
		${INSTALL_DATA} "$$f" ${EMACS_INFOPREFIX:Q};		\
	done

.include "../../mk/bsd.pkg.mk"
