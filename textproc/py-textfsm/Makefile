# $NetBSD: Makefile,v 1.1 2023/03/31 22:41:09 he Exp $

DISTNAME=	textfsm-1.1.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_GITHUB:=google/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/google/textfsm
COMMENT=	Template based state machine for parsing semi-formatted text
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-future-[0-9]*:../../devel/py-future

GITHUB_PROJECT=	textfsm
GITHUB_TAG=	v${PKGVERSION_NOREV}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
