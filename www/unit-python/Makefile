# $NetBSD: Makefile,v 1.10 2023/09/01 17:28:29 osa Exp $

PKGNAME=	unit-${LANG}${PYVERSSUFFIX}-${UNIT_VERSION}
COMMENT=	Python module for NGINX Unit

LANG=		python
MODNAME=	${LANG}${PYVERSSUFFIX}

MAINTAINER=	osa@NetBSD.org

post-configure:
	${RUN} cd ${WRKSRC} && ${SETENV} ${_CONFIGURE_SCRIPT_ENV}		\
		${CONFIG_SHELL} ${CONFIG_SHELL_FLAGS} ${CONFIGURE_SCRIPT}	\
			${LANG} --module=${MODNAME}				\
				--config=${LANG}${PYVERSSUFFIX}-config

.include "../../lang/${LANG}/application.mk"
.include "../../www/unit/ext.mk"
.include "../../www/unit/Makefile.common"
.include "../../mk/bsd.pkg.mk"
