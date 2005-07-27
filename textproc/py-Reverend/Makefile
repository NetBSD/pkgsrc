# $NetBSD: Makefile,v 1.6 2005/07/27 16:21:17 wiz Exp $
#

DISTNAME=		Reverend-0.2.4
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		textproc python
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=reverend/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.divmod.org/Reverend/
COMMENT=		General purpose Bayesian classifier

NO_CONFIGURE=		yes
USE_LANGUAGES=		# empty

PYDISTUTILSPKG=			yes
PYTHON_VERSIONS_ACCEPTED=	23

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
