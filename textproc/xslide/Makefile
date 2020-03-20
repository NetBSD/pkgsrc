# $NetBSD: Makefile,v 1.13 2020/03/20 11:58:30 nia Exp $
#

DISTNAME=		xslide-0.2.2
PKGNAME=		${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=		3
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=xslide/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://xslide.sourceforge.net/
COMMENT=		XSL major mode for emacs

.include "../../editors/emacs/modules.mk"

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
	${INSTALL_DATA_DIR} ${DESTDIR}${EMACS_LISPPREFIX}/${PKGBASE}
	cd ${WRKSRC} && ${INSTALL_DATA} ${SRCS} ${SRCS:.el=.elc} ${DESTDIR}${EMACS_LISPPREFIX}/${PKGBASE}
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/xslide
	${INSTALL_DATA} ${WRKSRC}/README.TXT ${DESTDIR}${PREFIX}/share/doc/xslide
	${INSTALL_DATA} ${WRKSRC}/dot_emacs ${DESTDIR}${PREFIX}/share/doc/xslide

.include "../../mk/bsd.pkg.mk"
