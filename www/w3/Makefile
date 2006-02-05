# $NetBSD: Makefile,v 1.19 2006/02/05 23:11:29 joerg Exp $

DISTNAME=	w3-4.0pre.47
PKGNAME=	${EMACS_PKGNAME_PREFIX}w3-4.0b47
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_XEMACS:=emacs-w3/}

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
