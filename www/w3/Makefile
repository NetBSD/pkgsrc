# $NetBSD: Makefile,v 1.20 2006/03/04 21:31:04 jlam Exp $

DISTNAME=	w3-4.0pre.47
PKGNAME=	${EMACS_PKGNAME_PREFIX}w3-4.0b47
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_XEMACS:=emacs-w3/}

MAINTAINER=	pkgsrc-users@NetBSD.org
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
