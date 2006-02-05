# $NetBSD: Makefile,v 1.7 2006/02/05 23:11:06 joerg Exp $
#

DISTNAME=		SimpleParse-2.0.0
PKGNAME=     		${PYPKGPREFIX}-SimpleParse-2.0.0
PKGREVISION=		2
CATEGORIES=		textproc python
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=simpleparse/}
EXTRACT_SUFX= 		.zip

MAINTAINER=		adam@monkeybyte.org
HOMEPAGE=		http://simpleparse.sourceforge.net/
COMMENT=		Simple parser generator for mxTextTools text-tagging engine

PYDISTUTILSPKG=		yes
PYTHON_VERSIONS_ACCEPTED=	23 22

.include "../../lang/python/extension.mk"
.include "../../time/py-mxDateTime/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
