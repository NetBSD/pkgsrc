# $NetBSD: Makefile,v 1.4 2003/07/17 22:55:32 grant Exp $

DISTNAME=	emacs-w3m-1.3.3
CATEGORIES=	www
MASTER_SITES=	${HOMEPAGE}

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	http://emacs-w3m.namazu.org/
COMMENT=	simple w3m interface for Emacs

EMACS_DEPENDS+=	{w3m,w3m-img}>=0.3.1:../../www/w3m
BUILD_DEPENDS+=	semi-*:../../devel/semi

.include "../../mk/emacs.mk"

# Not tested with xemacs...
EMACS_VERSIONS_ACCEPTED=	emacs21 emacs20 xemacs211 xemacs215

.if ${EMACS_FLAVOR} == "xemacs"
EMACS_DEPENDS+=	apel>=10.3:../../devel/apel
BUILD_DEPENDS+=	mew-xemacs-*:../../mail/mew-xemacs
.else
BUILD_DEPENDS+=	mew-*:../../mail/mew
.endif

EMACS_MAJOR_VERSION=	${EMACS_VERSION:C/\..*//}
.if ${EMACS_FLAVOR} == "emacs" && ${EMACS_MAJOR_VERSION} == 21
EMACS_DEPENDS+=	Mule-UCS>=0.84:../../editors/mule-ucs
.endif

HAS_CONFIGURE=	# defined
CONFIGURE_ARGS+=--with-emacs=${EMACS_BIN}
ALL_TARGET=	default
.if ${EMACS_FLAVOR} == "xemacs"
INSTALL_TARGET=	install-package
.else
INSTALL_TARGET=	install install-icons
.endif

DOCUMENTS=	COPYING ChangeLog ChangeLog.1 FAQ FAQ.ja README README.ja README.namazu.ja README.shimbun.ja TIPS TIPS.ja
.if ${EMACS_FLAVOR} == "xemacs"
ETCDIR=	lib/xemacs/site-packages/etc
ICONDIR=	${ETCDIR}/w3m
.else
ETCDIR=	share/emacs/${EMACS_VERSION}/etc
ICONDIR=	${ETCDIR}/w3m/icons
.endif
DOCDIR=	${ETCDIR}/w3m/doc
PLIST_SUBST+=	DOCDIR=${DOCDIR}
PLIST_SUBST+=	ICONDIR=${ICONDIR}

post-install:
	@${MKDIR} ${PREFIX}/${DOCDIR}
	for f in ${DOCUMENTS}; do ${INSTALL_DATA} ${WRKSRC}/$$f ${PREFIX}/${DOCDIR}; done

.include "../../mk/bsd.pkg.mk"
