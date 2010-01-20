# $NetBSD: Makefile,v 1.3 2010/01/20 10:34:23 wiz Exp $
#

DISTNAME=	icalendar-2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	time python
MASTER_SITES=	http://pypi.python.org/packages/source/i/icalendar/

MAINTAINER=	mj@turner.org.za
HOMEPAGE=	http://codespeak.net/icalendar/
COMMENT=	Python parser/generator for iCalendar files, as per RFC2445
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

PY_PATCHPLIST=	yes
EGG_NAME=	${DISTNAME:S/C/c/}

DOCDIR=		${PREFIX}/share/doc/${PKGNAME}

INSTALLATION_DIRS=	${DOCDIR}

# Install documentation manually
post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DESTDIR}${DOCDIR}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
