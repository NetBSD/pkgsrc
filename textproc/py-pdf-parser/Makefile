# $NetBSD: Makefile,v 1.6 2012/10/25 06:56:51 asau Exp $
#

DISTNAME=	pdf-parser_V0_3_9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_V/-/:S/_/./g}
CATEGORIES=	textproc
MASTER_SITES=	http://www.didierstevens.com/files/software/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://blog.didierstevens.com/programs/pdf-tools/
COMMENT=	Parse PDF document to identify the fundamental elements
LICENSE=	public-domain

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# none

REPLACE_PYTHON=	pdf-parser.py

INSTALLATION_DIRS=	bin

PYTHON_SELF_CONFLICT=	yes

do-build:

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pdf-parser.py ${DESTDIR}${PREFIX}/bin

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
