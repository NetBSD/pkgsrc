# $NetBSD: Makefile,v 1.9 2003/07/13 13:54:32 wiz Exp $
#

DISTNAME=		Xdialog-2.1.1
PKGNAME=		${DISTNAME:S/^X/x/}
PKGREVISION=		1
CATEGORIES=		x11 misc
MASTER_SITES=		http://thgodef.nerim.net/xdialog/	\
			http://thgodef.nerim.net/xdialog/archives/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://xdialog.dyns.net/
COMMENT=		X11 drop-in replacement for the curses dialog program

BUILD_USES_MSGFMT=	YES

USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES
USE_X11=		YES

DOCDIR=			${PREFIX}/share/doc/html/xdialog
EGDIR=			${PREFIX}/share/examples/xdialog

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

.include "../../x11/gtk/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
