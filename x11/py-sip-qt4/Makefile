# $NetBSD: Makefile,v 1.1 2020/07/10 20:02:23 rhialto Exp $

PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/sip/sip-qt4/}
COMMENT=	SIP bindings for C and C++ libraries (PyQt4 version)

.include "../../x11/py-sip/Makefile.common"

do-configure:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${PYTHONBIN} configure.py ${CONFIGURE_ARGS} --sip-module PyQt4.sip --no-tools

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
