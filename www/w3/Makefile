# $NetBSD: Makefile,v 1.3 2001/01/22 12:34:36 jtb Exp $

DISTNAME=		w3-4.0pre.46
PKGNAME=		w3-4.0b46
CATEGORIES=		www
MASTER_SITES=		ftp://ftp.xemacs.org/pub/xemacs/emacs-w3/

MAINTAINER=		jtb@netbsd.org
HOMEPAGE=		http://www.cs.indiana.edu/elisp/w3/docs.html

HAS_CONFIGURE=		YES
CONFIGURE_ARGS+=	"--enable-site-install"
INFO_FILES=		w3.info w3-faq.info

.include "../../mk/bsd.prefs.mk"

.if defined(USE_XEMACS)
DEPENDS+=		xemacs-[0-9]*:../../editors/xemacs
CONFIGURE_ARGS+=	"--with-xemacs"
CONFIGURE_ARGS+=	"--with-package-dir=${PREFIX}/lib/xemacs/xemacs-packages"
PLIST_SRC=		${PKGDIR}/PLIST.xemacs
.else
DEPENDS+= 		emacs-[0-9]*:../../editors/emacs
CONFIGURE_ARGS+=	"--with-emacs"
CONFIGURE_ARGS+=	"--with-lispdir=${PREFIX}/share/emacs/site-lisp/w3"
PLIST_SRC=		${PKGDIR}/PLIST.emacs
.endif

.include "../../mk/bsd.pkg.mk"
