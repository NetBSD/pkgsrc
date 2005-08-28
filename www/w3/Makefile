# $NetBSD: Makefile,v 1.17 2005/08/28 04:25:31 uebayasi Exp $

DISTNAME=	w3-4.0pre.47
PKGNAME=	${EMACS_PKGNAME_PREFIX}w3-4.0b47
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

# included in xemacs-packages
EMACS_VERSIONS_ACCEPTED= emacs21 emacs21nox emacs20
.include "../../mk/emacs.mk"

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-emacs
CONFIGURE_ARGS+=--with-lispdir=${EMACS_LISPPREFIX}/w3
INFO_FILES=	w3.info w3-faq.info
PLIST_SRC=	${PKGDIR}/PLIST.emacs

.include "../../mk/bsd.pkg.mk"
