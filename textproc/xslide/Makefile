# $NetBSD: Makefile,v 1.1.1.1 2003/09/03 14:55:00 wiz Exp $
#

DISTNAME=		xslide-0.2.2
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=xslide/}

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://xslide.sourceforge.net/
COMMENT=		XSL major mode for emacs

USE_BUILDLINK2=		yes

.include "../../mk/emacs.mk"

.if ${EMACS_FLAVOR} == "emacs"
EMACS=	emacs
.else
EMACS=	xemacs
.endif

SRCS=	xslide-abbrev.el xslide-data.el xslide-font.el xslide-process.el xslide.el

do-build:
	cd ${WRKSRC} &&							\
	for f in ${SRCS}; do						\
	${EMACS} --no-init-file --no-site-file -batch			\
		-l font-lock -l sendmail				\
		-l xslide-data.el -l xslide-abbrev.el -l xslide-font.el \
		-l xslide-process.el -l xslide.el			\
		-f batch-byte-compile $$f;				\
	done

do-install:
	${INSTALL_DATA_DIR} ${EMACS_LISPPREFIX}/${PKGBASE}
	cd ${WRKSRC} && ${INSTALL_DATA} ${SRCS} ${SRCS:.el=.elc} ${EMACS_LISPPREFIX}/${PKGBASE}
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xslide
	${INSTALL_DATA} ${WRKSRC}/README.TXT ${PREFIX}/share/doc/xslide
	${INSTALL_DATA} ${WRKSRC}/dot_emacs ${PREFIX}/share/doc/xslide

.include "../../mk/bsd.pkg.mk"
