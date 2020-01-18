# $NetBSD: Makefile,v 1.5 2020/01/18 23:35:30 rillig Exp $

DISTNAME=		gettext-0.18.1.1
PKGNAME=		po-mode-2.2
PKGREVISION=		1
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_GNU:=gettext/}
EXTRACT_ELEMENTS=	${DISTNAME}/gettext-tools/misc

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.gnu.org/software/gettext/gettext.html
COMMENT=		PO(Portable Object) file editing mode for GNU emacs
LICENSE=		gnu-gpl-v2

WRKSRC=			${WRKDIR}/${DISTNAME}/gettext-tools/misc
NO_CONFIGURE=		YES
INSTALLATION_DIRS+=	${EMACS_LISPPREFIX:C|^${PREFIX}/||}/po-mode

SRCS=			po-compat.el po-mode.el start-po.el

do-build:
.for f in ${SRCS}
	cd ${WRKSRC} && \
		${EMACS_BIN} --no-init-file --no-site-file -batch \
		-f batch-byte-compile ${f}
.endfor

do-install:
	cd ${WRKSRC} && \
		${INSTALL_DATA} ${SRCS} ${SRCS:.el=.elc} \
			${DESTDIR}${EMACS_LISPPREFIX}/po-mode

.include "../../editors/emacs/modules.mk"
.include "../../mk/bsd.pkg.mk"
