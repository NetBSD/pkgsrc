# $NetBSD: Makefile,v 1.8 2006/08/13 23:32:22 wiz Exp $
#

DISTNAME=		SimpleParse-2.0.0
PKGNAME=     		${PYPKGPREFIX}-SimpleParse-2.0.0
PKGREVISION=		2
CATEGORIES=		textproc python
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=simpleparse/}
EXTRACT_SUFX= 		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://simpleparse.sourceforge.net/
COMMENT=		Simple parser generator for mxTextTools text-tagging engine

PYDISTUTILSPKG=		yes
PYTHON_VERSIONS_ACCEPTED=	23 22

.include "../../lang/python/extension.mk"
.include "../../time/py-mxDateTime/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
