# $NetBSD: Makefile,v 1.1 2023/03/30 19:12:12 he Exp $

DISTNAME=	ntc_templates-1.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/ntc_templates/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/networktocode/ntc-templates
COMMENT=	Repository of TextFSM Templates for Network Devices
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-textfsm>=1.1.0:../../textproc/py-textfsm

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
