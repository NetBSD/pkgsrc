# $NetBSD: Makefile,v 1.13 2006/03/04 21:30:51 jlam Exp $

DISTNAME=		psgml-1.3.2
PKGNAME=		${EMACS_PKGNAME_PREFIX}${DISTNAME:S/-/-mode-/}
PKGREVISION=		1
CATEGORIES=		textproc editors
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=psgml/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.lysator.liu.se/~lenst/about_psgml/
COMMENT=		SGML/XML mode for Emacs

.include "../../mk/emacs.mk"

.if ${EMACS_FLAVOR} != "emacs"
BUILD_TARGET=	xemacs
.endif

INFO_FILES=	psgml-api.info psgml.info

INSTALLATION_DIRS+=	info

do-install:
	${INSTALL_DATA_DIR} ${EMACS_LISPPREFIX:Q}/psgml-mode
	cd ${WRKSRC} && ${INSTALL_DATA} *.el *.elc			\
		${EMACS_LISPPREFIX:Q}/psgml-mode
	${INSTALL_DATA} ${WRKSRC:Q}/iso88591.map				\
		${EMACS_LISPPREFIX:Q}/psgml-mode
	${INSTALL_DATA} ${WRKSRC:Q}/psgml-api.info ${PREFIX:Q}/info
	${INSTALL_DATA} ${WRKSRC:Q}/psgml.info ${PREFIX:Q}/info

.include "../../mk/bsd.pkg.mk"
