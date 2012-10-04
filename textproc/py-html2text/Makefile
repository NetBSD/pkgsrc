# $NetBSD: Makefile,v 1.24 2012/10/04 00:21:59 cheusov Exp $
#

DISTNAME=		aaronsw-${GHNAME}-${GHVERSION}-0-g${GHCOMMIT}
PKGREVISION=		1
GHNAME=			html2text
GHVERSION=		3.02
GHCOMMIT=		d9bf7d6
PKGNAME=		${PYPKGPREFIX}-${GHNAME}-${GHVERSION}
CATEGORIES=		textproc python
MASTER_SITES=		https://github.com/aaronsw/html2text/tarball/${GHVERSION}/

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://www.aaronsw.com/2002/html2text/
COMMENT=		Convert HTML into easy-to-read plain ASCII text
LICENSE=		gnu-gpl-v2

FETCH_USING=		curl

PKG_DESTDIR_SUPPORT=	user-destdir

PYTHON_VERSIONS_INCLUDE_3X=	yes
PYTHON_SELF_CONFLICT=		yes

WRKSRC=			${WRKDIR}/aaronsw-${GHNAME}-${GHCOMMIT}

NO_BUILD=		yes

REPLACE_PYTHON=		html2text.py

INSTALLATION_DIRS=	share/html2text

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/html2text.py ${DESTDIR}${PREFIX}/share/html2text

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
