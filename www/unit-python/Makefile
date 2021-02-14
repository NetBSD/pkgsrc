# $NetBSD: Makefile,v 1.1 2021/02/14 11:56:58 otis Exp $

PKGNAME=	unit-${LANG}-${UNIT_VERSION}
COMMENT=	Python module for NGINX Unit

LANG=		python
MODNAME=	${LANG}

MAINTAINER=	osa@FreeBSD.org

post-configure:
	${RUN} cd ${WRKSRC} && ${SETENV} ${_CONFIGURE_SCRIPT_ENV}		\
		${CONFIG_SHELL} ${CONFIG_SHELL_FLAGS} ${CONFIGURE_SCRIPT}	\
			${LANG} --module=${MODNAME}				\
				--config=${LANG}${PYVERSSUFFIX}-config

.include "../../lang/${LANG}/application.mk"
.include "../../wip/unit/ext.mk"
.include "../../wip/unit/Makefile.common"
.include "../../mk/bsd.pkg.mk"
