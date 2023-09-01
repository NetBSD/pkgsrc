# $NetBSD: Makefile,v 1.9 2023/09/01 17:28:28 osa Exp $

PKGNAME=	unit-${LANG}-${UNIT_VERSION}
COMMENT=	Perl module for NGINX Unit

LANG=		perl
MODNAME=	${LANG}

MAINTAINER=	osa@NetBSD.org

USE_TOOLS+=	perl

post-configure:
	${RUN} cd ${WRKSRC} && ${PKGSRC_SETENV} ${_CONFIGURE_SCRIPT_ENV}	\
		${CONFIG_SHELL} ${CONFIG_SHELL_FLAGS} ${CONFIGURE_SCRIPT}	\
			${LANG} --module=${MODNAME}

.include "../../lang/perl5/buildlink3.mk"
.include "../../www/unit/ext.mk"
.include "../../www/unit/Makefile.common"
.include "../../mk/bsd.pkg.mk"
