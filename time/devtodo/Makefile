# $NetBSD: Makefile,v 1.14 2003/12/05 18:56:36 kristerw Exp $
#

DISTNAME=	devtodo-0.1.7
CATEGORIES=	time
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=devtodo/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/devtodo/
COMMENT=	Display and manage a list of items that are outstanding

USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

USE_BUILDLINK2=		# defined
GNU_CONFIGURE=		# defined
CONFIG_GUESS_OVERRIDE=	${WRKSRC}/config.guess
CONFIG_SUB_OVERRIDE=	${WRKSRC}/config.sub

# We don't need curses, just termcap.
CONFIGURE_ENV+=		ac_cv_lib_curses_tputs=no

USE_GNU_READLINE=	# uses rl_startup_hook()

CONTRIBFILES=	changelog2todo todo-html.xslt xslt-example.1 \
		xslt-example.1.README xslt-example.1.sh xslt-example.2

post-install:
.for CFILE in ${CONTRIBFILES}
	${INSTALL_DATA} ${WRKSRC}/contrib/${CFILE} ${PREFIX}/share/examples/devtodo
.endfor

.include "../../devel/readline/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
