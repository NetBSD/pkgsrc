# $NetBSD: Makefile,v 1.2 2013/01/16 23:12:06 kleink Exp $

DISTNAME=	Werkzeug-0.8.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	http://pypi.python.org/packages/source/W/Werkzeug/

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	http://werkzeug.pocoo.org/
COMMENT=	Python WSGI Utility Library
LICENSE=	modified-bsd

USE_LANGUAGES=	# empty
USE_TOOLS+=	pax

REPLACE_PYTHON=		examples/cookieauth.py
REPLACE_PYTHON+=	examples/manage-coolmagic.py
REPLACE_PYTHON+=	examples/manage-couchy.py
REPLACE_PYTHON+=	examples/manage-cupoftee.py
REPLACE_PYTHON+=	examples/manage-i18nurls.py
REPLACE_PYTHON+=	examples/manage-plnt.py
REPLACE_PYTHON+=	examples/manage-shorty.py
REPLACE_PYTHON+=	examples/manage-simplewiki.py
REPLACE_PYTHON+=	examples/manage-webpylike.py
REPLACE_PYTHON+=	examples/upload.py
REPLACE_PYTHON+=	examples/contrib/sessions.py
REPLACE_PYTHON+=	werkzeug/testsuite/multipart/collect.py

DOCDIR=		share/doc/${PKGBASE}
DOCFILES=	AUTHORS CHANGES

EGDIR=		share/examples/${PKGBASE}

PLIST_SUBST+=	DOCDIR=${DOCDIR}
PLIST_SUBST+=	EGDIR=${EGDIR}

INSTALLATION_DIRS+=	${DOCDIR}
INSTALLATION_DIRS+=	${EGDIR}

post-install:
.for i in console.png less.png more.png source.png
	${CHMOD} ${SHAREMODE} \
	    ${DESTDIR}${PREFIX}/${PYSITELIB}/werkzeug/debug/shared/${i}
.endfor
.for i in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DESTDIR}${PREFIX}/${DOCDIR}
.endfor
	cd ${WRKSRC}/examples && pax -rwppm . ${DESTDIR}${PREFIX}/${EGDIR}
.for i in down.png up.png
	${CHMOD} ${SHAREMODE} \
	    ${DESTDIR}${PREFIX}/${EGDIR}/cupoftee/shared/${i}
.endfor

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
