# $NetBSD: Makefile,v 1.17 2004/02/14 00:54:46 grant Exp $
#

DISTNAME=	devtodo-0.1.17
CATEGORIES=	time
#MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=devtodo/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://devtodo.sourceforge.net/
COMMENT=	Display and manage a list of items that are outstanding

USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

USE_BUILDLINK2=		# defined
GNU_CONFIGURE=		# defined

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

.include "../../devel/readline/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
