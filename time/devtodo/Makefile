# $NetBSD: Makefile,v 1.11 2003/06/02 01:16:21 jschauma Exp $
#

DISTNAME=	devtodo-0.1.6-1
PKGNAME=	devtodo-0.1.6.1
WRKSRC=		${WRKDIR}/${DISTNAME:S/-1//}
CATEGORIES=	time
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=devtodo/}

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://sourceforge.net/projects/devtodo/
COMMENT=	Display and manage a list of items that are outstanding

USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

USE_BUILDLINK2=		# defined
GNU_CONFIGURE=		# defined

# We don't need curses, just termcap.
CONFIGURE_ENV+=		ac_cv_lib_curses_tputs=no

USE_GNU_READLINE=	# uses rl_startup_hook()

.include "../../devel/readline/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
