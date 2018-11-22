# $NetBSD: Makefile,v 1.1 2018/11/22 02:30:53 markd Exp $

PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/sip/sip-qt5/}
COMMENT=	SIP bindings for C and C++ libraries (PyQt5 version)

.include "../../x11/py-sip/Makefile.common"

do-configure:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${PYTHONBIN} configure.py ${CONFIGURE_ARGS}  --sip-module PyQt5.sip --no-tools

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
