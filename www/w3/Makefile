# $NetBSD: Makefile,v 1.7 2001/04/28 23:59:22 jtb Exp $

DISTNAME=	w3-4.0pre.46
PKGNAME=	w3-4.0b46
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.xemacs.org/pub/xemacs/emacs-w3/ \
		ftp://ftp.mpi-sb.mpg.de/pub/gnu/mirror/ftp.xemacs.org/xemacs/emacs-w3/ \
		ftp://ftp.usyd.edu.au/pub/Xemacs/emacs-w3/ \
		ftp://ftp.lab.kdd.co.jp/xemacs/emacs-w3/ \
		ftp://ftp.th-darmstadt.de/pub/editors/xemacs/emacs-w3/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.cs.indiana.edu/elisp/w3/docs.html
COMMENT=	World Wide Web browser for Emacs

HAS_CONFIGURE=	#defined
CONFIGURE_ARGS+=--enable-site-install

.include "../../mk/bsd.prefs.mk"

.if defined(USE_XEMACS)
DEPENDS+=	xemacs-[0-9]*:../../editors/xemacs
CONFIGURE_ARGS+=--with-xemacs
CONFIGURE_ARGS+=--with-package-dir=${PREFIX}/lib/xemacs/xemacs-packages
PLIST_SRC=	${PKGDIR}/PLIST.xemacs
.else
DEPENDS+= 	emacs-[0-9]*:../../editors/emacs
CONFIGURE_ARGS+=--with-emacs
CONFIGURE_ARGS+=--with-lispdir=${PREFIX}/share/emacs/site-lisp/w3
INFO_FILES=	w3.info w3-faq.info
PLIST_SRC=	${PKGDIR}/PLIST.emacs
.endif

.include "../../mk/bsd.pkg.mk"
