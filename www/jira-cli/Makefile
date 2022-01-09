# $NetBSD: Makefile,v 1.4 2022/01/09 20:10:40 bsiegert Exp $

DISTNAME=	jira-cli-0.2.0
MASTER_SITES=	${MASTER_SITE_GITHUB:=ankitpokhrel/}
PKGREVISION=	2
CATEGORIES=	www
DIST_SUBDIR=	${PKGBASE}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	fox@NetBSD.org
HOMEPAGE=	https://github.com/ankitpokhrel/jira-cli
COMMENT=	Feature-rich Interactive Jira Command Line
LICENSE=	mit

GO_BUILD_DATE_cmd=	${DATE} "+%FT%T%Z"
GO_XFLAG_PREFIX=	-X github.com/ankitpokhrel/jira-cli/internal/version

GO_BUILD_PATTERN=	-ldflags ' \
			${GO_XFLAG_PREFIX}.BuildDate=${GO_BUILD_DATE_cmd:sh} \
			${GO_XFLAG_PREFIX}.Version=v${PKGVERSION_NOREV} \
			${GO_XFLAG_PREFIX}.GitCommit=${GITHUB_TAG} '
GO_BUILD_PATTERN+=	-mod=readonly ./cmd/jira

CHECK_RELRO_SKIP+=	bin/jira

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man7

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/jira ${DESTDIR}${PREFIX}/bin

post-install:
	${DESTDIR}${PREFIX}/bin/jira man -g -o ${DESTDIR}${PREFIX}/${PKGMANDIR}/man7

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
