# $NetBSD: Makefile,v 1.10 2026/01/22 07:46:06 wiz Exp $

PKGNAME=	unit-${LANG}${RUBY_VER}-${UNIT_VERSION}
COMMENT=	Ruby module for NGINX Unit

LANG=		ruby
MODNAME=	${LANG}${RUBY_VER}

MAINTAINER=	pkgsrc-users@NetBSD.org

post-configure:
	${RUN} cd ${WRKSRC} && ${SETENV} ${_CONFIGURE_SCRIPT_ENV}	\
		${CONFIG_SHELL} ${CONFIG_SHELL_FLAGS} 			\
			${CONFIGURE_SCRIPT} ${LANG} --module=${MODNAME}

# only recognizes ruby 3.2
# ruby 3.4: error: 'rb_data_object_get_warning' is deprecated
RUBY_VERSIONS_ACCEPTED=		32

.include "../../lang/${LANG}/buildlink3.mk"
.include "../../www/unit/ext.mk"
.include "../../www/unit/Makefile.common"
.include "../../mk/bsd.pkg.mk"
