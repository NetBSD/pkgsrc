# $NetBSD: Makefile,v 1.4 2005/01/23 20:41:49 recht Exp $
#

DISTNAME=		Reverend-0.2.4
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		textproc python
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=reverend/}

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://www.divmod.org/Reverend/
COMMENT=		General purpose Bayesian classifier

NO_BUILDLINK=		yes
NO_CONFIGURE=		yes
USE_LANGUAGES=		# empty

PYDISTUTILSPKG=			yes
PYTHON_VERSIONS_ACCEPTED=	23

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
