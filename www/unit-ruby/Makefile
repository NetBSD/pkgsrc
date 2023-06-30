# $NetBSD: Makefile,v 1.5 2023/06/30 20:49:44 osa Exp $

PKGNAME=	unit-${LANG}${RUBY_VER}-${UNIT_VERSION}
PKGREVISION=	1
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
