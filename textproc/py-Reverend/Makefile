# $NetBSD: Makefile,v 1.9 2006/10/04 22:01:00 wiz Exp $
#

DISTNAME=		Reverend-0.2.4
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=		2
CATEGORIES=		textproc python
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=reverend/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://divmod.org/svn/Divmod/trunk/Reverend/
COMMENT=		General purpose Bayesian classifier

NO_CONFIGURE=		yes
USE_LANGUAGES=		# empty

PYDISTUTILSPKG=			yes
PYTHON_VERSIONS_ACCEPTED=	23

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
