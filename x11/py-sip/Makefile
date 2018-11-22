# $NetBSD: Makefile,v 1.56 2018/11/22 02:25:11 markd Exp $

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
COMMENT=	Tool to create Python bindings for C++ libraries

.include "../../x11/py-sip/Makefile.common"

do-configure:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${PYTHONBIN} configure.py ${CONFIGURE_ARGS}

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
