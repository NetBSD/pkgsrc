# $NetBSD: Makefile,v 1.7 2025/02/15 15:58:22 wiz Exp $

PKGNAME=	unit-${LANG}${RUBY_VER}-${UNIT_VERSION}
COMMENT=	Ruby module for NGINX Unit

LANG=		ruby
MODNAME=	${LANG}${RUBY_VER}

MAINTAINER=	osa@NetBSD.org

post-configure:
	${RUN} cd ${WRKSRC} && ${SETENV} ${_CONFIGURE_SCRIPT_ENV}	\
		${CONFIG_SHELL} ${CONFIG_SHELL_FLAGS} 			\
			${CONFIGURE_SCRIPT} ${LANG} --module=${MODNAME}

# ruby 3.4: error: 'rb_data_object_get_warning' is deprecated
RUBY_VERSIONS_ACCEPTED=		32 31 33

.include "../../lang/${LANG}/buildlink3.mk"
.include "../../www/unit/ext.mk"
.include "../../www/unit/Makefile.common"
.include "../../mk/bsd.pkg.mk"
