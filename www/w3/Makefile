# $NetBSD: Makefile,v 1.15 2003/08/09 11:32:32 seb Exp $

DISTNAME=	w3-4.0pre.47
PKGNAME=	w3-4.0b47
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.xemacs.org/pub/xemacs/emacs-w3/ \
		ftp://ftp.mpi-sb.mpg.de/pub/gnu/mirror/ftp.xemacs.org/xemacs/emacs-w3/ \
		ftp://ftp.usyd.edu.au/pub/Xemacs/emacs-w3/ \
		ftp://ftp.lab.kdd.co.jp/xemacs/emacs-w3/ \
		ftp://ftp.th-darmstadt.de/pub/editors/xemacs/emacs-w3/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.cs.indiana.edu/elisp/w3/docs.html
COMMENT=	World Wide Web browser for Emacs

CONFIGURE_ARGS+=--enable-site-install

.include "../../mk/emacs.mk"

.if ${EMACS_FLAVOR} == "xemacs"
HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-xemacs
CONFIGURE_ARGS+=--with-package-dir=${PREFIX}/lib/xemacs/xemacs-packages
PLIST_SRC=	${PKGDIR}/PLIST.xemacs
.else
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-emacs
CONFIGURE_ARGS+=--with-lispdir=${EMACS_LISPPREFIX}/w3
INFO_FILES=	w3.info w3-faq.info
PLIST_SRC=	${PKGDIR}/PLIST.emacs
.endif

.include "../../mk/bsd.pkg.mk"
