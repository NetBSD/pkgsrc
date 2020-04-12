# $NetBSD: Makefile,v 1.2 2020/04/12 06:19:56 adam Exp $

PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/sip/sip-qt5/}
COMMENT=	SIP bindings for C and C++ libraries (PyQt5 version)

.include "../../x11/py-sip/Makefile.common"

do-configure:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${PYTHONBIN} configure.py ${CONFIGURE_ARGS} --sip-module PyQt5.sip --no-tools

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
