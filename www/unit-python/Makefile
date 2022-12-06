# $NetBSD: Makefile,v 1.6 2022/12/06 08:54:23 wiz Exp $

PKGNAME=	unit-${LANG}${PYVERSSUFFIX}-${UNIT_VERSION}
PKGREVISION=	1
COMMENT=	Python module for NGINX Unit

LANG=		python
MODNAME=	${LANG}

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
