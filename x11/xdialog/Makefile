# $NetBSD: Makefile,v 1.20 2008/08/29 16:43:58 sborrill Exp $
#

DISTNAME=		Xdialog-2.3.1
PKGNAME=		${DISTNAME:S/^X/x/}
CATEGORIES=		x11 misc
MASTER_SITES=		http://xdialog.free.fr/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://xdialog.dyns.net/
COMMENT=		X11 drop-in replacement for the curses dialog program

USE_TOOLS+=		msgfmt
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES

DOCDIR=			${PREFIX}/share/doc/html/xdialog
EGDIR=			${PREFIX}/share/examples/xdialog

CHECK_PORTABILITY_SKIP+=	samples/*

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	cd ${WRKSRC}/doc && ${INSTALL_DATA} *.html *.png ${DOCDIR}
	${INSTALL_DATA_DIR} ${EGDIR}
	for f in Xmessage Xmore buildlist calendar chain checklist	\
		dselect editbox fselect gauge infobox infobox2 inputbox	\
		logbox logbox2 login menubox msgbox radiolist rangebox	\
		tailbox textbox timebox treeview yesno;			\
	do								\
		${INSTALL_SCRIPT} ${WRKSRC}/samples/$${f} ${EGDIR};	\
	done

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
