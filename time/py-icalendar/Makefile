# $NetBSD: Makefile,v 1.1.1.1 2009/05/19 09:19:45 wiz Exp $
#

DISTNAME=	iCalendar-1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/Calendar/calendar/}
CATEGORIES=	time python
MASTER_SITES=	http://codespeak.net/icalendar/
EXTRACT_SUFX=	.tgz

MAINTAINER=	mj@turner.org.za
HOMEPAGE=	http://codespeak.net/icalendar/
COMMENT=	Python parser/generator for iCalendar files, as per RFC2445
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

PY_PATCHPLIST=	yes
EGG_NAME=	${DISTNAME:S/C/c/}

DOCDIR=	${PREFIX}/share/doc/${PKGNAME}

INSTALLATION_DIRS=	${DOCDIR}

# Install documentation manually
post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DESTDIR}${DOCDIR}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
