# $NetBSD: Makefile,v 1.11 2006/02/05 23:11:06 joerg Exp $

DISTNAME=		psgml-1.3.2
PKGNAME=		${EMACS_PKGNAME_PREFIX}${DISTNAME:S/-/-mode-/}
PKGREVISION=		1
CATEGORIES=		textproc editors
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=psgml/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.lysator.liu.se/~lenst/about_psgml/
COMMENT=		SGML/XML mode for Emacs

.include "../../mk/emacs.mk"

.if ${EMACS_FLAVOR} != "emacs"
BUILD_TARGET=	xemacs
.endif

SRCS=	psgml-api.el psgml-charent.el psgml-debug.el psgml-dtd.el	\
	psgml-edit.el psgml-fs.el psgml-ids.el psgml-info.el 		\
	psgml-lucid.el psgml-maint.el psgml-other.el psgml-parse.el	\
	psgml-sysdep.el	psgml.el
INFO_FILES=	psgml-api.info psgml.info

INSTALLATION_DIRS+=	info

do-install:
	${INSTALL_DATA_DIR} ${EMACS_LISPPREFIX}/psgml-mode
	cd ${WRKSRC} && ${INSTALL_DATA} *.el *.elc			\
		${EMACS_LISPPREFIX}/psgml-mode
	${INSTALL_DATA} ${WRKSRC}/iso88591.map				\
		${EMACS_LISPPREFIX}/psgml-mode
	${INSTALL_DATA} ${WRKSRC}/psgml-api.info ${PREFIX}/info
	${INSTALL_DATA} ${WRKSRC}/psgml.info ${PREFIX}/info

.include "../../mk/bsd.pkg.mk"
