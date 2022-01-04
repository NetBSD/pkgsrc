# $NetBSD: Makefile,v 1.4 2022/01/04 20:55:14 wiz Exp $

DISTNAME=	ddgr-1.9
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=jarun/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/jarun/ddgr
COMMENT=	DuckDuckGo from the terminal
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	# none

INSTALLATION_DIRS=	${PKGMANDIR}/man1

PYTHON_VERSIONS_INCOMPATIBLE=	27

REPLACE_PYTHON+=	ddgr
REPLACE_PYTHON+=	setup.py

EGDIR=			${PREFIX}/share/examples/ddgr/auto-completion

SUBST_CLASSES+=		prefix
SUBST_MESSAGE.prefix=	Fixing paths.
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix+=	Makefile
SUBST_SED.prefix+=	-e 's,/usr/local,${PREFIX},g'
SUBST_SED.prefix+=	-e 's,share/man,${PKGMANDIR},g'

post-install:
	${INSTALL_MAN} ${WRKSRC}/ddgr.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/ddgr.1
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/auto-completion/bash/ddgr-completion.bash \
		${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/auto-completion/fish/ddgr.fish \
		${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/auto-completion/zsh/_ddgr \
		${DESTDIR}${EGDIR}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
