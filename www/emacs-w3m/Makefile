# $NetBSD: Makefile,v 1.1.1.1 2002/09/16 07:05:01 uebayasi Exp $

DISTNAME=	emacs-w3m-1.3.2
CATEGORIES=	www
MASTER_SITES=	${HOMEPAGE}

MAINTAINER=	uebayasi@netbsd.org
HOMEPAGE=	http://emacs-w3m.namazu.org/
COMMENT=	simple w3m interface for Emacs

DEPENDS+=	{w3m,w3m-img}>=0.3.1:../../www/w3m

HAS_CONFIGURE=	# defined
CONFIGURE_ARGS+=--with-emacs=${EMACS_BIN}
# XXX
#CONFIGURE_ARGS+=--with-icondir=${EMACS_LISPPREFIX}/w3m/icons
ALL_TARGET=	default

# XXX
#post-install:
#	@cd ${WRKSRC} && ${MAKE_PROGRAM} install-icons

.include "../../mk/emacs.mk"
.include "../../mk/bsd.pkg.mk"
