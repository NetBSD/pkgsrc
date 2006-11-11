# $NetBSD: Makefile,v 1.19 2006/11/11 16:53:10 rillig Exp $
#

DISTNAME=		Xdialog-2.1.1
PKGNAME=		${DISTNAME:S/^X/x/}
PKGREVISION=		3
CATEGORIES=		x11 misc
MASTER_SITES=		http://thgodef.nerim.net/xdialog/	\
			http://thgodef.nerim.net/xdialog/archives/
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

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
