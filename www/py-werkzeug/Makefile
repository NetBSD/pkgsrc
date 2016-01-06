# $NetBSD: Makefile,v 1.11 2016/01/06 17:28:31 kleink Exp $

PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}

COMMENT=	Python WSGI Utility Library

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
REPLACE_PYTHON+=	tests/multipart/test_collect.py

DOCFILES=	AUTHORS CHANGES

EGDIR=		share/examples/${PKGBASE}

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
.for i in manage-coolmagic.py manage-couchy.py manage-cupoftee.py \
    manage-i18nurls.py manage-plnt.py manage-shorty.py manage-simplewiki.py \
    manage-webpylike.py
	${CHMOD} ${SHAREMODE} \
	    ${DESTDIR}${PREFIX}/${EGDIR}/${i}
.endfor
.for i in down.png up.png
	${CHMOD} ${SHAREMODE} \
	    ${DESTDIR}${PREFIX}/${EGDIR}/cupoftee/shared/${i}
.endfor

.include "../../www/py-werkzeug/Makefile.common"

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
