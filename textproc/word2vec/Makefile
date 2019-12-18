# $NetBSD: Makefile,v 1.2 2019/12/18 00:47:22 minskim Exp $

DISTNAME=	word2vec-0.1c
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=tmikolov/}
GITHUB_TAG=	20c129af10659f7c50e86e3be406df663beff438

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/tmikolov/word2vec
COMMENT=	Tools for computing distributed representation of words
LICENSE=	apache-2.0

NO_CONFIGURE=	yes

INSTALLATION_DIRS+=	bin

do-install:
.for cmd in compute-accuracy distance word2phrase word2vec word-analogy
	${INSTALL_PROGRAM} ${WRKSRC}/${cmd} ${DESTDIR}${PREFIX}/bin
.endfor

.include "../../mk/bsd.pkg.mk"
