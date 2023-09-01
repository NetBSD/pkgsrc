# $NetBSD: Makefile,v 1.6 2023/09/01 17:28:29 osa Exp $

PKGNAME=	unit-${LANG}${RUBY_VER}-${UNIT_VERSION}
COMMENT=	Ruby module for NGINX Unit

LANG=		ruby
MODNAME=	${LANG}${RUBY_VER}

MAINTAINER=	osa@NetBSD.org

post-configure:
	${RUN} cd ${WRKSRC} && ${SETENV} ${_CONFIGURE_SCRIPT_ENV}	\
		${CONFIG_SHELL} ${CONFIG_SHELL_FLAGS} 			\
			${CONFIGURE_SCRIPT} ${LANG} --module=${MODNAME}

.include "../../lang/${LANG}/buildlink3.mk"
.include "../../www/unit/ext.mk"
.include "../../www/unit/Makefile.common"
.include "../../mk/bsd.pkg.mk"
