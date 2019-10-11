# $NetBSD: Makefile,v 1.16 2019/10/11 16:29:17 adam Exp $

PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}

COMMENT=	Python WSGI Utility Library

TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner

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

PYSETUPTESTTARGET=	pytest

EGDIR=		share/examples/${PKGBASE}

PLIST_SUBST+=	EGDIR=${EGDIR}

INSTALLATION_DIRS+=	${EGDIR}

post-install:
.for i in console.png less.png more.png source.png
	${CHMOD} ${SHAREMODE} \
	    ${DESTDIR}${PREFIX}/${PYSITELIB}/werkzeug/debug/shared/${i}
.endfor
	cd ${WRKSRC}/examples && ${PAX} -rwppm . ${DESTDIR}${PREFIX}/${EGDIR}
.for i in manage-coolmagic.py manage-couchy.py manage-cupoftee.py \
    manage-i18nurls.py manage-plnt.py manage-shorty.py manage-simplewiki.py \
    manage-webpylike.py
	${CHMOD} ${SHAREMODE} ${DESTDIR}${PREFIX}/${EGDIR}/${i}
.endfor
.for i in down.png up.png
	${CHMOD} ${SHAREMODE} ${DESTDIR}${PREFIX}/${EGDIR}/cupoftee/shared/${i}
.endfor

.include "../../www/py-werkzeug/Makefile.common"

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
