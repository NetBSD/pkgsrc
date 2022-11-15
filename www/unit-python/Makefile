# $NetBSD: Makefile,v 1.5 2022/11/15 12:47:59 wiz Exp $

PKGNAME=	unit-${LANG}${PYVERSSUFFIX}-${UNIT_VERSION}
COMMENT=	Python module for NGINX Unit

LANG=		python
MODNAME=	${LANG}

MAINTAINER=	osa@NetBSD.org

# https://github.com/nginx/unit/issues/710
PYTHON_VERSIONS_INCOMPATIBLE=	311

post-configure:
	${RUN} cd ${WRKSRC} && ${SETENV} ${_CONFIGURE_SCRIPT_ENV}		\
		${CONFIG_SHELL} ${CONFIG_SHELL_FLAGS} ${CONFIGURE_SCRIPT}	\
			${LANG} --module=${MODNAME}				\
				--config=${LANG}${PYVERSSUFFIX}-config

.include "../../lang/${LANG}/application.mk"
.include "../../www/unit/ext.mk"
.include "../../www/unit/Makefile.common"
.include "../../mk/bsd.pkg.mk"
