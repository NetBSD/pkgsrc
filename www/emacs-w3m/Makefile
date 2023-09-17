# $NetBSD: Makefile,v 1.36 2023/09/17 06:47:12 mef Exp $

DISTNAME=	emacs-w3m-1.4.5
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=emacs-w3m/}
GITHUB_TAG=	329cfcfc0448a45a0779ded7b51332a343d02a18

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://emacs-w3m.namazu.org/
COMMENT=	Simple w3m interface for Emacs
LICENSE=	gnu-gpl-v2

#NSTALLATION_DIRS=	${ETCDIR}

USE_TOOLS+=	makeinfo autoconf
INFO_FILES=	YES

DEPENDS+=	w3m{,-img}>=0.5.1nb2:../../www/w3m

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-emacs=${EMACS_BIN:Q}
CONFIGURE_ARGS+=	--with-icondir=${ICONDIR}
CONFIGURE_ARGS+=	--infodir=${PREFIX}/info
BUILD_TARGET=		default
INSTALL_TARGET=		${INSTALL_TARGET.${EMACS_FLAVOR}}
#AKE_FLAGS=		prefix=${DESTDIR}${PREFIX} ICONDIR=${DESTDIR}${ICONDIR}
PLIST_SUBST+=		ETCDIR=${ETCDIR:Q}

WRKSRC=	${WRKDIR}/${PKGBASE}-${GITHUB_TAG}

#SUBST_CLASSES+=		fix-icondir
#SUBST_STAGE.fix-icondir=	pre-configure
#SUBST_FILES.fix-icondir=	Makefile.in w3m.el w3mhack.el
#SUBST_SED.fix-icondir=		-e 's|etc/images/w3m|etc/w3m|g'
#SUBST_SED.fix-icondir+=	-e 's|images/w3m|w3m|g'

EMACS_BUILDLINK=		# empty
EMACS_VERSIONS_ACCEPTED=	emacs21 emacs21nox emacs20 \
				emacs28 emacs28nox \
				xemacs215 xemacs215nox xemacs214 xemacs214nox

.include "../../editors/emacs/modules.mk"

# GNU Emacs 21 or later and XEmacs have GUI support
PLIST_VARS+=	gui
.if (${EMACS_FLAVOR} == "emacs" && ${EMACS_VERSION_MAJOR} > 20) || \
    ${EMACS_FLAVOR} == "xemacs"
PLIST.gui=	yes
.endif

# Work around an xemacs rendering bug for optimized GIFs, see
# <https://github.com/doitian/emacs-w3m>, 2b
.if (${EMACS_FLAVOR} == "xemacs")
DEPENDS+=	gifsicle:../../graphics/gifsicle
.endif

DOCUMENTS=	COPYING ChangeLog ChangeLog.1 README README.ja
ETCDIR=		${ETCDIR.${EMACS_FLAVOR}}
ICONDIR=	${PREFIX}/share/emacs-w3m/icons

INSTALL_TARGET.emacs=	install install-icons
INSTALL_TARGET.xemacs=	install-package
ETCDIR.emacs=		share/emacs/${_EMACS_VERSION_MAJOR}/etc/w3m
ETCDIR.xemacs=		lib/xemacs/site-packages/etc/w3m

pre-configure:
	(cd ${WRKSRC}; autoconf)

post-install:
	for f in ${DOCUMENTS}; do \
		${INSTALL_DATA} ${WRKSRC}/$$f ${DESTDIR}${PREFIX}/share/emacs-w3m/; \
	done

.include "options.mk"

.if (${EMACS_FLAVOR} != "xemacs")
.include "../../devel/apel/buildlink3.mk"
.include "../../devel/semi/buildlink3.mk"
.include "../../editors/mule-ucs/buildlink3.mk"
.endif

.include "../../devel/flim/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
