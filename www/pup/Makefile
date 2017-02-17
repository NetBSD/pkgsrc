# $NetBSD: Makefile,v 1.1 2017/02/17 15:39:38 fhajny Exp $

DISTNAME=		pup-0.4.0
CATEGORIES=		www
MASTER_SITES=		${MASTER_SITE_GITHUB:=ericchiang/}
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		filip@joyent.com
HOMEPAGE=		https://github.com/ericchiang/pup/
COMMENT=		Parsing HTML at the command line
LICENSE=		mit

WRKSRC=			${WRKDIR}/src/github.com/ericchiang/pup

.include "../../lang/go/version.mk"

BUILD_DEPENDS+=		go-${GO_VERSION}*:../../lang/go

MAKE_ENV+=		GOPATH=${WRKDIR}:${PREFIX}/gopkg
INSTALLATION_DIRS+=	bin

post-extract:
	${MKDIR} ${WRKSRC}
	${MV} ${WRKDIR}/${DISTNAME}/* ${WRKSRC}

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} go build -o bin/pup

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/pup ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
