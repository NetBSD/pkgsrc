# $NetBSD: Makefile,v 1.8 2001/06/11 02:05:15 jlam Exp $
#

DISTNAME=	devtodo-0.1.6-1
PKGNAME=	devtodo-0.1.6.1
WRKSRC=		${WRKDIR}/${DISTNAME:S/-1//}
CATEGORIES=	time
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=devtodo/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://sourceforge.net/projects/devtodo/
COMMENT=	Display and manage a list of items that are outstanding

USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

GNU_CONFIGURE=		# defined
CONFIGURE_ENV+=		ac_cv_lib_ncurses_tputs=no
CONFIGURE_ENV+=		ac_cv_lib_curses_tputs=no

USE_GNU_READLINE=	# uses rl_startup_hook()

.include "../../devel/readline/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
