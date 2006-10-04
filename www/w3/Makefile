# $NetBSD: Makefile,v 1.23 2006/10/04 22:04:10 wiz Exp $

DISTNAME=	w3-4.0pre.47
PKGNAME=	${EMACS_PKGNAME_PREFIX}w3-4.0b47
PKGREVISION=	2
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_XEMACS:=emacs-w3/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/w3/
COMMENT=	World Wide Web browser for Emacs

# included in xemacs-packages
EMACS_VERSIONS_ACCEPTED= emacs21 emacs21nox emacs20
.include "../../mk/emacs.mk"

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-emacs
CONFIGURE_ARGS+=	--enable-site-install
CONFIGURE_ARGS+=	--with-lispdir=${EMACS_LISPPREFIX}/w3
CONFIGURE_ARGS+=	--datadir=${ETCDIR}
INFO_FILES=		# PLIST

.if ${EMACS_FLAVOR} == "xemacs"
ETCDIR=			${EMACS_LISPPREFIX:H}/etc/w3
.else
ETCDIR=			${PREFIX}/share/w3
.endif
PLIST_SUBST+=		ETCDIR=${ETCDIR:S/^${PREFIX}\///:Q}

.include "../../mk/bsd.pkg.mk"
