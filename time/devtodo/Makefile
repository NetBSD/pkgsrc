# $NetBSD: Makefile,v 1.32 2013/07/15 02:02:29 ryoon Exp $

DISTNAME=	devtodo-0.1.20
PKGREVISION=	3
CATEGORIES=	time
MASTER_SITES=	http://swapoff.org/files/devtodo/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://swapoff.org/DevTodo
COMMENT=	Display and manage a list of items that are outstanding

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

EGDIR=			${PREFIX}/share/examples/devtodo
INSTALL_MAKE_FLAGS+=	sysconfdir=${EGDIR}

post-install:
.for cfile in	changelog2html						\
		changelog2todo						\
		tdrec							\
		todo-nodone-html.xslt					\
		todo2html-2.xslt					\
		todo2html.xslt						\
		todo2pdf.README						\
		todo2pdf.sh						\
		todo2pdf.xslt
	${INSTALL_DATA} ${WRKSRC}/contrib/${cfile} ${DESTDIR}${EGDIR}
.endfor

# uses rl_startup_hook()
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
