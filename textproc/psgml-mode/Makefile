# $NetBSD: Makefile,v 1.1.1.1 2003/01/09 20:14:00 wiz Exp $

DISTNAME=		psgml-1.2.5
PKGNAME=		${DISTNAME:S/-/-mode-/}
CATEGORIES=		textproc editors
MASTER_SITES=		http://www.lysator.liu.se/~lenst/about_psgml/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.lysator.liu.se/~lenst/about_psgml/
COMMENT=		SGML/XML mode for Emacs

.include "../../mk/bsd.prefs.mk"

.include "../../mk/emacs.mk"

.if ${EMACS_FLAVOR} != "emacs"
ALL_TARGET=	xemacs
.endif

SRCS=	psgml-api.el psgml-charent.el psgml-debug.el psgml-dtd.el	\
	psgml-edit.el psgml-fs.el psgml-info.el psgml-lucid.el		\
	psgml-maint.el psgml-other.el psgml-parse.el psgml.el
INFO_FILES=	psgml-api.info psgml.info

do-install:
	${INSTALL_DATA_DIR} ${EMACS_LISPPREFIX}/psgml-mode
	cd ${WRKSRC} && ${INSTALL_DATA} *.el *.elc			\
		${EMACS_LISPPREFIX}/psgml-mode
	${INSTALL_DATA} ${WRKSRC}/iso88591.map				\
		${EMACS_LISPPREFIX}/psgml-mode
	${INSTALL_DATA} ${WRKSRC}/psgml-api.info ${PREFIX}/info
	${INSTALL_DATA} ${WRKSRC}/psgml.info ${PREFIX}/info

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
