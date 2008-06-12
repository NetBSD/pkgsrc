# $NetBSD: Makefile,v 1.10 2008/06/12 02:14:52 joerg Exp $
#

DISTNAME=		Reverend-0.2.4
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=		2
CATEGORIES=		textproc python
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=reverend/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://divmod.org/svn/Divmod/trunk/Reverend/
COMMENT=		General purpose Bayesian classifier

PKG_DESTDIR_SUPPORT=	user-destdir

NO_CONFIGURE=		yes
USE_LANGUAGES=		# empty

PYDISTUTILSPKG=			yes
PYTHON_VERSIONS_ACCEPTED=	23

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
