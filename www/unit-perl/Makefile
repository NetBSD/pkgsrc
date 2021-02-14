# $NetBSD: Makefile,v 1.1 2021/02/14 11:56:57 otis Exp $

PKGNAME=	unit-${LANG}-${UNIT_VERSION}
COMMENT=	Perl module for NGINX Unit

LANG=		perl
MODNAME=	${LANG}

MAINTAINER=	osa@FreeBSD.org

USE_TOOLS+=	perl

post-configure:
	${RUN} cd ${WRKSRC} && ${PKGSRC_SETENV} ${_CONFIGURE_SCRIPT_ENV}	\
		${CONFIG_SHELL} ${CONFIG_SHELL_FLAGS} ${CONFIGURE_SCRIPT}	\
			${LANG} --module=${MODNAME}

.include "../../lang/perl5/buildlink3.mk"
.include "../../wip/unit/ext.mk"
.include "../../wip/unit/Makefile.common"
.include "../../mk/bsd.pkg.mk"
