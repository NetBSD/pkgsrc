# $NetBSD: Makefile,v 1.3 2004/07/22 09:16:02 recht Exp $
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
PYTHON_VERSIONS_ACCEPTED=	23 23pth

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
