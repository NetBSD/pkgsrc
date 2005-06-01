# $NetBSD: Makefile,v 1.23 2005/06/01 02:40:43 snj Exp $

DISTNAME=	devtodo-0.1.18
CATEGORIES=	time
MASTER_SITES=	http://swapoff.org/files/devtodo/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://swapoff.org/DevTodo
COMMENT=	Display and manage a list of items that are outstanding

USE_LIBTOOL=	YES

GNU_CONFIGURE=	YES

# We don't need curses, just termcap.
CONFIGURE_ENV+=		ac_cv_lib_curses_tputs=no

USE_GNU_READLINE=	# uses rl_startup_hook()

CONTRIBFILES=	changelog2html						\
		changelog2todo						\
		tdrec							\
		todo-nodone-html.xslt					\
		todo2html-2.xslt					\
		todo2html.xslt						\
		todo2pdf.README						\
		todo2pdf.sh						\
		todo2pdf.xslt

post-install:
.for CFILE in ${CONTRIBFILES}
	${INSTALL_DATA} ${WRKSRC}/contrib/${CFILE} 			\
		${PREFIX}/share/examples/devtodo
.endfor

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
