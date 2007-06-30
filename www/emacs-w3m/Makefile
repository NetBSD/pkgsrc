# $NetBSD: Makefile,v 1.20 2007/06/30 13:21:13 joerg Exp $

DISTNAME=	emacs-w3m-1.4.4
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${HOMEPAGE}

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	http://emacs-w3m.namazu.org/
COMMENT=	Simple w3m interface for Emacs

USE_TOOLS+=	makeinfo
INFO_FILES=	YES

DEPENDS+=	w3m>=0.5.1nb2:../../www/w3m

.include "../../mk/emacs.mk"

DEPENDS+=	${EMACS_PKGNAME_PREFIX}semi-[0-9]*:../../devel/semi
.if ${EMACS_FLAVOR} == "xemacs"
DEPENDS+=	${EMACS_PKGNAME_PREFIX}apel>=10.3:../../devel/apel
.endif

.if ${EMACS_TYPE} == "emacs21" || ${EMACS_TYPE} == "emacs22"
BUILD_DEPENDS+=	${EMACS_PKGNAME_PREFIX}Mule-UCS>=0.84:../../editors/mule-ucs
.endif

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-emacs=${EMACS_BIN:Q}
BUILD_TARGET=	default
.if ${EMACS_FLAVOR} == "xemacs"
INSTALL_TARGET=	install-package
.else
INSTALL_TARGET=	install install-icons
.endif

DOCUMENTS=	COPYING ChangeLog ChangeLog.1 README README.ja
.if ${EMACS_FLAVOR} == "xemacs"
ETCDIR=	lib/xemacs/site-packages/etc
ICONDIR=	${ETCDIR}/w3m
.else
ETCDIR=	share/emacs/${_EMACS_VERSION_NOREV}/etc
ICONDIR=	${ETCDIR}/images/w3m
.endif
DOCDIR=	${ETCDIR}/w3m/doc
PLIST_SUBST+=	DOCDIR=${DOCDIR:Q}
PLIST_SUBST+=	ICONDIR=${ICONDIR:Q}

post-install:
	@${INSTALL_DATA_DIR} ${PREFIX}/${DOCDIR}
	for f in ${DOCUMENTS}; do ${INSTALL_DATA} ${WRKSRC}/$$f ${PREFIX}/${DOCDIR}; done

.include "../../mk/bsd.pkg.mk"
