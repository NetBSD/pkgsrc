# $NetBSD: Makefile,v 1.29 2013/04/06 20:27:29 rodent Exp $

DISTNAME=	w3-4.0pre.47
PKGNAME=	${EMACS_PKGNAME_PREFIX}w3-4.0b47
PKGREVISION=	3
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_XEMACS:=emacs-w3/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/w3/
COMMENT=	World Wide Web browser for Emacs

# included in xemacs-packages
# emacs22 doesn't work
EMACS_VERSIONS_ACCEPTED=	emacs21 emacs21nox emacs20

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-emacs
CONFIGURE_ARGS+=	--enable-site-install
CONFIGURE_ARGS+=	--with-lispdir=${EMACS_LISPPREFIX}/w3
CONFIGURE_ARGS+=	--datadir=${ETCDIR}
INFO_FILES=		yes

PLIST_SUBST+=	ETCDIR=${ETCDIR:S/^${PREFIX}\///:Q}

ETCDIR=		${ETCDIR.${EMACS_FLAVOR}}

ETCDIR.emacs=	${PREFIX}/share/w3
ETCDIR.xemacs=	${EMACS_LISPPREFIX:H}/etc/w3

.include "../../editors/emacs/modules.mk"

.include "../../mk/bsd.pkg.mk"
